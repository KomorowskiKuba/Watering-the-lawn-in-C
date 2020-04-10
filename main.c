#include <stdio.h>
#include <math.h>
#include "okrag.h"
#include "rysowanie.h"
#define TOLERANCJA 7

int tab[ROZMIAR_Y][ROZMIAR_X] = {{0}};

double sprawdzanie_warunku(int tablica[ROZMIAR_Y][ROZMIAR_X], int srodek_x, int srodek_y){
	int r = 200;
	int x,y;
	double zbadane_pola = 0.0;
	double niepodlane = 0.0;
	double wspolczynnik = 0.0;
	double wszystkie_pola = 0.0;
	for(int i = 0; i < ROZMIAR_Y; i++)
        {
            x = srodek_y - i;

            for(int j = 0; j < ROZMIAR_X; j++)
            {
                y = srodek_x - j;

                if(x * x + y * y <= r * r + TOLERANCJA)
		{
		    if(tab[i][j] == 0){
			niepodlane++;
		    	zbadane_pola++;
		    }
		    else if(tab[i][j] > 0){
		    	zbadane_pola++;
		    }
		    else if(tab[i][j] < 0){ //Przypadek, gdy pole jest chodnikiem
		        zbadane_pola++;
		    }
		wspolczynnik = niepodlane / zbadane_pola;
		}
	    }
	}

	return wspolczynnik;
}

int main(int argc, char** argv)
{
    FILE * fp = argc > 1 ? fopen(argv[1], "r") : stdin;
    int x,y = 0;
    
    //Zamiana pliku na tablice 8000 x 4000
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
    //Glowny algorytm
    for(x = 300; x < 4000; x += 300){
        for(y = 300; y < 8000; y += 100){
	   double test = 0.0;
	   printf("wspolrzedne: x: %d  y: %d\n",x,y);
	   test = sprawdzanie_warunku(tab,y,x);
	   if(test >= 0.6){
	       stworz_kolo(y,x,tab,360,0);
	       y += 200;
	   }
	}
    }
    FILE *f = argc > 2 ? fopen(argv[2], "wb") : stdin;
    char* rysunek = argv[3];
    rysuj_heatmape(tab,f,rysunek);
    return 0;
}
