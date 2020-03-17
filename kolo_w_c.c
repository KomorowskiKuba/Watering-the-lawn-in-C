#include <stdio.h>
#include <math.h>

#define ROZMIAR_X 8000
#define ROZMIAR_Y 4000
#define SRODEK_KOLA_X 400
#define SRODEK_KOLA_Y 400
#define PROMIEN 200
#define TOLERANCJA 7
#define PI 3.14159265

long long tab[ROZMIAR_Y][ROZMIAR_X];

void stworz_kolo(int r_x, int r_y, int srodek_x, int srodek_y, int r, long long tab[ROZMIAR_Y][ROZMIAR_X], double kat, double kat_obrotu)
{
    int pocz_x = r_x / 2 + srodek_x, pocz_y = r_y / 2 + srodek_y;
    double a1 = tan (kat_obrotu * PI / 180), a2 = -1 / a1;
    if(a1 == 0.0)
        a2 = -1000000000;

    if(kat == 90)
    {

        if(kat_obrotu > 90 && kat_obrotu <= 180)
        {
            a1 =  - tan(((180 - kat_obrotu) * PI) / 180);
            a2 =  - 1 / a1;
            if(a1 == 0.0)
                a2 = 1000000000;
        }

        else if(kat_obrotu > 180 && kat_obrotu <= 270)
        {
            a1 =  - tan(((90 - kat_obrotu) * PI) / 180);
            a2 =  - 1 / a1;
            if(a1 == 0.0)
                a2 = 1000000000;
        }

        for(int i = pocz_y - r - TOLERANCJA; i < pocz_y + r + TOLERANCJA; i++)
        {
            for(int j = pocz_x - r - TOLERANCJA; j < pocz_x + r + TOLERANCJA; j++)
            {
                double x = i - pocz_y, y = j - pocz_x;

                if((kat_obrotu >= 0 && kat_obrotu <= 90) || (kat_obrotu > 180 && kat_obrotu <= 270))
                {
                    if((x * x + y * y <= r * r + TOLERANCJA) && y >= a1 * x && y <= a2 * x)
                        tab[i][j]++;
                }

                else if(kat_obrotu > 90 && kat_obrotu <= 180)
                {
                    if((x * x + y * y <= r * r + TOLERANCJA) && y <= a1 * x && y <= a2 * x)
                        tab[i][j]++;
                }

                else if(kat_obrotu > 270 && kat_obrotu < 360)
                {
                    if((x * x + y * y <= r * r + TOLERANCJA) && y >= a1 * x && y >= a2 * x)
                        tab[i][j]++;
                }
            }
        }
    }

    else if(kat == 180) // dziala
    {
        for(int i = pocz_y - r - TOLERANCJA; i < pocz_y + r + TOLERANCJA; i++)
        {
            for(int j = pocz_x - r - TOLERANCJA; j < pocz_x + r + TOLERANCJA; j++)
            {
                double x = i - pocz_y, y = j - pocz_x;

                if((kat_obrotu <= 90 && kat_obrotu >= 0) || (kat_obrotu > 180 && kat_obrotu < 270))
                {
                    if((x * x + y * y <= r * r + TOLERANCJA) && (y <= a2 * x))
                        tab[i][j]++;
                }

                else if((kat_obrotu > 90 && kat_obrotu <= 180) || (kat_obrotu >= 270 && kat_obrotu < 360))
                {
                    if((x * x + y * y <= r * r + TOLERANCJA) && (y >= a2 * x))
                        tab[i][j]++;
                }
            }
        }
    }
    else if(kat == 270)
    {
        if(kat_obrotu > 90 && kat_obrotu <= 180)
        {
            a1 =  - tan(((180 - kat_obrotu) * PI) / 180);
            a2 =  - 1 / a1;
            if(a1 == 0.0)
                a2 = 1000000000;
        }

        else if(kat_obrotu > 180 && kat_obrotu <= 270)
        {
            a1 =  - tan(((90 - kat_obrotu) * PI) / 180);
            a2 =  - 1 / a1;
            if(a1 == 0.0)
                a2 = 1000000000;
        }

        for(int i = pocz_y - r - TOLERANCJA; i < pocz_y + r + TOLERANCJA; i++)
        {
            for(int j = pocz_x - r - TOLERANCJA; j < pocz_x + r + TOLERANCJA; j++)
            {
                double x = i - pocz_y, y = j - pocz_x;

                if((kat_obrotu >= 0 && kat_obrotu <= 90) || (kat_obrotu > 180 && kat_obrotu <= 270))
                {
                    if((x * x + y * y <= r * r + TOLERANCJA) && (y <= a1 * x || y >= a2 * x))
                        tab[i][j]++;
                }

                else if(kat_obrotu > 90 && kat_obrotu <= 180)
                {
                    if((x * x + y * y <= r * r + TOLERANCJA) && (y >= a1 * x || y >= a2 * x))
                        tab[i][j]++;
                }

                else if(kat_obrotu > 270 && kat_obrotu < 360)
                {
                    if((x * x + y * y <= r * r + TOLERANCJA) && (y <= a1 * x || y <= a2 * x))
                        tab[i][j]++;
                }
            }
        }
    }

    else if(kat == 360)
    {
        for(int i = pocz_y - r - TOLERANCJA; i < pocz_y + r + TOLERANCJA; i++)
        {
            for(int j = pocz_x - r - TOLERANCJA; j < pocz_x + r + TOLERANCJA; j++)
            {
                double x = i - pocz_y, y = j - pocz_x;

                if(x * x + y * y <= r * r + TOLERANCJA)
                    tab[i][j]++;
            }
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
    for(int i = 0; i < ROZMIAR_Y; i++)
    {
       for(int j = 0; j < ROZMIAR_X; j++)
            tab[i][j] = 0;
    }

    stworz_kolo(ROZMIAR_X, ROZMIAR_Y, SRODEK_KOLA_X, SRODEK_KOLA_Y, PROMIEN, tab, 180, 15);
    stworz_kolo(ROZMIAR_X, ROZMIAR_Y, SRODEK_KOLA_X+50, SRODEK_KOLA_Y+50, 400, tab, 90, 45);

    rysuj_heatmape(tab, fp, ROZMIAR_X, ROZMIAR_Y);

    return 0;
}
