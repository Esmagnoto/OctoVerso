
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "Paquet.h"
#include "Rail.h"
#include "Joueur.h"
#pragma warning (disable : 4996)


int main() {
	Paquet p;

	assert(initPaquet(&p, NBCHEVALETS) == 1);
	assert(remplir(&p) == 1);
	melanger(&p);
	printf("Le paquet est : \n");
	afficher(&p);
	Item piocher = pioche(&p);
	printf("Le chevalet pioche est : %c\n", toupper(piocher));
	printf("Le paquet est : \n");
	afficher(&p);
	detruirePaquet(&p);

}