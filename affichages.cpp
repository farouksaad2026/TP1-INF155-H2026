#include "affichages.h"
#include "winconsole.h"
#include <stdio.h>

void afficher_infos_jeu(int score, t_tab_chiffres nbr_chiffres) {
    gotoxy(30, LIG_POINTS);
    textcolor(BLANC);
    printf("Score: %d", score);
    
    gotoxy(30, LIG_INFOS_CH);
    printf("Chiffres: ");
    for(int i=1; i<=9; i++) {
        if(nbr_chiffres[i] > 0) printf("%d ", i);
        else printf("  ");
    }
}

void afficher_grille(t_grille_nos grille, int derniere_lig) {
    gotoxy(COL_GRILLE, LIG_GRILLE - 1);
    textcolor(BLANC);
    printf("  A B C D E F G H I");
    
    for(int l = 0; l <= derniere_lig; l++) {
        gotoxy(COL_GRILLE, LIG_GRILLE + l);
        textcolor(JAUNE);
        printf("%d ", l + 1);
        textcolor(BLANC);
        for(int c = 1; c < NB_COL; c++) {
            if(grille[l][c] == 0) printf(". ");
            else printf("%d ", grille[l][c]);
        }
    }
}

void mess_erreur(const char *msg) {
    gotoxy(0, LIG_MESSAGES);
    textcolor(ROUGE);
    printf("%s", msg);
    clreol();
    delay(1500);
    gotoxy(0, LIG_MESSAGES);
    clreol();
}

void mess_points(int pts) {
    gotoxy(50, LIG_POINTS);
    textcolor(VERT);
    printf("+%d points!", pts);
    delay(1000);
    gotoxy(50, LIG_POINTS);
    clreol();
}

void afficher_couple(int pos1, int pos2, int color) {
    // Non implémenté car nécessite de connaître les chiffres
    // Mais on peut utiliser pour flasher
}

void afficher_indice(int pos1, int pos2) {
    int l1 = pos1 / 10, c1 = pos1 % 10;
    int l2 = pos2 / 10, c2 = pos2 % 10;
    char s1[5], s2[5];
    sprintf(s1, "%c%d", 'A' + c1 - 1, l1 + 1);
    sprintf(s2, "%c%d", 'A' + c2 - 1, l2 + 1);
    
    gotoxy(0, LIG_MESSAGES);
    textcolor(CYAN);
    printf("Indice: essayez %s et %s", s1, s2);
    delay(3000);
    gotoxy(0, LIG_MESSAGES);
    clreol();
}

void afficher_instructions(void) {
    clrscr();
    textcolor(JAUNE);
    printf("=== NUMBER MATCH ===\n\n");
    printf("Associez des chiffres identiques ou dont la somme est 10.\n");
    printf("Commandes:\n");
    printf("  XX : Quitter\n");
    printf("  ?? : Indice\n");
    printf("  ++ : Nouvelles lignes\n");
    printf("Appuyez sur Entree pour commencer...");
    while(getchar() != '\n');
    clrscr();
}

void afficher_fin_jeu(int score) {
    clrscr();
    gotoxy(30, 10);
    textcolor(JAUNE);
    printf("PARTIE TERMINEE");
    gotoxy(30, 11);
    printf("Score final: %d", score);
    gotoxy(30, 13);
    printf("Merci d'avoir joue!");
    delay(3000);
    clrscr();
}

void demander_saisie(int num) {
    gotoxy(0, LIG_SAISIE + num - 1);
    textcolor(BLANC);
    printf("Entrer la case %d (ex. A1): ", num);
    clreol();
}
