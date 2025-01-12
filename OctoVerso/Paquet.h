#pragma once
#include "vecteur.h"
#define NBCHEVALETS 88

typedef struct {
	Vecteur* chevalets;
} Paquet;

/**
 * @brief Initialise un paquet comme étant une liste vide.
 * Pour éviter toute fuite mémoire, tout paquet non vide doit être détruit
 * lorsqu'il ne sera plus utilisée (@ref detruiPaquet).
 * @param[out] p Adresse du paquet devant être initialisé.
 * return 0 en cas d'échec (manque de mémoire disponible) et 1 en cas de succès.
 */
int initPaquet(Paquet* p, int nbChevalets);

/**
 * @brief Remplit un paquet (vide) avec tous les chevalets du jeu.
 * @param[in,out] p Adresse du paquet.
 * return 0 en cas d'échec (manque de mémoire disponible) et 1 en cas de succès.
 * @sa initPaquet
 */
int remplir(Paquet* p);

/**
 * @brief Mélange les chevalets d'un paquet.
 * @param[in,out] p Adresse du paquet.
 * @pre Le paquet ne doit pas être vide.
 */
void melanger(Paquet* p);

/**
 * @brief Pioche un chevalet dans un paquet.
 * @param[in,out] p Adresse du paquet.
 * @pre Le paquet ne doit pas être vide.
 * @return Le chevalet pioché.
 * */
Item pioche(Paquet* p);

/**
 * @brief Affiche les chevalets d'un paquet.
 * @param[in] p Adresse du paquet.
 * @pre Le paquet ne doit pas être vide.
 */
void afficher(const Paquet* p);

/**
 * @brief Détruit un paquet.
 * @param[in,out] p Adresse du paquet.
 */
void detruirePaquet(Paquet* p);