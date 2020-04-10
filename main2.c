#include <stdio.h>
#include "okrag.h"
#include "rysowanie.h"
#include "kolka.h"
#include "krawedzie.h"
#include "rogi.h"

int main(int argc, char** argv)
{
    FILE * fp = argc > 1 ? fopen(argv[1], "r") : stdin;
    int x,y = 0;

    for(x = 0; x < 40; x++){
        for(y = 0; y < 81; y++){
	     char c = getc(fp);
	     int k,l;
	   
	     if( c == '*'){
	       for(k = 100*x ; k < 100*(x+1); k++){
	          for(l = 100*y ;l < 100*(y+1); l++){
		    tab[k][l] = -1;
	          }
	       }
    	    }
	    else if( c == '#'){
	       for(k=100*x ; k < 100*(x+1); k++){
	          for(l=100*y ;l < 100*(y+1); l++){
		    tab[k][l] = 0;
	          }
	       }
	    }
	    else if( c == '\n'){
	    }
	}
    }

    wypelnij_rogi(tab,fp,argv[1]);
    wypelnij_krawedzie(tab,fp,argv[1]);

    double test = 0.6;
    x = 300;
    y = 300;
    wypelnij360(tab,x,y,test);

    FILE *f = argc > 2 ? fopen(argv[2], "wb") : stdin;
    char* rysunek = argv[3];
    rysuj_heatmape(tab,f,rysunek);
    return 0;
}
