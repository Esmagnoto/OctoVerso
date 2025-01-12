//#include "dictionnaire.h"
//#include <assert.h>
//#include <string.h>
//
//int initDictionnaire(Dictionnaire* d, const char* nomFichier)
//{
//	d->file = fopen(nomFichier, "r");
//	if (d->file == NULL) {
//		//printf("fichier non accessible\n");
//		return 1;
//	}
//	d->mots = NULL;
//	d->nbMots = 0;
//	return 0;
//}
//
//
//int lireMot(Dictionnaire* d, const char* motCherche)
//{
//	assert(d->file != NULL);
//	rewind(d->file);
//	char buffer[30];
//
//	while (fscanf(d->file, "%29s", buffer) == 1) {
//		if (motUtilise(d, motCherche)== 0 && strcmp(buffer, motCherche) == 0) {
//			d->mots = realloc(d->mots, (d->nbMots + 1) * sizeof(char*));
//			d->mots[d->nbMots] = strdup(motCherche);
//			++d->nbMots;
//			return 1; // mot trouve dans le dictionnaire et ajoute a la liste de mots utilisees
//		}
//	}
//	return 0; // mot non trouve dans le dictionnaire ou deja utilise
//}
//
//int motUtilise(const Dictionnaire* d, const char* motCherche) {
//	assert(d->nbMots > 0);
//	for (int i = 0; i < d->nbMots; ++i) {
//		if (strcmp(d->mots[i], motCherche) == 0)
//			return 1; // mot deja utilise
//	}
//	return 0; // mot non utilise
//}
//
//
//void detruireDictionnaire(Dictionnaire* d){
//	if (d->file != NULL) {
//		fclose(d->file);
//		d->file = NULL;
//	}
//	for (int i = 0; i < d->nbMots; i++) {
//		free(d->mots[i]);
//	}
//	free(d->mots);
//	d->mots = NULL;
//	d->nbMots = 0;	
//}
