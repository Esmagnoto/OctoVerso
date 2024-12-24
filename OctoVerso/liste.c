#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "liste.h"

void initListe(Liste* li) {
    li->premier = li->dernier = NULL; // <-- modification Question 5
    li -> taille = 0; // <-- ajout Question 4
}

int estVide(const Liste* li) {
    return li->premier == NULL;
}

int inclure(Liste* li, ItemL it) {
    Maillon* m = (Maillon*)malloc(sizeof(Maillon));
    if (m == NULL)
        return 0;
    m->element = it;
    m->suivant = li->premier;
    li->premier = m;
    if (li->dernier == NULL) // <-- ajout Question 5
        li->dernier = m;
    
    ++li->taille; // <-- ajout Question 4
    return 1;
}

ItemL premier(const Liste* li) {
    assert(!estVide(li));
    return li->premier->element;
}

void tronquer(Liste* li) {
    assert(!estVide(li));
    Maillon* m = li->premier;
    li->premier = m->suivant;
    if (li->premier == NULL) // <-- ajout Question 5
        li->dernier = NULL;
    free(m);
    --li->taille; // <-- ajout Question 4
}

void detruireListe(Liste* li) {
    while (!estVide(li))
        tronquer(li);
}

ConstIt iterer(const Liste* li) {
    return li->premier;
}

int fini(const ConstIt* iter) {
    return *iter == NULL;
}

ItemL courant(const ConstIt* iter) {
    assert(!fini(iter));
    return (*iter)->element;
}

void suivant(ConstIt* iter) {
    assert(!fini(iter));
    *iter = (*iter)->suivant;
}

void initIterateur(Liste* li, Iterateur* iter) {
    iter->liste = li;
    iter->pred = NULL;
    iter->courant = li->premier;
}

int finiIt(const Iterateur* iter) {
    return iter->courant == NULL;
}

ItemL courantIt(const Iterateur* iter) {
    assert(!finiIt(iter));
    return iter->courant->element;
}

void suivantIt(Iterateur* iter) {
    assert(!finiIt(iter));
    iter->pred = iter->courant;
    iter->courant = iter->courant->suivant;
}

void changer(const Iterateur* iter, ItemL it) {
    assert(!finiIt(iter));
    iter->courant->element = it;
}

int inserer(Iterateur* iter, ItemL it) {
    Maillon* m = (Maillon*)malloc(sizeof(Maillon));
    if (m == NULL)
        return 0;
    m->element = it;
    m->suivant = iter->courant;
    if (iter->pred == NULL)
        iter->liste->premier = m;
    else
        iter->pred->suivant = m;
    if(iter->pred == NULL) // <-- ajout Question 5
        iter->liste->dernier = m;
    iter->courant = m;
    ++iter->liste->taille; // <-- ajout Question 4
    return 1;
}

ItemL effacer(Iterateur* iter) {
    assert(!finiIt(iter));
    Maillon* m = iter->courant;
    if (iter->pred == NULL)
        iter->liste->premier = m->suivant;
    else
        iter->pred->suivant = m->suivant;
    if (m->suivant == NULL) // <-- ajout Question 5
        iter->liste->dernier = iter->pred;
    iter->courant = m->suivant;
    ItemL it = m->element;
    free(m);
    --iter->liste->taille; // <-- ajout Question 4
    return it;
}





// QUESTION 1
void affiche(const Liste* liste) {
    int p = 0;
    printf("[");
    for (ConstIt it = iterer ( liste ); !fini(&it); suivant(&it)) {
        printf("%s%d", p ? ", " : "", courant(&it));
        p = 1;
    }
    printf("]\n");
}







// QUESTION 2
Liste crible(int n) {
    
    Liste premiers;
    initListe(&premiers);
    
    for(int i = n; i > 1; --i)
        inclure(&premiers, i);
    
    Iterateur it;
    initIterateur(&premiers, &it);
    while(!finiIt(&it)) {
        int p = courantIt(&it);
        Iterateur tmp = it;
        suivantIt(&tmp);
        while(!finiIt(&tmp)) {
            if (courantIt(&tmp) % p == 0)
                effacer(&tmp);
            else
                suivantIt(&tmp);
        }
        suivantIt(&it);
    }
    return premiers;
}


//QUESTION 3
Liste crible(int n) {
    assert (n >= 0); // pour sqrtf
    float max = sqrtf((float)n); // calcul de la borne
    Liste premiers;
    initListe (&premiers);
    for (int i = n; i > 1; --i)
        inclure (&premiers, i);
    Iterateur it;
    initIterateur (&premiers, &it);
    while (!finiIt(&it) && (float) courantIt(&it) <= max) { // boucle bornée
        int p = courantIt(&it);
        Iterateur tmp = it;
        suivantIt(&tmp);
        while (!finiIt(&tmp)) {
            if (courantIt(&tmp) % p == 0)
                effacer (&tmp);
            else
                suivantIt(&tmp);
        }
        suivantIt(&it);
    }
    return premiers;
}


// QUESTION 4
int taille(const Liste* li){
    return li->taille;
}




// QUESTION 5
int inclureFin(Liste* li,ItemL it){
    Maillon* m = (Maillon*)malloc(sizeof(Maillon));
    if(m==NULL)
        return 0;
    m->element = it;
    m->suivant = NULL;
    if (li->premier == NULL)
        li->premier = li->dernier = m;
    else {
        li->dernier->suivant = m; 
        li->dernier = m;
    }
    ++li->taille;
    return 1;
}




// QUESTION 6

unsigned int ronde(unsigned int n, unsigned int c, unsigned int e){
    assert(n > 0 && c > 0);
    assert(e > 0 && e <= n);
    Liste liste;
    initListe(&liste);
    for(unsigned int i = 1; i <= n ; ++i)
        inclureFin(&liste, i);
    for(unsigned int i = 1; i <= e ; ++i){
        int player = premier(&liste);
        tronquer(&liste);
        inclureFin(&liste, player);
    }
    // éléction
    int tour = 1;
    while(taille(&liste) > 1){
        int player = premier(&liste);
        tronquer(&liste);
        if(tour % c != 0)
            inclureFin(&liste, player);
        ++tour;
    }
    int gagnant = premier(&liste);
    detruireListe(&liste);
    return gagnant;
}
