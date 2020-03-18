#ifndef KOLO_W_C_H_INCLUDED
#define KOLO_W_C_H_INCLUDED

#define ROZMIAR_X 8000
#define ROZMIAR_Y 4000

void stworz_kolo(int r_x, int r_y, int srodek_x, int srodek_y, long long tab[ROZMIAR_Y][ROZMIAR_X], double kat, double kat_obrotu);

void rysuj_heatmape(long long tab[ROZMIAR_Y][ROZMIAR_X], FILE * f, int r_x, int r_ym, char *nazwa);

#endif // KOLO_W_C_H_INCLUDED
