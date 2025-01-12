#pragma once
#include "item.h"
#include "Paquet.h"

#define MAINJOUEUR 12


typedef struct {
	int nbOrdre;
	Paquet* chevalets;
	int nbChevalets;
} Joueur;

void initjoueur(Joueur* j, int no);

void piocher(Joueur* j, Item* it);

void faireCoup();

void nbChevalets();

void signalerMot();
