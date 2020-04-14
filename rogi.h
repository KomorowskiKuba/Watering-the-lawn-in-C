#ifndef ROGI_H
#define ROGI_H

typedef struct
{
    int x;
    int y;
    int kat;
    int kat_obrotu;
} rogi_t;

void wypelnij_rogi(int tab[ROZMIAR_Y][ROZMIAR_X], FILE * f, char *nazwa);

#endif
