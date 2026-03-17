#include "utilitaires.h"
#include <stdlib.h>
#include <time.h>

void init_rand(void) {
    srand((unsigned int)time(NULL));
}

int entier_aleatoire(int min, int max) {
    return min + rand() % (max - min + 1);
}

double reel_aleatoire(double min, double max) {
    double scale = rand() / (double)RAND_MAX;
    return min + scale * (max - min);
}
