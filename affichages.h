#ifndef AFFICHAGES_H
#define AFFICHAGES_H

#include "grille_chiffres.h"

#define COL_GRILLE 20
#define LIG_GRILLE 5
#define LIG_SAISIE 22
#define LIG_MESSAGES 24
#define LIG_POINTS 2
#define LIG_INFOS_CH 3

void afficher_infos_jeu(int score, t_tab_chiffres nbr_chiffres);
void afficher_grille(t_grille_nos grille, int derniere_lig);
void mess_erreur(const char *msg);
void mess_points(int pts);
void afficher_couple(int pos1, int pos2, int color);
void afficher_indice(int pos1, int pos2);
void afficher_instructions(void);
void afficher_fin_jeu(int score);
void demander_saisie(int num);

#endif
