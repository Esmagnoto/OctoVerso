#pragma once
#include <cstdio>




typedef struct {
	FILE* file;
	char** mots;
	int nbMots
} Dictionnaire;



int initDictionnaire(Dictionnaire* d, const char* nomFichier);

int motUtilise(const Dictionnaire* d, const char* motCherche);

int lireMot(Dictionnaire* d, const char* motCherche);

void detruireDictionnaire(Dictionnaire* d);

