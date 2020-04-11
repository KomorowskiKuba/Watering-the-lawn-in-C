#ifndef ROGI_H_INCLUDED
#define ROGI_H_INCLUDED

struct e{
        int x;
        int y;
        int kat;
        int kat_obrotu;
} typedef rogi_t;

void wypelnij_rogi(int tab[ROZMIAR_Y][ROZMIAR_X], FILE * f, char *nazwa);

#endif // ROGI_H_INCLUDED
