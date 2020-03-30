#include <stdio.h>
#include <math.h>
#include "okrag.h"
#include "rysowanie.h"
#include "rogi.h"

int tab[ROZMIAR_Y][ROZMIAR_X] = {{0}};

int main(int argc, char * args[])
{
    FILE * fp;
    FILE * dane;
    if(argc<2){
	printf("nie podano danych wejsciowych\n");
	return 1;
    }
	   
    wypelnij_rogi(tab, dane, args[1]); 
    rysuj_heatmape(tab, fp, "heatmap.ppm");
    return 0;    
}
