#include "liste_couples.h"
#include "utilitaires.h"
#include <stdio.h>

void init_liste_couples(t_liste_couples liste) {
    liste[LIG_INFOS][COL_TAILLE] = MAX_COUPLES;
    liste[LIG_INFOS][COL_NBELEM] = 0;
}

int ajouter_couple(t_liste_couples liste, int pos1, int pos2) {
    int nb = liste[LIG_INFOS][COL_NBELEM];
    if (nb < MAX_COUPLES) {
        for(int i = 1; i <= nb; i++) {
            if ((liste[i][0] == pos1 && liste[i][1] == pos2) ||
                (liste[i][0] == pos2 && liste[i][1] == pos1)) {
                return 0;
            }
        }
        nb++;
        liste[nb][0] = pos1;
        liste[nb][1] = pos2;
        liste[LIG_INFOS][COL_NBELEM] = nb;
        return 1;
    }
    return 0;
}

static int est_valide(t_grille_nos grille, int p1, int p2) {
    int v1 = get_chiffre_case(grille, p1);
    int v2 = get_chiffre_case(grille, p2);
    return (v1 == v2 || v1 + v2 == 10);
}

void verifier_huit_directions(t_grille_nos grille, int lig, int col, t_liste_couples liste) {
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int p1 = lig * 10 + col;

    for (int i = 0; i < 8; i++) {
        int nl = lig + dx[i];
        int nc = col + dy[i];
        while (nl >= 0 && nl < MAX_LIG && nc >= 1 && nc < NB_COL) {
            if (grille[nl][nc] != 0) {
                if (est_valide(grille, p1, nl * 10 + nc)) {
                    ajouter_couple(liste, p1, nl * 10 + nc);
                }
                break;
            }
            nl += dx[i];
            nc += dy[i];
        }
    }
}

void verifier_sens_est(t_grille_nos grille, int lig, int col, t_liste_couples liste) {
    int p1 = lig * 10 + col;
    int nl = lig;
    int nc = col + 1;
    
    while (nl < MAX_LIG) {
        if (nc >= NB_COL) {
            nc = 1;
            nl++;
            if (nl >= MAX_LIG) break;
            continue;
        }
        if (grille[nl][nc] != 0) {
            if (est_valide(grille, p1, nl * 10 + nc)) {
                ajouter_couple(liste, p1, nl * 10 + nc);
            }
            break;
        }
        nc++;
    }
}

int generer_liste_couples(t_grille_nos grille, int derniere_lig, t_liste_couples liste) {
    init_liste_couples(liste);
    for (int l = 0; l <= derniere_lig; l++) {
        for (int c = 1; c < NB_COL; c++) {
            if (grille[l][c] != 0) {
                verifier_huit_directions(grille, l, c, liste);
                verifier_sens_est(grille, l, c, liste);
            }
        }
    }
    return liste[LIG_INFOS][COL_NBELEM];
}

int choix_couple_alea(t_liste_couples liste, int *pos1, int *pos2) {
    int nb = liste[LIG_INFOS][COL_NBELEM];
    if (nb > 0) {
        int idx = entier_aleatoire(1, nb);
        *pos1 = liste[idx][0];
        *pos2 = liste[idx][1];
        return 1;
    }
    return 0;
}
