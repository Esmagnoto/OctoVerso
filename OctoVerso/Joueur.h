#pragma once 
#include "item.h"

typedef struct {
	int nbOrdre;
	Item* chevalets;
	int nbChevalets;
} Joueur;

void initjoueur(Joueur* j);

void piocher();

void faireCoup();

void nbChevalets();

void signalerMot();

