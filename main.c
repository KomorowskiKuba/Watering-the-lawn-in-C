#include <stdio.h>
#include <math.h>
#include "okrag.h"
#include "rysowanie.h"

#define SRODEK_KOLA_X 400
#define SRODEK_KOLA_Y 400

int tab[ROZMIAR_Y][ROZMIAR_X] = {{0}};

int main()
{
    FILE * fp;

    stworz_kolo(ROZMIAR_X, ROZMIAR_Y, SRODEK_KOLA_X, SRODEK_KOLA_Y, tab, 180, 15);
    stworz_kolo(ROZMIAR_X, ROZMIAR_Y, SRODEK_KOLA_X+50, SRODEK_KOLA_Y+50, tab, 90, 45);

    rysuj_heatmape(tab, fp, ROZMIAR_X, ROZMIAR_Y, "heatmap.ppm");

    return 0;
}
