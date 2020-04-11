#include "rysowanie.h"

int szukaj_max(int tab[ROZMIAR_Y][ROZMIAR_X])
{
    int aktualny_max = 0;
    for(int i = 0; i < ROZMIAR_Y; i++)
    {
        for(int j = 0; j < ROZMIAR_Y; j++)
        {
            if(tab[i][j] > aktualny_max)
                aktualny_max = tab[i][j];
        }
    }
    return aktualny_max;
}

void przemnoz_przez_czas(int tab[ROZMIAR_Y][ROZMIAR_X], int mnoznik)
{
    for(int i = 0; i < ROZMIAR_Y; i++)
    {
        for(int j = 0; j < ROZMIAR_X; j++)
        {
            if(tab[i][j] > 0)
                tab[i][j] *= mnoznik;
        }
    }
}

void rysuj_heatmape(int tab[ROZMIAR_Y][ROZMIAR_X], FILE * f, char *nazwa)
{
    f = fopen(nazwa, "wb");
    fprintf(f, "P6\n%d %d\n255\n", ROZMIAR_X, ROZMIAR_Y);

    for(int i = 0; i < ROZMIAR_Y; i++)
    {
        for(int j = 0; j < ROZMIAR_X; j++)
        {
            static unsigned char color[3];
            if(tab[i][j] == 0)
            {
                color[0]= 255; /* red */
                color[1]= 0; /* green */
                color[2]= 0; /* blue */
                fwrite(color, 1, 3, f);
            }
            else if(tab[i][j] < -100)
            {
                color[0]= 0; /* red */
                color[1]= 0; /* green */
                color[2]= 0; /* blue */
                fwrite(color, 1, 3, f);
            }
            else if(tab[i][j] > 0)
            {
                int w = 8 * tab[i][j];
                if(w >= 255)
                    w = 255;
                color[0]= 0; /* red */
                color[1]= 255 - w; /* green */
                color[2]= 0; /* blue */
                fwrite(color, 1, 3, f);
            }
        }
    }
    fclose(f);
}
