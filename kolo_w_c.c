#include <stdio.h>

#define ROZMIAR_X 8000
#define ROZMIAR_Y 4000
#define SRODEK_KOLA_X 0
#define SRODEK_KOLA_Y 0
#define PROMIEN 200
#define TOLERANCJA 7

long long tab[ROZMIAR_Y][ROZMIAR_X];

void stworz_kolo(int r_x, int r_y, int srodek_x, int srodek_y, int r, long long tab[ROZMIAR_Y][ROZMIAR_X])
{
    int pocz_x = r_x / 2 + srodek_x, pocz_y = r_y / 2 + srodek_y;

    for(int i = 0; i < r_y; i++)
    {
       for(int j = 0; j < r_x; j++)
       {
            double x = i - pocz_y, y = j - pocz_x;
            if(x * x + y * y <= r * r + TOLERANCJA)
                tab[i][j]++;
       }
    }
}

void rysuj_heatmape(long long tab[ROZMIAR_Y][ROZMIAR_X], FILE * f, int r_x, int r_y)
{
    f = fopen("heatmap.ppm", "wb");
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

int main()
{
    FILE * fp;
    for(int i = 0; i < ROZMIAR_Y; i++) // zerowanie tablicy
    {
       for(int j = 0; j < ROZMIAR_X; j++)
            tab[i][j] = 0;
    }

    stworz_kolo(ROZMIAR_X, ROZMIAR_Y, SRODEK_KOLA_X, SRODEK_KOLA_Y, PROMIEN, tab);
    stworz_kolo(ROZMIAR_X, ROZMIAR_Y, 40, 40, PROMIEN, tab);
    stworz_kolo(ROZMIAR_X, ROZMIAR_Y, -40, -40, PROMIEN, tab);
    rysuj_heatmape(tab, fp, ROZMIAR_X, ROZMIAR_Y);

    return 0;
}
