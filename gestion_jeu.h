#ifndef GESTION_JEU_H
#define GESTION_JEU_H

#include "grille_chiffres.h"
#include "liste_couples.h"

#define CODE_CHIFFRES -2
#define CODE_AIDE -1
#define CODE_QUITTER 0

#define PTS_COUPLE_VOISIN 1
#define PTS_COUPLE_SEPARE 4
#define PTS_LIGNE_RETIREE 10

int valider_coup(t_liste_couples liste, int derniere_lig, int *caseA, int *caseB);
int jouer_coup(t_grille_nos grille, int caseA, int caseB, t_tab_chiffres nbr_chiffres, int *derniere_lig);

#endif
