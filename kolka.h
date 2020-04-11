#ifndef KOLKA_H_INCLUDED
#define KOLKA_H_INCLUDED

#define ROZMIAR_X 8000
#define ROZMIAR_Y 4000

#define TOLERANCJA 7

void wypelnij360(int tab[ROZMIAR_Y][ROZMIAR_X],int x0,int y0,double wspolczynnik);

double sprawdzanie_warunku(int tablica[ROZMIAR_Y][ROZMIAR_X], int srodek_x, int srodek_y);

#endif // KOLKA_H_INCLUDED
