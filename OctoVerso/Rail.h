#pragma once
#include "liste.h"

#define NBCHMAX 8

typedef struct {
	Liste* chevalets;
} Rail;

void initRail(Rail* r);

void ajouterR(Rail* r, Item* it);
//gauche droite
void ajouterI(Rail* r, Item* it);

void enlever(Rail* r, Item* it);

void palindrome(const Rail* r);

void afficherR(const Rail* r);

//void estVide();

//void estPlein();

void detruireRail();

