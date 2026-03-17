#include "gestion_jeu.h"
#include "affichages.h"
#include "winconsole.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define CHIFFRE_A_VAL(ch) (ch - '0')
#define LETTRE_A_COL(let) (toupper(let) - 'A' + 1)
#define COL_A_LETTRE(col) (col - 1 + 'A')

static int saisie_case(int derniere_lig, int num) {
    char buffer[10];
    int lig, col;
    
    while (1) {
        demander_saisie(num);
        if (scanf("%s", buffer) != 1) continue;
        
        if (strcmp(buffer, "XX") == 0 || strcmp(buffer, "xx") == 0) return CODE_QUITTER;
        if (strcmp(buffer, "??") == 0) return CODE_AIDE;
        if (strcmp(buffer, "++") == 0) return CODE_CHIFFRES;
        
        if (strlen(buffer) < 2 || strlen(buffer) > 3) {
            mess_erreur("Format invalide (ex: A1)");
            continue;
        }
        
        if (!isalpha(buffer[0])) {
            mess_erreur("La colonne doit etre une lettre (A-I)");
            continue;
        }
        
        col = LETTRE_A_COL(buffer[0]);
        if (col < 1 || col > 9) {
            mess_erreur("Lettre de colonne invalide (A-I)");
            continue;
        }
        
        lig = atoi(&buffer[1]) - 1;
        if (lig < 0 || lig > derniere_lig) {
            mess_erreur("Numero de ligne invalide");
            continue;
        }
        
        return lig * 10 + col;
    }
}

int valider_coup(t_liste_couples liste, int derniere_lig, int *caseA, int *caseB) {
    while (1) {
        *caseA = saisie_case(derniere_lig, 1);
        if (*caseA <= 0) return *caseA;
        
        *caseB = saisie_case(derniere_lig, 2);
        if (*caseB <= 0) return *caseB;
        
        int nb = liste[LIG_INFOS][COL_NBELEM];
        int trouve = 0;
        for (int i = 1; i <= nb; i++) {
            if ((liste[i][0] == *caseA && liste[i][1] == *caseB) ||
                (liste[i][0] == *caseB && liste[i][1] == *caseA)) {
                trouve = 1;
                break;
            }
        }
        
        if (trouve) return 1;
        mess_erreur("Coup non valide");
    }
}

int jouer_coup(t_grille_nos grille, int caseA, int caseB, t_tab_chiffres nbr_chiffres, int *derniere_lig) {
    int points = 0;
    int pts_lignes = 0;
    
    int lA = caseA / 10, cA = caseA % 10;
    int lB = caseB / 10, cB = caseB % 10;
    
    if (abs(lA - lB) <= 1 && abs(cA - cB) <= 1) {
        points = PTS_COUPLE_VOISIN;
    } else {
        points = PTS_COUPLE_SEPARE;
    }
    
    int chA = get_chiffre_case(grille, caseA);
    int chB = get_chiffre_case(grille, caseB);
    
    retirer_chiffre(nbr_chiffres, chA);
    retirer_chiffre(nbr_chiffres, chB);
    
    effacer_chiffre(grille, caseA);
    effacer_chiffre(grille, caseB);
    
    if (lA < lB) { int t = lA; lA = lB; lB = t; }
    
    if (grille[lA][POS_NB] == 0) {
        retirer_ligne(grille, lA, derniere_lig);
        pts_lignes += PTS_LIGNE_RETIREE;
    }
    
    if (lB != lA && grille[lB][POS_NB] == 0) {
        retirer_ligne(grille, lB, derniere_lig);
        pts_lignes += PTS_LIGNE_RETIREE;
    }
    
    return points + pts_lignes;
}
