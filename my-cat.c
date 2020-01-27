//////////////////////////////////
//
// Tiedosto: my-cat.c
// Tekijä: Aleksi Karhu 
// Opiskelijanumero: 0452237
// Päivämäärä: 15.12.2019
// Lähteet: C-kieli ohjelmointiopas, Kasurinen & Nikula 2012
//
//////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#define buffSize 128

int main(int argc, char *argv[]) {	
	int i;	
	char buffer[buffSize];
	FILE *file;
	//Virheentarkastus puuttuvan tiedostonimen vuoksi
	if(argc == 1){
		printf("Please enter a valid filename.\n");	
		exit(1);
	}
	//Tiedoston avaus ja avauksen virheentarkastus
	for(i = 1; i < argc; i++) {
		file = fopen(argv[i], "r");
		if(file == NULL){
			perror("Error: my-cat\n");
			exit(1);
		}		
	//Tiedoston luku, tulostus ja sulku
		while(fgets(buffer, buffSize, file)) {
			printf("%s", buffer);
		}
		fclose(file);
	}	
	return 0;
}
