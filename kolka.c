#include <stdio.h>
#include <math.h>
#include "okrag.h"
#include "rysowanie.h"
#include "kolka.h"

void wypelnij360(int tab[ROZMIAR_Y][ROZMIAR_X],int x0,int y0,double wspolczynnik){
    double test = 0.0;
    int x,y;

    for(x = x0; x < 3700; x += 50){
        for(y = y0; y < 7700; y += 100){
	   test = sprawdzanie_warunku(tab,x,y);
	   if(test >= wspolczynnik){
	       stworz_kolo(y,x,tab,360,0);
	       y += 100;
	   }
	}
    }
}

double sprawdzanie_warunku(int tab[ROZMIAR_Y][ROZMIAR_X], int srodek_x, int srodek_y){
	int r = 200;
	int x,y;
	double zbadane_pola = 0.0;
	double niepodlane = 0.0;
	double wspolczynnik = 0.0;

	for(int i = 0; i < 2*r; i++){
            x = srodek_x - r + i;
            for(int j = 0; j < 2*r; j++){
                y = srodek_y - r + j;
                if((i-r) * (i-r) + (j-r) * (j-r) <= r * r + TOLERANCJA){
		    if(tab[x][y] == 0){
			niepodlane += 3.0;
		    	zbadane_pola++;
		    }
		    else if(tab[x][y] > 0){
		    	zbadane_pola++;
		    }
		    else if(tab[x][y] < 0){
		        zbadane_pola++;
		    }
		wspolczynnik = niepodlane / zbadane_pola;
		}
	    }
	}
	return wspolczynnik;
}
