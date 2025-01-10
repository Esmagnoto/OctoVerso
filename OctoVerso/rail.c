#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "Rail.h"


void initRail(Rail* r)
{
	r->chevalets = (Liste*)malloc(NBCHMAX * sizeof(Liste));
	r->nbChevalets = 0;
	initListe(r->chevalets);
}

void ajouter(Rail* r, Item* it)
{
	inclure(r->chevalets, it);
}

void enlever(Rail* r, Item* it)
{

}
