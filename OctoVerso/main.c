
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "Paquet.h"
#include "Rail.h"
#include "Joueur.h"
#pragma warning (disable : 4996)

void distribuerChevalets(Joueur* j1, Joueur* j2, Paquet* p) {
	for (int i = 0; i < MAINJOUEUR; i++)
	{
		piocher(&j1, pioche(&p));
		piocher(&j2, pioche(&p));
	}
}
int main() {
	Paquet p;
	Joueur j1;
	Joueur j2;
	Rail r;

	initPaquet(&p, NBCHEVALETS);
	remplir(&p);
	melanger(&p);
	afficher(&p);
	distribuerChevalets(&j1, &j2, &p);

	detruirePaquet(&p);
	
}