/*
je define un joueur
*/
#pragma once
#include "liste.h"

typedef struct {
	int numOrdre;
	ItemL* chevalets; // tableau dinamique des chevalets
	int nbChevalets;
}Joueur;


void afficherChevalets(const Joueur* j);