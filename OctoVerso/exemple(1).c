//
//#pragma warning (disable : 4996)
//
//#include <string.h>
//#include <stdio.h>
//
//int main() {
//	FILE* f = fopen("ods4.txt", "r");
//	if (f == NULL) {
//		printf("fichier non accessible\n");
//		return;
//	}
//	size_t nbm = 0, nbc = 0;
//	char mot[30] = { 0 };
//	int n;
//	n = fscanf(f, "%29s", mot);
//	while (n == 1) {
//		++nbm;
//		nbc += strlen(mot);
//		n = fscanf(f, "%29s", mot);
//	}
//	if (ferror(f))
//		printf("erreur - %s\n", strerror(errno));
//	else
//		printf("nbre de mots : %zd, nbre moyen de lettres : %.2f\n", nbm, nbc / (float)nbm);
//	fclose(f);
//}
