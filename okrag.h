
#ifndef OKRAG_H_INCLUDED
#define OKRAG_H_INCLUDED

#define ROZMIAR_X 8000
#define ROZMIAR_Y 4000

void stworz_kolo(int srodek_x, int srodek_y, int tab[ROZMIAR_Y][ROZMIAR_X], int kat, int kat_obrotu);
typedef struct {
        int x;
        int y;
        int kat;
        int kat_obrotu;
} okrag_t;
okrag_t tab_okregow[1500];
int indx;

#endif //OKRAG_H_INCLUDED
