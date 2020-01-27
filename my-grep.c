//////////////////////////////////
//
// Tiedosto: my-grep.c
// Tekijä: Aleksi Karhu 
// Opiskelijanumero: 0452237
// Päivämäärä: 15.12.2019
// Lähteet: C-kieli ohjelmointiopas, Kasurinen & Nikula 2012
//
//////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Puskurin koko 128 merkkiä
#define buffSize 128

int main(int argc, char *argv[]) {
	int foundWords = 0, i;
	char *findWord = argv[1], buffer[buffSize];
	FILE *file;
	//Komentoriviparametrit puuttuvat 
	if (argc == 1) {
		printf("my-grep: searchterm [file ...]\n");
		exit(1);
	//Luetaan stdinistä
	} else if (argc == 2) {
		printf("Reading stdin\n");
		while(fgets(buffer, buffSize, stdin)) {
			if(strstr(buffer, findWord) != NULL) {
				printf("%s", buffer);
			}			
		}	
	} else {
	//Tiedoston avaus ja avauksen virheentarkistus
		for(i = 2; i < argc; i++) {
			printf("Finding in file: %s\n", argv[i]);
			file = fopen(argv[i], "r");
			if(file == NULL){
				perror("Error: my-grep\n");
				exit(1);
			}
	//Tietojen tulostus
			while(fgets(buffer, buffSize, file) != NULL) {
				if(strstr(buffer, findWord) != NULL) {
					printf("%s", buffer);
					foundWords++;
				}
			}
	//Tieto käyttäjälle, jos sanalla ei löydy hakutuloksia
			if(foundWords == 0) {
				printf("No matches found for word: %s\n", findWord);
			}
		}
	//Tiedoston sulku
		fclose(file);
	}
	return 0;
}
