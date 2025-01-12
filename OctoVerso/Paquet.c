#include "paquet.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

void initPaquet(Paquet* p, int nbChevalets)
{
    p->chevalets = (Vecteur*) malloc(sizeof(Vecteur));
    assert(p->chevalets != NULL);
	initVecteur(p->chevalets, nbChevalets);
}

void remplir(Paquet* p) {
    initPaquet(p, NBCHEVALETS);
    const char lettre[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'l', 'm', 'n', 'o', 'p'
    , 'q', 'r', 's', 't', 'u', 'v' };
    const int quantite[] = { 9, 1, 2, 3, 14, 1, 1, 1, 7, 1, 5, 3, 6, 5, 2, 1, 6, 7, 6, 5, 2 };
    const int taille = sizeof(lettre) / sizeof(lettre[0]);

    for (int j = 0; j < taille; j++) {
        for (int k = 0; k < quantite[j]; k++) {
            ajouter(p->chevalets, lettre[j]);
        }
    }
}

void melanger(Paquet* p) {
    assert(taille(p->chevalets) > 0);
    for (int i = taille(p->chevalets) - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        Item tmp = obtenir(p->chevalets,i);
        modifier(p->chevalets, i, obtenir(p->chevalets, j));
        modifier(p->chevalets, j, tmp);
    }
}

Item pioche(Paquet* p)
{
    assert(taille(p->chevalets) > 0);
    Item tmp = obtenir(p->chevalets, taille(p->chevalets)-1);
    supprimer(p->chevalets, taille(p->chevalets)-1);
    return tmp;
}


void afficher(const Paquet* p) {
    assert(taille(p->chevalets) > 0);
    for (int i = 0; i < taille(p->chevalets); i++) {
        printf("%c", obtenir(p->chevalets, i));
    }
    printf("\n");
}

void detruirePaquet(Paquet* p) {
    detruireVecteur(p->chevalets);
    free(p->chevalets);
}