//////////////////////////////////
//
// Tiedosto: my-unzip.c
// Tekijä: Aleksi Karhu 
// Opiskelijanumero: 0452237
// Päivämäärä: 10.12.2019
// Lähteet: C-kieli ohjelmointiopas, Kasurinen & Nikula 2012
//
//////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv){
	FILE* file;
  	int c, count;
	
	//Virheentarkastus tyhjän komentoriviparametrin varalle 	
	if (argc == 1){
    	printf("my-unzip: file1 [file2...]\n");
    	exit(1);
  	}
  	for (int i = 1; i < argc; i++){
		//Tiedoston avaus ja avauksen virheentarkistus
    	file = fopen(argv[i], "r");
    	if (file == NULL) {
      		printf("Error opening file\n");
      		exit(1);
    	}
		// Käydään tiedosto läpi 
    	while (fread(&count, sizeof(int), 1, file) == 1){
      		c = fgetc(file);
			// Tulostetaan j-määrä samaa merkkiä
      		for (int j = 0; j < count; j++){
        		printf("%c", c);
      		}
    	}
    	fclose(file);
  	}
	return 0;
}
