#include <stdlib.h>
#include "plik.h"

int** trawnik(FILE *in){

	int i,j;
	int** trawnik_tab;

	for(i = 0; i < 40; i++){
		for(j = 0; j < 81; j++){
	 char c = getc(in);
	 int k = 100*i;
	 int l = 100*j;

	if( c == '*'){
	   for( ; k < 100*(i+1); k++){
	      for( ;l < 100*(j+1); j++){
		trawnik_tab[k][l] = -9;
	      }
	   }
	}
	else if( c == '#'){
	   for( ; k < 100*(i+1); k++){
	      for( ;l < 100*(j+1); j++){
		trawnik_tab[k][l] = 0;
	      }
	   }
	}
	else if( c == '\n'){
	}
		}
	}
return trawnik_tab;
}
