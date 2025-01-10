#include "paquet.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#pragma warning (disable : 4996)

int main() {
	Paquet p;
	initPaquet(&p);
	remplir(&p);
	melanger(&p);
	afficher(&p);
	Item pioche = piocher(&p);
	afficher(&p);
	printf("%c", pioche);
	detruirePaquet(&p);
	
}