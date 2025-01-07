
#pragma once

#include "vecteur.h"
#define NBCHEVALETS 88

typedef struct {
	Vecteur* chevalets;
} Paquet;


void initPaquet(Paquet* p);

void remplir(Paquet* p);

void melanger(Paquet* p);

Item piocher(Paquet* p);

void afficher(const Paquet* p);

void detruirePaquet(Paquet* p);