#include <stdio.h>
#include "okrag.h"
#include "krawedzie.h"

void wypelnij_krawedzie(int tab[ROZMIAR_Y][ROZMIAR_X], FILE* dane, char* nazwa)
{
    dane = fopen(nazwa, "r");
    if(dane==NULL)
        printf("error in opening file dane");

    int c,i,j,k,x,y,warunek;
    int tab_wejsciowa[40][80] = {{0}};
    for(int i = 0; i < 40; i++)
    {
        for(int j = 0; j < 81; j++)
        {
            c = fgetc(dane);
            if(c == '*')
                tab_wejsciowa[i][j] = -9;
	    else if(c == '#')
		tab_wejsciowa[i][j] = 0;
        }
    }
    int licznik[10] = {0};

    for(i = 0; i < 40; i++)
    {
        for(j = 0; j < 80; j++)
        {
            if(tab_wejsciowa[i][j] == -9)
            {
                if(i > 1 && tab_wejsciowa[i-1][j] == 0 && tab_wejsciowa[i-2][j] == 0)
                    licznik[0] += 1;
                else
                    licznik[0] = 0;
                if(i < 38 && tab_wejsciowa[i+1][j] == 0 && tab_wejsciowa[i+2][j] == 0)
                    licznik[2] += 1;
                else
                    licznik[2] = 0;
            }
            if(licznik[0] == 8)
            {
                for(k = 0; (tab_wejsciowa[i-1-k][j-8] < 0 && tab_wejsciowa[i-1-k][j-7] >= 0 && i - 1 - k >= 0 && j - 8 >= 0); k++)
                {
                    if(((i - k >= 0 && j - 8 >= 0 && j + 1 < 80) && (tab_wejsciowa[i-k][j-8] < 0 || tab_wejsciowa[i-k][j+1] < 0)) || ((i + k < 40 && j - 8 >= 0 && j + 1 < 80) &&( tab_wejsciowa[i+k][j-8] < 0 || tab_wejsciowa[i+k][j+1] < 0)))
                        warunek++;
                }
                if(warunek >= 5)
                    licznik[0] = 5;
                warunek = 0;
                if(licznik[0] == 8)
                {
                    if(j - 3 > 0 && i < 40)
                    {
		    	x = j - 3;
                    	y = i;
                    	stworz_kolo(x*100,y*100-2,tab,180,0);
		    }
                    x,y,licznik[0] = 0;
                }
            }
            if(licznik[2] == 8)
            {
                for(k = 0; (tab_wejsciowa[i+1+k][j-8] < 0 && tab_wejsciowa[i+1+k][j-7] >= 0 && i + 1 + k < 40 && j - 8 >= 0); k++)
                {
                    if(((i > 4 && i - k >= 0 && j - 8 >= 0 && j + 1 < 80) && (tab_wejsciowa[i-k][j-8] < 0 || tab_wejsciowa[i-k][j+1] < 0)) || ((i < 37 && i + k < 40 && j - 8 >= 0 && j + 1 < 80) &&( tab_wejsciowa[i+k][j-8] < 0 || tab_wejsciowa[i+k][j+1] < 0)))
                        warunek++;
                }
                if(warunek >= 5)
                    licznik[2] = 5;
                warunek = 0;
                if(licznik[2] == 8)
                {
		    if(j - 3 > 0 && i + 1 < 40)
                    {
		    	x = j - 3;
                    	y = i + 1;
                    	stworz_kolo(x*100,y*100+1,tab,180,180);
		    }
                    x,y,licznik[2] = 0;
                }
            }
        }
    }


    for(i = 0; i < 80; i++)
    {
        for(j = 0; j < 40; j++)
        {
            if(tab_wejsciowa[j][i] == -9)
            {
                if(i - 1 >= 0 && i - 2 >= 0 && tab_wejsciowa[j][i-1] == 0 && tab_wejsciowa[j][i-2] == 0)
                    licznik[1] += 1;
                else
                    licznik[1] = 0;
		
                if(i < 77 && tab_wejsciowa[j][i+1] == 0 && tab_wejsciowa[j][i+2] == 0)
                    licznik[3] += 1;
                else
                    licznik[3] = 0;
            }
            if(licznik[1] == 8)
            {
                for(k = 0; (tab_wejsciowa[j-8][i-1-k] < 0 && tab_wejsciowa[j-7][i-1-k] >= 0 && j - 8 >= 0 && i - 1 - k >= 0); k++)
                {
                    if(((j - 8 >= 0 && i - k >= 0 && j + 8 < 40) && (tab_wejsciowa[j-8][i-k] < 0 || tab_wejsciowa[j+8][i-k] < 0)) || ((j - 8 >= 0 && i + k < 80 && j + 8 < 40) && (tab_wejsciowa[j-8][i+k] < 0 || tab_wejsciowa[j+8][i+k] < 0)))
                        warunek++;

                }
                if(warunek >= 5)
                    licznik[1] = 5;
                warunek = 0;
                if(licznik[1] == 8)
                {
		    if(j - 3 >= 0 && i < 80)
                    {	
		    	x = i;
                    	y = j - 3;
                    	stworz_kolo(x*100-1,y*100,tab,180,90);
		    }
                    x,y,licznik[1] = 0;
                }
            }
            if(licznik[3] == 8)
            {
                for(k = 0; (tab_wejsciowa[j-8][i+1+k] < 0 && tab_wejsciowa[j-7][i+1+k] >= 0 && j - 8 >= 0 && i + 1 + k < 80); k++)
                {
                    if(((j - 8 >= 0 && i - k >= 0 && j + 8 < 40) && (tab_wejsciowa[j-8][i-k] < 0 || tab_wejsciowa[j+8][i-k] < 0)) || ((j - 8 >= 0 && i + k < 80 && j + 8 < 40) && (tab_wejsciowa[j-8][i+k] < 0 || tab_wejsciowa[j+8][i+k] < 0)))
                        warunek++;
                }
                if(warunek >= 5)
                    licznik[3] = 4;
                warunek = 0;
                if(licznik[3] == 8)
                {
 		    if(i + 1 < 80 && j - 3 > 0)
                    {	
		    	x = i + 1;
                    	y = j - 3;
                    	stworz_kolo(x*100+1,y*100,tab,180,270);
		    }
                    x,y,licznik[3] = 0;
                }
            }
        }
    }
}
