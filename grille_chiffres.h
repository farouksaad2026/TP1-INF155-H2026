#ifndef GRILLE_CHIFFRES_H
#define GRILLE_CHIFFRES_H

#define NB_COL 10
#define MAX_LIG 20
#define POS_NB 0

typedef int t_grille_nos[MAX_LIG][NB_COL];
typedef int t_tab_chiffres[NB_COL];

#define INC_POS(lig, col) { col++; if (col >= NB_COL) { col = 1; lig++; } }

int init_grille(t_grille_nos grille, t_tab_chiffres nbr_chiffres);
void retirer_ligne(t_grille_nos grille, int no_lig, int *derniere_lig);
void effacer_chiffre(t_grille_nos grille, int pos);
int retirer_chiffre(t_tab_chiffres nbr_chiffres, int ch);
int get_chiffre_case(t_grille_nos grille, int pos);
int nb_chiffres_restants(t_tab_chiffres nbr_chiffres);
void ajouter_chiffres(t_grille_nos grille, t_tab_chiffres nbr_chiffres, int *derniere_lig);

#endif
