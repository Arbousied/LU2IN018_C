#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAILLE 10

void min_max_moy(int *tab, int *max, int *min, float *moy, int taille){
    for(int i = 0; i < taille; i++){
        *moy += *(tab + i);
        if (*(tab + i) > *max)
            *max = *(tab + i);
        if (*(tab + i) < *min)
            *min = *(tab + i);
    }
    *moy /= taille;
}

int main(){
    int max,min,*tab;
    max = 0;
    min = 0;
    float moy;
    moy = 0.0;
    tab = malloc(sizeof(int) * TAILLE);
    for(int i =0; i < TAILLE; i++){
        *(tab + i) = (rand() % 50 - 20);
    }
    min_max_moy(tab, &max, &min, &moy, TAILLE);
    printf("%d\n%d\n%f\n", max, min, moy);
    free(tab);
    return 0;
}
