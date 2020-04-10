#include <stdio.h>
#include <math.h>
#include "kolka.h"
#include "okrag.h"
#include "rysowanie.h"

int tab[ROZMIAR_Y][ROZMIAR_X] = {{0}};

int main(int argc, char **argv)
{
    FILE *out;
    for(int i = 0; i < 8000; i++)
    {
        for(int j = 0; j < 100; j++)
            tab[j][i] = -999;
    }

    for(int i = 0; i < 8000; i++)
    {
        for(int j = 3900; j < 4000; j++)
            tab[j][i] = -999;
    }

    for(int i = 400; i < 800; i++)
    {
        for(int j = 500; j < 1200; j++)
            tab[i][j] = -999;
    }



    wypelnij360(tab, 300, 300, 0.6);
    /*for(int i = 1; i <= 5; i++)
    {
        int y = 200*i;
        for(int j = 1; j <= 5; j++)
        {
            int x = 500*j;
            stworz_kolo(x, y, tab, 360, 0);
        }
    }

        stworz_kolo(800, 900, tab, 360, 0);*/
    rysuj_heatmape(tab, out, "heatmapa.ppm");

    return 0;
}
