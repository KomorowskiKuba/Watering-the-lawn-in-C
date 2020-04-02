#ifndef KOLKA_H
#define KOLKA_H

#define TOLERANCJA 7

int tab[ROZMIAR_Y][ROZMIAR_X];

void wypelnij360(int tab[ROZMIAR_Y][ROZMIAR_X],int x,int y,double wspolczynnik);

double sprawdzanie_warunku(int tablica[ROZMIAR_Y][ROZMIAR_X], int srodek_x, int srodek_y);

#endif
