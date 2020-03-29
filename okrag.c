#include <stdio.h>
#include <math.h>
#include "okrag.h"

#define TOLERANCJA 7
#define PI 3.14159265

void stworz_kolo(int srodek_x, int srodek_y, int tab[ROZMIAR_Y][ROZMIAR_X], double kat, double kat_obrotu)
{
    int x, y, r;
    double a1 = tan (kat_obrotu * PI / 180), a2 = -1 / a1;

    if(a1 == 0.0)
        a2 = -1000000000;

    if(kat == 90)
    {
        r = 500;

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

        for(int i = 0; i < ROZMIAR_Y; i++)
        {
            x = srodek_y - i;

            for(int j = 0; j < ROZMIAR_X; j++)
            {
                y = srodek_x - j;

                if((kat_obrotu >= 0 && kat_obrotu <= 90) || (kat_obrotu > 180 && kat_obrotu <= 270))
                {
                    if((x * x + y * y <= r * r + TOLERANCJA) && y <= a1 * x && y >= a2 * x)
                        tab[i][j]+=4;
                }
                else if(kat_obrotu > 90 && kat_obrotu <= 180)
                {
                    if((x * x + y * y <= r * r + TOLERANCJA) && y >= a1 * x && y >= a2 * x)
                        tab[i][j]+=4;
                }
                else if(kat_obrotu > 270 && kat_obrotu < 360)
                {
                    if((x * x + y * y <= r * r + TOLERANCJA) && y <= a1 * x && y <= a2 * x)
                        tab[i][j]+=4;
                }
            }
        }
    }
    else if(kat == 180) // dziala
    {
        r = 400;

        for(int i = 0; i < ROZMIAR_Y; i++)
        {
            x = srodek_y - i;

            for(int j = 0; j < ROZMIAR_X; j++)
            {
                y = srodek_x - j;

                if((kat_obrotu <= 90 && kat_obrotu >= 0) || (kat_obrotu > 90 && kat_obrotu <= 180))
                {
                    if((x * x + y * y <= r * r + TOLERANCJA) && (y >= a2 * x))
                        tab[i][j]+=3;
                }
                else if((kat_obrotu >= 270 && kat_obrotu < 360) || (kat_obrotu > 180 && kat_obrotu < 270))
                {
                    if((x * x + y * y <= r * r + TOLERANCJA) && (y <= a2 * x))
                        tab[i][j]+=3;
                }
            }
        }
    }
    else if(kat == 270)
    {
        r = 300;

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

        for(int i = 0; i < ROZMIAR_Y; i++)
        {
            x = srodek_y - i;

            for(int j = 0; j < ROZMIAR_X; j++)
            {
                y = srodek_x - j;

                if((kat_obrotu >= 0 && kat_obrotu <= 90) || (kat_obrotu > 180 && kat_obrotu <= 270))
                {
                    if((x * x + y * y <= r * r + TOLERANCJA) && (y >= a1 * x || y <= a2 * x))
                        tab[i][j]+=2;
                }
                else if(kat_obrotu > 90 && kat_obrotu <= 180)
                {
                    if((x * x + y * y <= r * r + TOLERANCJA) && (y <= a1 * x || y <= a2 * x))
                        tab[i][j]+=2;
                }
                else if(kat_obrotu > 270 && kat_obrotu < 360)
                {
                    if((x * x + y * y <= r * r + TOLERANCJA) && (y >= a1 * x || y >= a2 * x))
                        tab[i][j]+=2;
                }
            }
        }
    }
    else if(kat == 360)
    {
        r = 200;

        for(int i = 0; i < ROZMIAR_Y; i++)
        {
            x = srodek_y - i;

            for(int j = 0; j < ROZMIAR_X; j++)
            {
                y = srodek_x - j;

                if(x * x + y * y <= r * r + TOLERANCJA)
                    tab[i][j]++;
            }
       }
    }
}
