#include <stdio.h>
#include <stdlib.h>
#include "okrag.h"
#include "rysowanie.h"
#include "kolka.h"
#include "krawedzie.h"
#include "rogi.h"

int main(int argc, char** argv)
{
    FILE * fp = argc > 1 ? fopen(argv[1], "r") : stdin;
    int x,y = 0;
    indx = 0;
    for(x = 0; x < 40; x++){
        for(y = 0; y < 81; y++){
	     char c = getc(fp);
	     int k,l;
	   
	     if( c == '*'){
	       for(k = 100*x; k < 100*(x+1); k++){
	          for(l = 100*y; l < 100*(y+1); l++){
		    tab[k][l] = -999;
	          }
	       }
    	    }
	    else if( c == '#'){
	       for(k=100*x; k < 100*(x+1); k++){
	          for(l=100*y; l < 100*(y+1); l++){
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

    double test = 0.5;
    x = 300;
    y = 300;
    wypelnij360(tab,x,y,test);

    FILE *f = argc > 2 ? fopen(argv[2], "wb") : stdout;
    char* rysunek = argv[2];

    int cykle = argc > 3 ? atoi(argv[3]) : 1;
    if( cykle > 1) 
        przemnoz_przez_czas(tab,cykle);
    rysuj_heatmape(tab,f,rysunek);

     FILE * zraszacze = argc > 4 ? fopen(argv[4], "w") : stdout;
    fprintf(zraszacze, "polozenie x, polozenie y, kat, kat obrotu\n");
    for(int i=0; i<indx; i++){
	fprintf(zraszacze, ("%d, %d, %d, %d\n"), tab_okregow[i].x, tab_okregow[i].y, tab_okregow[i].kat, tab_okregow[i].kat_obrotu);
    }
    return 0;
}
