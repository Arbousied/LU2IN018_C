#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#define SIZEX 30
#define SIZEY 30

extern float p_ch_dir;
extern int gain_energie_proie;
extern int gain_energie_predateur;
extern float p_reproduce_proie;
extern float p_reproduce_predateur;
extern int temps_repousse_herbe;

typedef struct animal{
        int x;
        int y;
        int dir[2];
        float energie;
        struct animal *suivant;
} Animal;

Animal *creer_animal(int x, int y, float energie);
Animal *ajouter_en_tete_animal(Animal *liste, Animal *animal);
unsigned int compte_animal_it(Animal *la);
void affichage(Animal *liste_proie, Animal *liste_predateur);
void ajouter_animal(int x, int y, Animal **liste_animal);
void liberer_liste_animaux(Animal *liste);
void enlever_animal(Animal **Liste, Animal *animal);
void bouger_animaux(Animal *la);
void reproduce(Animal **liste_animal, float p_reproduce);
