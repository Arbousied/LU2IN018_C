#include "ecosys.h"
int main() {
  int i;
  Animal * listeproie = creer_animal(rand() % SIZEX, rand() % SIZEY, rand() % 100);
  Animal * listepred = creer_animal(rand() % SIZEX, rand() % SIZEY, rand() % 100);
  for (i = 0; i < 10; i++) {
    Animal * nouveau = creer_animal(rand() % SIZEX, rand() % SIZEY, rand() % 100);
    if (i % 2 == 0) {
      nouveau -> suivant = listeproie -> suivant;
      listeproie -> suivant = nouveau;
    }
    else {
      nouveau -> suivant = listepred -> suivant;
      listepred -> suivant = nouveau;
    }
    reproduce(&listepred, p_reproduce_predateur);
    reproduce(&listeproie, p_reproduce_proie);
    bouger_animaux(listepred);
    bouger_animaux(listeproie);
    affichage(listeproie, listepred);
  }
  /*listeproie = creer_animal(rand() % 2 - 1, rand() % 2 - 1, rand() % 100);
  listepred = creer_animal(rand() % 2 - 1, rand() % 2 - 1, rand() % 100);
  for(i=0; i < 10; i++){
  	bouger_animaux(listepred);
  	bouger_animaux(listeproie);
  	affichage(listeproie, listepred);
  }*/
  liberer_liste_animaux(listepred);
  liberer_liste_animaux(listeproie);
  listepred = NULL;
  listeproie = NULL;
  return 0;
}
