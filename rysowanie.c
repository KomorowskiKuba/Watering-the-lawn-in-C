#include "rysowanie.h"

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
            else
            {
                color[0]= 0; /* red */
                color[1]= 255 - 30 * tab[i][j]; /* green */
                color[2]= 0; /* blue */
                fwrite(color, 1, 3, f);
            }
        }
    }
    fclose(f);
}
