#include <stdio.h>
#include <math.h>
#include "okrag.h"
#include "rysowanie.h"
#include "kolka.h"

void wypelnij360(int tab[ROZMIAR_Y][ROZMIAR_X],int x,int y,double wspolczynnik){
    double test = 0.0;

    for(x = 300; x < 4000; x += 300){
        for(y = 300; y < 8000; y += 100){
	   test = sprawdzanie_warunku(tab,y,x);
	   printf("wspolrzedne x:%d y:%d\n",x,y);
	   if(test >= wspolczynnik){
	       stworz_kolo(y,x,tab,360,0);
	       y += 200;
	   }
	}
    }
}

double sprawdzanie_warunku(int tablica[ROZMIAR_Y][ROZMIAR_X], int srodek_x, int srodek_y){
	int r = 200;
	int x,y;
	double zbadane_pola = 0.0;
	double niepodlane = 0.0;
	double wspolczynnik = 0.0;
	for(int i = 0; i < ROZMIAR_Y; i++){
            x = srodek_y - i;
            for(int j = 0; j < ROZMIAR_X; j++){
                y = srodek_x - j;
                if(x * x + y * y <= r * r + TOLERANCJA){
		    if(tab[i][j] == 0){
			niepodlane++;
		    	zbadane_pola++;
		    }
		    else if(tab[i][j] > 0){
		    	zbadane_pola++;
		    }
		    else if(tab[i][j] < 0){
		        zbadane_pola++;
		    }
		wspolczynnik = niepodlane / zbadane_pola;
		}
	    }
	}
	return wspolczynnik;
}
