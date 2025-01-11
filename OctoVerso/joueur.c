#include "Joueur.h"


void initjoueur(Joueur* j, int no)
{
	initPaquet(j->chevalets,MAINJOUEUR);
	j->nbChevalets = 0;
	j->nbOrdre = no;
}

void piocher(Joueur* j, Item* it)
{
	ajouter(j->chevalets, *it);
	j->nbChevalets++;
}
