#ifndef LISTE_COUPLES_H
#define LISTE_COUPLES_H

#include "grille_chiffres.h"

#define MAX_COUPLES 200
#define LIG_INFOS 0
#define COL_TAILLE 0
#define COL_NBELEM 1

typedef int t_liste_couples[MAX_COUPLES + 1][2];

void init_liste_couples(t_liste_couples liste);
int ajouter_couple(t_liste_couples liste, int pos1, int pos2);
int generer_liste_couples(t_grille_nos grille, int derniere_lig, t_liste_couples liste);
void verifier_huit_directions(t_grille_nos grille, int lig, int col, t_liste_couples liste);
void verifier_sens_est(t_grille_nos grille, int lig, int col, t_liste_couples liste);
int choix_couple_alea(t_liste_couples liste, int *pos1, int *pos2);

#endif
