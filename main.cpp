#include "utilitaires.h"
#include "winconsole.h"
#include "grille_chiffres.h"
#include "liste_couples.h"
#include "affichages.h"
#include "gestion_jeu.h"
#include <stdio.h>

int main() {
    t_grille_nos grille;
    t_tab_chiffres nbr_chiffres;
    t_liste_couples liste;
    int score = 0;
    int derniere_lig;
    int caseA, caseB;
    int quitter = 0;
    int nb_regen = 3;

    init_rand();
    afficher_instructions();
    
    derniere_lig = init_grille(grille, nbr_chiffres);

    while (!quitter) {
        clrscr();
        afficher_infos_jeu(score, nbr_chiffres);
        afficher_grille(grille, derniere_lig);
        
        int nb_couples = generer_liste_couples(grille, derniere_lig, liste);
        
        if (nb_couples == 0 && nb_chiffres_restants(nbr_chiffres) > 0) {
            if (nb_regen > 0) {
                mess_erreur("Plus de coups! Regeneration...");
                ajouter_chiffres(grille, nbr_chiffres, &derniere_lig);
                nb_regen--;
                continue;
            } else {
                quitter = 1;
                continue;
            }
        }

        int res = valider_coup(liste, derniere_lig, &caseA, &caseB);
        
        if (res == CODE_QUITTER) {
            quitter = 1;
        } else if (res == CODE_AIDE) {
            int p1, p2;
            if (choix_couple_alea(liste, &p1, &p2)) {
                afficher_indice(p1, p2);
            }
        } else if (res == CODE_CHIFFRES) {
            if (nb_regen > 0) {
                ajouter_chiffres(grille, nbr_chiffres, &derniere_lig);
                nb_regen--;
            } else {
                mess_erreur("Plus de regenerations!");
            }
        } else {
            score += jouer_coup(grille, caseA, caseB, nbr_chiffres, &derniere_lig);
            if (nb_chiffres_restants(nbr_chiffres) == 0) {
                score += 140;
                quitter = 1;
            }
        }
    }

    afficher_fin_jeu(score);
    return 0;
}
