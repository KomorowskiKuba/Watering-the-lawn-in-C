#include <stdio.h>
#include "okrag.h"
#include "rogi.h"

void wypelnij_rogi(int tab[ROZMIAR_Y][ROZMIAR_X], FILE * dane, char *nazwa){
dane = fopen(nazwa, "r");
    if(dane==NULL)
        printf("error in opening file dane");

    rogi_t tab_rogow[200];
    int c;
    int s=0;
    int tab_wejsciowa[40][80]={{0}};
    for(int i=0; i<40; i++){      // zamiana danych wejsciowych na tablice, gdzie *=-9, #=0
        for(int j=0; j<81; j++){
            c=fgetc(dane);
            if(c=='*')
                tab_wejsciowa[i][j]=-9;
        }
    }

    for(int i=1; i<39; i++){
        for(int j=1; j<79; j++){
            if(tab_wejsciowa[i][j]==0){
                if(tab_wejsciowa[i-1][j]==-9 && tab_wejsciowa[i][j-1]==-9){
                    tab_rogow[s].x=100*j;
                    tab_rogow[s].y=100*i;
                    tab_rogow[s].kat=90;
                    tab_rogow[s].kat_obrotu=270;
                    s++;
                }
		if(tab_wejsciowa[i-1][j]==-9 && tab_wejsciowa[i][j+1]==-9){
                    tab_rogow[s].x=100*(j+1);
                    tab_rogow[s].y=100*i;
                    tab_rogow[s].kat=90;
                    tab_rogow[s].kat_obrotu=180;
                    s++;
                }
                if(tab_wejsciowa[i+1][j]==-9 && tab_wejsciowa[i][j-1]==-9){
                    tab_rogow[s].x=100*j;
                    tab_rogow[s].y=100*(i+1);
                    tab_rogow[s].kat=90;
                    tab_rogow[s].kat_obrotu=0;
                    s++;
                }
                if(tab_wejsciowa[i+1][j]==-9 && tab_wejsciowa[i][j+1]==-9){
                    tab_rogow[s].x=100*(j+1);
                    tab_rogow[s].y=100*(i+1);
                    tab_rogow[s].kat=90;
                    tab_rogow[s].kat_obrotu=90;
                    s++;
                }
                if(tab_wejsciowa[i+1][j+1]==-9 && tab_wejsciowa[i+1][j]==0 && tab_wejsciowa[i][j+1]==0){
                    tab_rogow[s].x=100*(j+1);
                    tab_rogow[s].y=100*(i+1);
                    tab_rogow[s].kat=270;
                    tab_rogow[s].kat_obrotu=270;
                    s++;
		}
	 	if(tab_wejsciowa[i+1][j-1]==-9 && tab_wejsciowa[i+1][j]==0 && tab_wejsciowa[i][j-1]==0){
                    tab_rogow[s].x=100*j;
                    tab_rogow[s].y=100*(i+1);
                    tab_rogow[s].kat=270;
                    tab_rogow[s].kat_obrotu=180;
                    s++;
                }
                if(tab_wejsciowa[i-1][j+1]==-9 && tab_wejsciowa[i][j+1]==0 && tab_wejsciowa[i-1][j]==0){
                    tab_rogow[s].x=100*(j+1);
                    tab_rogow[s].y=100*i;
                    tab_rogow[s].kat=270;
                    tab_rogow[s].kat_obrotu=0;
                    s++;
                }
                if(tab_wejsciowa[i-1][j-1]==-9 && tab_wejsciowa[i][j-1]==0 && tab_wejsciowa[i-1][j]==0){
                    tab_rogow[s].x=100*j;
                    tab_rogow[s].y=100*i;
                    tab_rogow[s].kat=270;
                    tab_rogow[s].kat_obrotu=90;
                    s++;
                }
            }
        }
    }
for(int i=0; i<s; i++){
        stworz_kolo(tab_rogow[i].x, tab_rogow[i].y, tab, tab_rogow[i].kat, tab_rogow[i].kat_obrotu);
    }
}	
