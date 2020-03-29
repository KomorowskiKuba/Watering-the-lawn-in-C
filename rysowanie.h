#ifndef RYSOWANIE_H_INCLUDED
#define RYSOWANIE_H_INCLUDED

#include <stdio.h>

#define ROZMIAR_X 8000
#define ROZMIAR_Y 4000

void rysuj_heatmape(int tab[ROZMIAR_Y][ROZMIAR_X], FILE * f, char *nazwa);

#endif RYSOWANIE_H_INCLUDED
