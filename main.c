#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
	
	int trawnik[40][80];
	int i,j;
	FILE *in = argc > 1 ? fopen( argv[1], "r" ) : stdin;

 	if( in == NULL ) {
	  fprintf( stderr, "%s: błąd: nie mogę czytać pliku %s\n", argv[0], argv[1] );
    	  return EXIT_FAILURE;
 	 }

	for(i = 0; i < 40; i++){
		for(j = 0; j < 81; j++){
	 char c = getc(in);
 
	
	if( c == '*'){
		trawnik[i][j] = 0;
	}
	else if( c == '#'){
		trawnik[i][j] = 1;
	}
	else if( c == '\n'){
	}	
	else{
		fprintf( stderr, "%s blad w pliku wejsciowym %s\n", argv[0], argv[1]);
		return EXIT_FAILURE;
	}
		}
	}
	

	printf("\n");
	for(i = 0; i < 40; i++){
		for(j = 0; j < 80; j++){
			printf("%d",trawnik[i][j]);
		}
	printf("\n");
	}
	
}
