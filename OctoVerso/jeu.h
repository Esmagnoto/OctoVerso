#pragma once
#include "paquet.h"
#include "rail.h"
#include "joueur.h"

typedef struct {
	Paquet p;
	Rail r;
	Joueur j1, j2;
}Jeu;

void distibuer(Paquet* p);

void afficherMainJoueurs();

void etatJeu();

void lireMot();

void aideH();