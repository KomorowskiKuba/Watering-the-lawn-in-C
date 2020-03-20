#include "rysowanie.h"

void rysuj_heatmape(int tab[ROZMIAR_Y][ROZMIAR_X], FILE * f, int r_x, int r_y, char *nazwa)
{
    f = fopen(nazwa, "wb");
    fprintf(f, "P6\n%d %d\n255\n", r_x, r_y);

    for(int i = 0; i < r_y; i++)
    {
        for(int j = 0; j < r_x; j++)
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
