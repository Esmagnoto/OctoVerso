/* 
je vais definir ici un paquet que contient des cartes Chevalet.h
 */
#pragma once
#include "liste.h"
#include "Joueur.h"
#include "Rail.h"

typedef struct {
	ItemL* chevalets; // tableau dinamique des chevalets
	int nbChevalets;
}Paquet;

void initPaquet(Paquet* p);

void melangerChevalets(Paquet* p);

void distributionChevalets(Paquet* p, Joueur* j1, Joueur* j2, Rail* r);

void afficherPaquet(const Paquet* p);