//////////////////////////////////
//
// Tiedosto: my-zip.c
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
 	int c = 0, lastChar = -1, count = 0;	
	//Virheentarkastus tyhjän komentoriviparametrin varalle
	if (argc < 2) {
		printf("my-zip: file1 [file2 ...]\n");
    	exit(1);
  	}
  	for (int i = 1; i < argc; i++){
		// Avataan tiedosto ja tarkistetaan virheiden varalta
    	file = fopen(argv[i], "r");
		if (file == NULL) {
    		printf("Error opening file\n");
			exit(1);
  		}
		// Käydään läpi tiedosto
    	while ((c = fgetc(file)) != EOF){
			// Katsotaanko onko ensimmäinen merkki ja kasvatetaan muutujien arvoja
      		if (lastChar == -1) {
        		lastChar = c;
        		count++;
			// Merkki vaihtuu, kirjoitetaan tiedostoon
      		} else if (c != lastChar) {
			// Kirjoittaa lukumäärän
        		fwrite(&count, sizeof(int), 1, stdout);
			// Kirjoittaa kirjaimen
        		fputc(lastChar, stdout);
        		count = 1;
			// Sama merkki, laskuri kasvaa
      		} else {
        		count++;
      		}
      		lastChar = c;
    	}
    fclose(file);
	}
	// Tulostaa rivinvaihdon merkkijonon perään
	if (count > 0){
    	fwrite(&count, sizeof(int), 1, stdout);
    	fputc(lastChar, stdout);
  	}
	return 0;
}
