#include "grille_chiffres.h"
#include "utilitaires.h"
#include <stdio.h>

static int verifier_ch_voisins(t_grille_nos grille, int lig, int col, int ch) {
    if (lig > 0 && grille[lig-1][col] == ch) return 0;
    if (col > 1 && grille[lig][col-1] == ch) return 0;
    return 1;
}

int init_grille(t_grille_nos grille, t_tab_chiffres nbr_chiffres) {
    int i, j;
    for(i=0; i<MAX_LIG; i++) for(j=0; j<NB_COL; j++) grille[i][j] = 0;
    for(i=0; i<NB_COL; i++) nbr_chiffres[i] = 0;

    double facteur = reel_aleatoire(4.0, 5.0);
    int nb_chiffres = (int)(facteur * 9);
    if (nb_chiffres % 2 != 0) nb_chiffres++;

    int lig = 0, col = 1;
    for(i=0; i<nb_chiffres; i++) {
        int ch;
        do {
            ch = entier_aleatoire(1, 9);
        } while (!verifier_ch_voisins(grille, lig, col, ch));
        
        grille[lig][col] = ch;
        grille[lig][POS_NB]++;
        nbr_chiffres[ch]++;
        INC_POS(lig, col);
    }
    
    int visibles = 0;
    for(i=1; i<=9; i++) if(nbr_chiffres[i] > 0) visibles++;
    nbr_chiffres[0] = visibles;

    return (col == 1) ? lig - 1 : lig;
}

void retirer_ligne(t_grille_nos grille, int no_lig, int *derniere_lig) {
    for(int i = no_lig; i < *derniere_lig; i++) {
        for(int j = 0; j < NB_COL; j++) {
            grille[i][j] = grille[i+1][j];
        }
    }
    for(int j = 0; j < NB_COL; j++) grille[*derniere_lig][j] = 0;
    (*derniere_lig)--;
}

void effacer_chiffre(t_grille_nos grille, int pos) {
    int lig = pos / 10;
    int col = pos % 10;
    grille[lig][col] = 0;
    grille[lig][POS_NB]--;
}

int retirer_chiffre(t_tab_chiffres nbr_chiffres, int ch) {
    if (nbr_chiffres[ch] > 0) {
        nbr_chiffres[ch]--;
        if (nbr_chiffres[ch] == 0) {
            nbr_chiffres[0]--;
            return ch;
        }
    }
    return 0;
}

int get_chiffre_case(t_grille_nos grille, int pos) {
    return grille[pos/10][pos%10];
}

int nb_chiffres_restants(t_tab_chiffres nbr_chiffres) {
    int total = 0;
    for(int i=1; i<=9; i++) total += nbr_chiffres[i];
    return total;
}

static void trouver_fin_chiffres(t_grille_nos grille, int *lig, int *col) {
    int l = *lig;
    int c = NB_COL - 1;
    while(c >= 1 && grille[l][c] == 0) c--;
    c++;
    if(c >= NB_COL) {
        c = 1;
        (*lig)++;
    }
    *col = c;
}

void ajouter_chiffres(t_grille_nos grille, t_tab_chiffres nbr_chiffres, int *derniere_lig) {
    int lig = *derniere_lig;
    int col;
    trouver_fin_chiffres(grille, &lig, &col);
    
    double facteur = reel_aleatoire(1.5, 5.0);
    int nb_a_ajouter = (int)(facteur * 9); // Simplifié
    if (nb_a_ajouter % 2 != 0) nb_a_ajouter++;
    
    int prev_ch = -1;
    for(int i=0; i<nb_a_ajouter && lig < MAX_LIG; i++) {
        int ch;
        do {
            ch = entier_aleatoire(1, 9);
        } while (ch == prev_ch);
        
        grille[lig][col] = ch;
        grille[lig][POS_NB]++;
        if(nbr_chiffres[ch] == 0) nbr_chiffres[0]++;
        nbr_chiffres[ch]++;
        prev_ch = ch;
        INC_POS(lig, col);
    }
    *derniere_lig = (col == 1) ? lig - 1 : lig;
}
