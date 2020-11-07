#include "ecosys.h"

float p_ch_dir = 0.5;
int gain_energie_proie = 6;
int gain_energie_predateur = 20;
float p_reproduce_proie = 0.5;
float p_reproduce_predateur = 0.4;
int temps_repousse_herbe = -15;

Animal * creer_animal(int x, int y, float energie) {
  Animal * na = malloc(sizeof(Animal));
  assert(na);
  na -> x = x;
  na -> y = y;
  na -> energie = energie;
  na -> dir[0] = rand() % 3 -1;
  na -> dir[1] = rand() % 3 -1;
  na -> suivant = NULL;
  return na;
}
Animal * ajouter_en_tete_animal(Animal * liste, Animal * animal) {
  assert(animal);
  assert(!animal -> suivant);
  animal -> suivant = liste;
  return animal;
}
unsigned int compte_animal_it(Animal * la) {
  unsigned int i = 0;
  while (la) {
    i++;
    la = la -> suivant;
  }
  return i;
}

void affichage(Animal * liste_proie, Animal * liste_predateur) {
  char ecosys[SIZEX][SIZEY];
  unsigned int i, j;
  int nbpred = 0, nbproie = 0;
  Animal * pa;

  /* on initialise le tableau */
  for (i = 0; i < SIZEX; i++) {
    for (j = 0; j < SIZEY; j++) {
      ecosys[i][j] = ' ';
    }
  }
  pa = liste_proie;
  while (pa) {
    nbproie++;
    assert(pa -> x >= 0 && pa -> x < SIZEX && pa -> y >= 0 && pa -> y < SIZEY);
    ecosys[pa -> x][pa -> y] = '*';
    printf("x: %d y: %d\n", pa->x, pa->y);
    pa = pa -> suivant;
  }
  pa = liste_predateur;
  while (pa) {
    nbpred++;
    assert(pa -> x >= 0 && pa -> x < SIZEX && pa -> y >= 0 && pa -> y < SIZEY);
    if (ecosys[pa -> x][pa -> y] == '*')
      ecosys[pa -> x][pa -> y] = '@';
    if (ecosys[pa -> x][pa -> y] == ' ')
      ecosys[pa -> x][pa -> y] = 'O';
    printf("x: %d y: %d\n", pa->x, pa->y);
    pa = pa -> suivant;
  }
  /* on affiche le tableau */
  printf("+");
  for (j = 0; j < SIZEY; j++) {
    printf("-");
  }
  printf("+\n");
  for (i = 0; i < SIZEX; i++) {
    printf("|");
    for (j = 0; j < SIZEY; j++) {
      putchar(ecosys[i][j]);
    }
    printf("|\n");
  }
  printf("+");
  for (j = 0; j < SIZEY; j++) {
    printf("-");
  }
  printf("+\n");
  printf("Nb proies : %d\t Nb predateurs : %d\n", nbproie, nbpred);

}
void ajouter_animal(int x, int y, Animal ** liste_animal) {
  Animal * nouvel = creer_animal(x, y, rand() % 100);
  assert(x < SIZEX && y < SIZEY);
  nouvel -> suivant = * liste_animal;
  * liste_animal = nouvel;
  nouvel = NULL;
}
void liberer_liste_animaux(Animal * liste) {
  int i;
  Animal * tmp;
  for (i = 0; liste != NULL; i++) {
    tmp = liste;
    free(tmp);
    liste = liste -> suivant;
  }
  tmp = NULL;
  printf("animaux libérés : %d", i);
}
void enlever_animal(Animal ** Liste, Animal * animal) {
  Animal * iterate;
  iterate = * Liste;
  while (iterate != animal || NULL) {
    iterate = iterate -> suivant;
  }
  free(iterate);
  iterate = NULL;
  animal = NULL;
  assert(animal == NULL);

}
void bouger_animaux(Animal * la) {
  int indicex;
  int indicey;
  if (la -> dir[0] != 0 && la -> dir[1] != 0) {
    while (la) {
			if (((rand() % 1000) / 1000.0) <= p_ch_dir){
		  	la->dir[0] = rand() % 3 -1;
		  	la->dir[1] = rand() % 3 -1;
		  }
      if (la -> dir[0] == -1)
        indicex = SIZEX - 1;
      if (la -> dir[0] == 1)
        indicex = 0;
      if (la -> dir[1] == -1)
        indicey = SIZEY - 1;
      if (la -> dir[1] == 1)
        indicey = 0;
      if (indicex < la -> x) {
        if (abs(indicex - la -> x) < (SIZEX - 1) / 2)
          la -> x--;
        if (abs(indicex - la -> x) > (SIZEX - 1) / 2)
          la -> x++;
      }
      if (indicex > la -> x) {
        if (abs(indicex - la -> x) < (SIZEX - 1) / 2)
          la -> x++;
        if (abs(indicex - la -> x) > (SIZEX - 1) / 2)
          la -> x--;

      }
      if (indicey < la -> y) {
        if (abs(indicey - la -> y) < (SIZEY - 1) / 2)
          la -> y--;
        if (abs(indicey - la -> y) > (SIZEY - 1) / 2)
          la -> y++;
      }
      if (indicey > la -> y) {
        if (abs(indicey - la -> y) < (SIZEY - 1) / 2)
          la -> y++;
        if (abs(indicey - la -> y) > (SIZEY - 1) / 2)
          la -> y--;
      }
      if (la -> x == -1)
        la -> x = SIZEX - 1;
      if (la -> x == SIZEX)
        la -> x = 0;
      if (la -> y == -1)
        la -> y = SIZEY - 1;
      if (la -> y == SIZEY)
        la -> y = 0;
      assert(la -> x <= SIZEX - 1);
      assert(la -> x >= 0);
      assert(la -> y <= SIZEY - 1);
      assert(la -> y >= 0);
      la = la -> suivant;
    }
  }
}
void reproduce(Animal **liste_animal, float p_reproduce){
	float i;
	Animal *ani = *liste_animal;
	Animal *nouv;
	while (ani){
		i = (rand() % 1000) / 1000.0;
		if (i <= p_reproduce){
			ani->energie = ani->energie/2;
			nouv = creer_animal(ani->x, ani->y, ani->energie);
			nouv->suivant = *liste_animal;
			*liste_animal = nouv;
		}
		ani = ani->suivant;
	}
	nouv = NULL;
}
