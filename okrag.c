#include <stdio.h>
#include <math.h>
#include "okrag.h"

#define TOLERANCJA 7
#define PI 3.14159265

struct {
    int x;
    int y;
} typedef odbicie;

void stworz_kolo(int srodek_x, int srodek_y, int tab[ROZMIAR_Y][ROZMIAR_X], int kat, int kat_obrotu)
{
    odbicie punkty[100];
    int ilosc_odbic = 0;
    int x, y, r, i, j, stan;
    int odleglosc_gora = 0, odleglosc_dol = 0, odleglosc_lewo = 0, odleglosc_prawo = 0;
    double a1 = tan ((double)kat_obrotu * PI / 180), a2 = -1 / a1;

    if(a1 == 0.0)
        a2 = -1000000000;

    if(kat == 90)
    {
        r = 500;
        stan = 4;

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

        for(i = (srodek_y - r - TOLERANCJA >= 0) ? srodek_y - r - TOLERANCJA : 0; (i < srodek_y + r + TOLERANCJA) && (i < ROZMIAR_Y); i++)
        {
            x = srodek_y - i;

            for(j = (srodek_x - r - TOLERANCJA >= 0) ? srodek_x - r - TOLERANCJA : 0; (j < srodek_x + r + TOLERANCJA) && (j < ROZMIAR_X); j++)
            {
                y = srodek_x - j;

                if((kat_obrotu >= 0 && kat_obrotu <= 90) || (kat_obrotu > 180 && kat_obrotu <= 270))
                {
                    if((x * x + y * y <= r * r + TOLERANCJA) && y <= a1 * x && y >= a2 * x)
                    {
                        if(tab[i][j] >= 0)
                            tab[i][j] += stan;

                        if((tab[i][j] == -9 && tab[i][j+1] >= 0 && tab[i+1][j] >= 0 && tab[i+1][j+1] >= 0) ||
                       (tab[i][j] >= 0 && tab[i][j+1] == -9 && tab[i+1][j] >= 0 && tab[i+1][j+1] >= 0) ||
                       (tab[i][j] >= 0 && tab[i][j+1] >= 0 && tab[i+1][j] == -9 && tab[i+1][j+1] >= 0) ||
                       (tab[i][j] >= 0 && tab[i][j+1] >= 0 && tab[i+1][j] >= 0 && tab[i+1][j+1] == -9) ||

                       (tab[i][j] == -9 && tab[i][j+1] == -9 && tab[i+1][j] == -9 && tab[i+1][j+1] >= 0) ||
                       (tab[i][j] == -9 && tab[i][j+1] == -9 && tab[i+1][j] >= 0 && tab[i+1][j+1] == -9) ||
                       (tab[i][j] == -9 && tab[i][j+1] >= 0 && tab[i+1][j] == -9 && tab[i+1][j+1] == -9) ||
                       (tab[i][j] >= 0 && tab[i][j+1] == -9 && tab[i+1][j] == -9 && tab[i+1][j+1] == -9))
                       {
                           punkty[ilosc_odbic].x = j;
                           punkty[ilosc_odbic++].y = i;
                       }
                    }
                }
                else if(kat_obrotu > 90 && kat_obrotu <= 180)
                {
                    if((x * x + y * y <= r * r + TOLERANCJA) && y >= a1 * x && y >= a2 * x)
                    {
                        if(tab[i][j] >= 0)
                            tab[i][j] += stan;

                        if((tab[i][j] == -9 && tab[i][j+1] >= 0 && tab[i+1][j] >= 0 && tab[i+1][j+1] >= 0) ||
                       (tab[i][j] >= 0 && tab[i][j+1] == -9 && tab[i+1][j] >= 0 && tab[i+1][j+1] >= 0) ||
                       (tab[i][j] >= 0 && tab[i][j+1] >= 0 && tab[i+1][j] == -9 && tab[i+1][j+1] >= 0) ||
                       (tab[i][j] >= 0 && tab[i][j+1] >= 0 && tab[i+1][j] >= 0 && tab[i+1][j+1] == -9) ||

                       (tab[i][j] == -9 && tab[i][j+1] == -9 && tab[i+1][j] == -9 && tab[i+1][j+1] >= 0) ||
                       (tab[i][j] == -9 && tab[i][j+1] == -9 && tab[i+1][j] >= 0 && tab[i+1][j+1] == -9) ||
                       (tab[i][j] == -9 && tab[i][j+1] >= 0 && tab[i+1][j] == -9 && tab[i+1][j+1] == -9) ||
                       (tab[i][j] >= 0 && tab[i][j+1] == -9 && tab[i+1][j] == -9 && tab[i+1][j+1] == -9))
                       {
                           punkty[ilosc_odbic].x = j;
                           punkty[ilosc_odbic++].y = i;
                       }
                    }
                }
                else if(kat_obrotu > 270 && kat_obrotu < 360)
                {
                    if((x * x + y * y <= r * r + TOLERANCJA) && y <= a1 * x && y <= a2 * x)
                    {
                        if(tab[i][j] >= 0)
                            tab[i][j] += stan;

                        if((tab[i][j] == -9 && tab[i][j+1] >= 0 && tab[i+1][j] >= 0 && tab[i+1][j+1] >= 0) ||
                       (tab[i][j] >= 0 && tab[i][j+1] == -9 && tab[i+1][j] >= 0 && tab[i+1][j+1] >= 0) ||
                       (tab[i][j] >= 0 && tab[i][j+1] >= 0 && tab[i+1][j] == -9 && tab[i+1][j+1] >= 0) ||
                       (tab[i][j] >= 0 && tab[i][j+1] >= 0 && tab[i+1][j] >= 0 && tab[i+1][j+1] == -9) ||

                       (tab[i][j] == -9 && tab[i][j+1] == -9 && tab[i+1][j] == -9 && tab[i+1][j+1] >= 0) ||
                       (tab[i][j] == -9 && tab[i][j+1] == -9 && tab[i+1][j] >= 0 && tab[i+1][j+1] == -9) ||
                       (tab[i][j] == -9 && tab[i][j+1] >= 0 && tab[i+1][j] == -9 && tab[i+1][j+1] == -9) ||
                       (tab[i][j] >= 0 && tab[i][j+1] == -9 && tab[i+1][j] == -9 && tab[i+1][j+1] == -9))
                       {
                           punkty[ilosc_odbic].x = j;
                           punkty[ilosc_odbic++].y = i;
                       }
                    }
                }
            }
        }

        for(int i = srodek_x; (i <= srodek_x + r + TOLERANCJA) && (i < ROZMIAR_X); i++) // prawo
        {
            if(tab[srodek_y][i] == -9)
            {
                punkty[ilosc_odbic].x = i;
                punkty[ilosc_odbic].y = srodek_y;
                ilosc_odbic++;
                break;
            }
        }
        for(int i = srodek_x; (i >= srodek_x - r - TOLERANCJA) && (i > 0); i--) // lewo
        {
            if(tab[srodek_y][i] == -9)
            {
                punkty[ilosc_odbic].x = i;
                punkty[ilosc_odbic].y = srodek_y;
                ilosc_odbic++;
                break;
            }
        }
        for(int i = srodek_y; (i <= srodek_y + r + TOLERANCJA) && (i < ROZMIAR_Y); i++) // dol
        {
            if(tab[i][srodek_x] == -9)
            {
                punkty[ilosc_odbic].x = srodek_x;
                punkty[ilosc_odbic].y = i;
                ilosc_odbic++;
                break;
            }
        }
        for(int i = srodek_y; (i >= srodek_y - r - TOLERANCJA) && (i > 0); i--) // gora
        {
            if(tab[i][srodek_x] == -9)
            {
                punkty[ilosc_odbic].x = srodek_x;
                punkty[ilosc_odbic].y = i;
                ilosc_odbic++;
                break;
            }
        }

        for(int p = 0; p < ilosc_odbic; p++)
        {
            odleglosc_gora = 0;
            odleglosc_dol = 0;
            odleglosc_lewo = 0;
            odleglosc_prawo = 0;

            if(punkty[p].x > srodek_x)
                odleglosc_lewo = 2 * abs(srodek_x - punkty[p].x);
            else if(punkty[p].x < srodek_x)
                odleglosc_prawo = 2 * -abs(srodek_x - punkty[p].x);
            if(punkty[p].y > srodek_y)
                odleglosc_dol = 2 * abs(srodek_y - punkty[p].y);
            else if(punkty[p].y < srodek_y)
                odleglosc_gora= 2 * -abs(srodek_y - punkty[p].y);

            int mnoznik_x = 0, mnoznik_y = 0;
            if(odleglosc_dol != 0 || odleglosc_gora != 0)
                mnoznik_y = 1;
            if(odleglosc_prawo != 0 || odleglosc_lewo != 0)
                mnoznik_x = 1;

            for(i = (srodek_y - r - TOLERANCJA >= 0) ? srodek_y - r - TOLERANCJA : 0; (i <= srodek_y + r + TOLERANCJA) && (i < ROZMIAR_Y); i++)
            {
                x = srodek_y - i;

                for(j = (srodek_x - r - TOLERANCJA >= 0) ? srodek_x - r - TOLERANCJA : 0; (j <= srodek_x + r + TOLERANCJA) && (j < ROZMIAR_X); j++)
                {
                    y = srodek_x - j;

                    if((kat_obrotu >= 0 && kat_obrotu <= 90) || (kat_obrotu > 180 && kat_obrotu <= 270))
                    {
                        if((x * x + y * y <= r * r + TOLERANCJA) && y <= a1 * x && y >= a2 * x && tab[i][j] == -9)
                        {
                              if(j + mnoznik_x * (-(srodek_x - j)*-2 + odleglosc_prawo + odleglosc_lewo) < 0)
                              {
                                    tab[i + mnoznik_y * (- (srodek_y - i)*-2 + odleglosc_gora + odleglosc_dol)][j] += stan;
                              }
                              else if(i + mnoznik_y * (- (srodek_y - i)*-2 + odleglosc_gora + odleglosc_dol) < 0)
                              {
                                  tab[i][j + mnoznik_x * (-(srodek_x - j)*-2 + odleglosc_prawo + odleglosc_lewo)] += stan;
                              }
                              else
                              {
                                  tab[i + mnoznik_y * (- (srodek_y - i)*-2 + odleglosc_gora + odleglosc_dol)][j + mnoznik_x * (-(srodek_x - j)*-2 + odleglosc_prawo + odleglosc_lewo)] += stan;
                              }
                        }
                    }
                    else if(kat_obrotu > 90 && kat_obrotu <= 180)
                    {
                        if((x * x + y * y <= r * r + TOLERANCJA) && y >= a1 * x && y >= a2 * x && tab[i][j] == -9)
                        {
                            if(j + mnoznik_x * (-(srodek_x - j)*-2 + odleglosc_prawo + odleglosc_lewo) < 0)
                            {
                                tab[i + mnoznik_y * (- (srodek_y - i)*-2 + odleglosc_gora + odleglosc_dol)][j] += stan;
                            }
                            else if(i + mnoznik_y * (- (srodek_y - i)*-2 + odleglosc_gora + odleglosc_dol) < 0)
                            {
                                tab[i][j + mnoznik_x * (-(srodek_x - j)*-2 + odleglosc_prawo + odleglosc_lewo)] += stan;
                            }
                            else
                            {
                                tab[i + mnoznik_y * (- (srodek_y - i)*-2 + odleglosc_gora + odleglosc_dol)][j + mnoznik_x * (-(srodek_x - j)*-2 + odleglosc_prawo + odleglosc_lewo)] += stan;
                            }
                        }
                    }
                     else if(kat_obrotu > 270 && kat_obrotu < 360)
                    {
                        if((x * x + y * y <= r * r + TOLERANCJA) && y <= a1 * x && y <= a2 * x && tab[i][j] == -9)
                            {
                            if(j + mnoznik_x * (-(srodek_x - j)*-2 + odleglosc_prawo + odleglosc_lewo) < 0)
                            {
                                tab[i + mnoznik_y * (- (srodek_y - i)*-2 + odleglosc_gora + odleglosc_dol)][j] += stan;
                            }
                            else if(i + mnoznik_y * (- (srodek_y - i)*-2 + odleglosc_gora + odleglosc_dol) < 0)
                            {
                                tab[i][j + mnoznik_x * (-(srodek_x - j)*-2 + odleglosc_prawo + odleglosc_lewo)] += stan;
                            }
                            else
                            {
                                tab[i + mnoznik_y * (- (srodek_y - i)*-2 + odleglosc_gora + odleglosc_dol)][j + mnoznik_x * (-(srodek_x - j)*-2 + odleglosc_prawo + odleglosc_lewo)] += stan;
                            }
                        }
                    }
                }
            }
        }
    }
    else if(kat == 180) // dziala
    {

        r = 400;
        stan = 3;

        for(i = (srodek_y - r - TOLERANCJA >= 0) ? srodek_y - r - TOLERANCJA : 0; (i < srodek_y + r + TOLERANCJA) && (i < ROZMIAR_Y); i++)
        {
            x = srodek_y - i;

            for(j = (srodek_x - r - TOLERANCJA >= 0) ? srodek_x - r - TOLERANCJA : 0; (j < srodek_x + r + TOLERANCJA) && (j < ROZMIAR_X); j++)
            {
                y = srodek_x - j;

                if((kat_obrotu <= 90 && kat_obrotu >= 0) || (kat_obrotu > 90 && kat_obrotu <= 180))
                {
                    if((x * x + y * y <= r * r + TOLERANCJA) && (y >= a2 * x))
                    {
                        if(tab[i][j] >= 0)
                            tab[i][j] += stan;

                        if((tab[i][j] == -9 && tab[i][j+1] >= 0 && tab[i+1][j] >= 0 && tab[i+1][j+1] >= 0) ||
                       (tab[i][j] >= 0 && tab[i][j+1] == -9 && tab[i+1][j] >= 0 && tab[i+1][j+1] >= 0) ||
                       (tab[i][j] >= 0 && tab[i][j+1] >= 0 && tab[i+1][j] == -9 && tab[i+1][j+1] >= 0) ||
                       (tab[i][j] >= 0 && tab[i][j+1] >= 0 && tab[i+1][j] >= 0 && tab[i+1][j+1] == -9) ||

                       (tab[i][j] == -9 && tab[i][j+1] == -9 && tab[i+1][j] == -9 && tab[i+1][j+1] >= 0) ||
                       (tab[i][j] == -9 && tab[i][j+1] == -9 && tab[i+1][j] >= 0 && tab[i+1][j+1] == -9) ||
                       (tab[i][j] == -9 && tab[i][j+1] >= 0 && tab[i+1][j] == -9 && tab[i+1][j+1] == -9) ||
                       (tab[i][j] >= 0 && tab[i][j+1] == -9 && tab[i+1][j] == -9 && tab[i+1][j+1] == -9))
                       {
                           punkty[ilosc_odbic].x = j;
                           punkty[ilosc_odbic++].y = i;
                       }
                    }
                }
                else if((kat_obrotu >= 270 && kat_obrotu < 360) || (kat_obrotu > 180 && kat_obrotu < 270))
                {
                    if((x * x + y * y <= r * r + TOLERANCJA) && (y <= a2 * x))
                    {
                        if(tab[i][j] >= 0)
                            tab[i][j] += stan;

                        if((tab[i][j] == -9 && tab[i][j+1] >= 0 && tab[i+1][j] >= 0 && tab[i+1][j+1] >= 0) ||
                       (tab[i][j] >= 0 && tab[i][j+1] == -9 && tab[i+1][j] >= 0 && tab[i+1][j+1] >= 0) ||
                       (tab[i][j] >= 0 && tab[i][j+1] >= 0 && tab[i+1][j] == -9 && tab[i+1][j+1] >= 0) ||
                       (tab[i][j] >= 0 && tab[i][j+1] >= 0 && tab[i+1][j] >= 0 && tab[i+1][j+1] == -9) ||

                       (tab[i][j] == -9 && tab[i][j+1] == -9 && tab[i+1][j] == -9 && tab[i+1][j+1] >= 0) ||
                       (tab[i][j] == -9 && tab[i][j+1] == -9 && tab[i+1][j] >= 0 && tab[i+1][j+1] == -9) ||
                       (tab[i][j] == -9 && tab[i][j+1] >= 0 && tab[i+1][j] == -9 && tab[i+1][j+1] == -9) ||
                       (tab[i][j] >= 0 && tab[i][j+1] == -9 && tab[i+1][j] == -9 && tab[i+1][j+1] == -9))
                       {
                           punkty[ilosc_odbic].x = j;
                           punkty[ilosc_odbic++].y = i;
                       }
                    }
                }
            }
        }

        for(int i = srodek_x; (i <= srodek_x + r + TOLERANCJA) && (i < ROZMIAR_X); i++) // prawo
        {
            if(tab[srodek_y][i] == -9)
            {
                punkty[ilosc_odbic].x = i;
                punkty[ilosc_odbic].y = srodek_y;
                ilosc_odbic++;
                break;
            }
        }
        for(int i = srodek_x; (i >= srodek_x - r - TOLERANCJA) && (i > 0); i--) // lewo
        {
            if(tab[srodek_y][i] == -9)
            {
                punkty[ilosc_odbic].x = i;
                punkty[ilosc_odbic].y = srodek_y;
                ilosc_odbic++;
                break;
            }
        }
        for(int i = srodek_y; (i <= srodek_y + r + TOLERANCJA) && (i < ROZMIAR_Y); i++) // dol
        {
            if(tab[i][srodek_x] == -9)
            {
                punkty[ilosc_odbic].x = srodek_x;
                punkty[ilosc_odbic].y = i;
                ilosc_odbic++;
                break;
            }
        }
        for(int i = srodek_y; (i >= srodek_y - r - TOLERANCJA) && (i > 0); i--) // gora
        {
            if(tab[i][srodek_x] == -9)
            {
                punkty[ilosc_odbic].x = srodek_x;
                punkty[ilosc_odbic].y = i;
                ilosc_odbic++;
                break;
            }
        }

        for(int p = 0; p < ilosc_odbic; p++)
        {
            odleglosc_gora = 0;
            odleglosc_dol = 0;
            odleglosc_lewo = 0;
            odleglosc_prawo = 0;

            if(punkty[p].x > srodek_x)
                odleglosc_lewo = 2 * abs(srodek_x - punkty[p].x);
            else if(punkty[p].x < srodek_x)
                odleglosc_prawo = 2 * -abs(srodek_x - punkty[p].x);
            if(punkty[p].y > srodek_y)
                odleglosc_dol = 2 * abs(srodek_y - punkty[p].y);
            else if(punkty[p].y < srodek_y)
                odleglosc_gora= 2 * -abs(srodek_y - punkty[p].y);

            int mnoznik_x = 0, mnoznik_y = 0;
            if(odleglosc_dol != 0 || odleglosc_gora != 0)
                mnoznik_y = 1;
            if(odleglosc_prawo != 0 || odleglosc_lewo != 0)
                mnoznik_x = 1;

            for(i = (srodek_y - r - TOLERANCJA >= 0) ? srodek_y - r - TOLERANCJA : 0; (i <= srodek_y + r + TOLERANCJA) && (i < ROZMIAR_Y); i++)
            {
                x = srodek_y - i;

                for(j = (srodek_x - r - TOLERANCJA >= 0) ? srodek_x - r - TOLERANCJA : 0; (j <= srodek_x + r + TOLERANCJA) && (j < ROZMIAR_X); j++)
                {
                    y = srodek_x - j;

                    if((kat_obrotu <= 90 && kat_obrotu >= 0) || (kat_obrotu > 90 && kat_obrotu <= 180))
                    {
                        if((x * x + y * y <= r * r + TOLERANCJA) && (y >= a2 * x) && tab[i][j] == -9)
                        {
                              if(j + mnoznik_x * (-(srodek_x - j)*-2 + odleglosc_prawo + odleglosc_lewo) < 0)
                              {
                                    tab[i + mnoznik_y * (- (srodek_y - i)*-2 + odleglosc_gora + odleglosc_dol)][j] += stan;
                              }
                              else if(i + mnoznik_y * (- (srodek_y - i)*-2 + odleglosc_gora + odleglosc_dol) < 0)
                              {
                                  tab[i][j + mnoznik_x * (-(srodek_x - j)*-2 + odleglosc_prawo + odleglosc_lewo)] += stan;
                              }
                              else
                              {
                                  tab[i + mnoznik_y * (- (srodek_y - i)*-2 + odleglosc_gora + odleglosc_dol)][j + mnoznik_x * (-(srodek_x - j)*-2 + odleglosc_prawo + odleglosc_lewo)] += stan;
                              }
                        }
                    }
                    else if((kat_obrotu >= 270 && kat_obrotu < 360) || (kat_obrotu > 180 && kat_obrotu < 270) && tab[i][j] == -9)
                    {
                        if((x * x + y * y <= r * r + TOLERANCJA) && (y <= a2 * x) && tab[i][j] == -9)
                        {
                            if(j + mnoznik_x * (-(srodek_x - j)*-2 + odleglosc_prawo + odleglosc_lewo) < 0)
                            {
                                tab[i + mnoznik_y * (- (srodek_y - i)*-2 + odleglosc_gora + odleglosc_dol)][j] += stan;
                            }
                            else if(i + mnoznik_y * (- (srodek_y - i)*-2 + odleglosc_gora + odleglosc_dol) < 0)
                            {
                                tab[i][j + mnoznik_x * (-(srodek_x - j)*-2 + odleglosc_prawo + odleglosc_lewo)] += stan;
                            }
                            else
                            {
                                tab[i + mnoznik_y * (- (srodek_y - i)*-2 + odleglosc_gora + odleglosc_dol)][j + mnoznik_x * (-(srodek_x - j)*-2 + odleglosc_prawo + odleglosc_lewo)] += stan;
                            }
                        }
                    }
                }
            }
        }
    }
    else if(kat == 270)
    {
        r = 300;
        stan = 2;

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

        for(i = (srodek_y - r - TOLERANCJA >= 0) ? srodek_y - r - TOLERANCJA : 0; (i < srodek_y + r + TOLERANCJA) && (i < ROZMIAR_Y); i++)
        {
            x = srodek_y - i;

            for(j = (srodek_x - r - TOLERANCJA >= 0) ? srodek_x - r - TOLERANCJA : 0; (j < srodek_x + r + TOLERANCJA) && (j < ROZMIAR_X); j++)
            {
                y = srodek_x - j;

                if((kat_obrotu >= 0 && kat_obrotu <= 90) || (kat_obrotu > 180 && kat_obrotu <= 270))
                {
                    if((x * x + y * y <= r * r + TOLERANCJA) && (y >= a1 * x || y <= a2 * x))
                    {
                        if(tab[i][j] >= 0)
                            tab[i][j] += stan;

                        if((tab[i][j] == -9 && tab[i][j+1] >= 0 && tab[i+1][j] >= 0 && tab[i+1][j+1] >= 0) ||
                       (tab[i][j] >= 0 && tab[i][j+1] == -9 && tab[i+1][j] >= 0 && tab[i+1][j+1] >= 0) ||
                       (tab[i][j] >= 0 && tab[i][j+1] >= 0 && tab[i+1][j] == -9 && tab[i+1][j+1] >= 0) ||
                       (tab[i][j] >= 0 && tab[i][j+1] >= 0 && tab[i+1][j] >= 0 && tab[i+1][j+1] == -9) ||

                       (tab[i][j] == -9 && tab[i][j+1] == -9 && tab[i+1][j] == -9 && tab[i+1][j+1] >= 0) ||
                       (tab[i][j] == -9 && tab[i][j+1] == -9 && tab[i+1][j] >= 0 && tab[i+1][j+1] == -9) ||
                       (tab[i][j] == -9 && tab[i][j+1] >= 0 && tab[i+1][j] == -9 && tab[i+1][j+1] == -9) ||
                       (tab[i][j] >= 0 && tab[i][j+1] == -9 && tab[i+1][j] == -9 && tab[i+1][j+1] == -9))
                       {
                           punkty[ilosc_odbic].x = j;
                           punkty[ilosc_odbic++].y = i;
                       }
                    }
                }
                else if(kat_obrotu > 90 && kat_obrotu <= 180)
                {
                    if((x * x + y * y <= r * r + TOLERANCJA) && (y <= a1 * x || y <= a2 * x))
                    {
                        if(tab[i][j] >= 0)
                            tab[i][j] += stan;

                        if((tab[i][j] == -9 && tab[i][j+1] >= 0 && tab[i+1][j] >= 0 && tab[i+1][j+1] >= 0) ||
                       (tab[i][j] >= 0 && tab[i][j+1] == -9 && tab[i+1][j] >= 0 && tab[i+1][j+1] >= 0) ||
                       (tab[i][j] >= 0 && tab[i][j+1] >= 0 && tab[i+1][j] == -9 && tab[i+1][j+1] >= 0) ||
                       (tab[i][j] >= 0 && tab[i][j+1] >= 0 && tab[i+1][j] >= 0 && tab[i+1][j+1] == -9) ||

                       (tab[i][j] == -9 && tab[i][j+1] == -9 && tab[i+1][j] == -9 && tab[i+1][j+1] >= 0) ||
                       (tab[i][j] == -9 && tab[i][j+1] == -9 && tab[i+1][j] >= 0 && tab[i+1][j+1] == -9) ||
                       (tab[i][j] == -9 && tab[i][j+1] >= 0 && tab[i+1][j] == -9 && tab[i+1][j+1] == -9) ||
                       (tab[i][j] >= 0 && tab[i][j+1] == -9 && tab[i+1][j] == -9 && tab[i+1][j+1] == -9))
                       {
                           punkty[ilosc_odbic].x = j;
                           punkty[ilosc_odbic++].y = i;
                       }
                    }
                }
                else if(kat_obrotu > 270 && kat_obrotu < 360)
                {
                    if((x * x + y * y <= r * r + TOLERANCJA) && (y >= a1 * x || y >= a2 * x))
                    {
                        if(tab[i][j] >= 0)
                            tab[i][j] += stan;

                        if((tab[i][j] >= 0 && tab[i][j+1] == -9 && tab[i+1][j] >= 0 && tab[i+1][j+1] >= 0) ||
                       (tab[i][j] >= 0 && tab[i][j+1] >= 0 && tab[i+1][j] == -9 && tab[i+1][j+1] >= 0) ||
                       (tab[i][j] >= 0 && tab[i][j+1] >= 0 && tab[i+1][j] >= 0 && tab[i+1][j+1] == -9) ||

                       (tab[i][j] == -9 && tab[i][j+1] == -9 && tab[i+1][j] == -9 && tab[i+1][j+1] >= 0) ||
                       (tab[i][j] == -9 && tab[i][j+1] == -9 && tab[i+1][j] >= 0 && tab[i+1][j+1] == -9) ||
                       (tab[i][j] == -9 && tab[i][j+1] >= 0 && tab[i+1][j] == -9 && tab[i+1][j+1] == -9) ||
                       (tab[i][j] >= 0 && tab[i][j+1] == -9 && tab[i+1][j] == -9 && tab[i+1][j+1] == -9))
                       {
                           punkty[ilosc_odbic].x = j;
                           punkty[ilosc_odbic++].y = i;
                       }
                    }
                }
            }
        }

        for(int i = srodek_x; (i <= srodek_x + r + TOLERANCJA) && (i < ROZMIAR_X); i++) // prawo
        {
            if(tab[srodek_y][i] == -9)
            {
                punkty[ilosc_odbic].x = i;
                punkty[ilosc_odbic].y = srodek_y;
                ilosc_odbic++;
                break;
            }
        }
        for(int i = srodek_x; (i >= srodek_x - r - TOLERANCJA) && (i > 0); i--) // lewo
        {
            if(tab[srodek_y][i] == -9)
            {
                punkty[ilosc_odbic].x = i;
                punkty[ilosc_odbic].y = srodek_y;
                ilosc_odbic++;
                break;
            }
        }
        for(int i = srodek_y; (i <= srodek_y + r + TOLERANCJA) && (i < ROZMIAR_Y); i++) // dol
        {
            if(tab[i][srodek_x] == -9)
            {
                punkty[ilosc_odbic].x = srodek_x;
                punkty[ilosc_odbic].y = i;
                ilosc_odbic++;
                break;
            }
        }
        for(int i = srodek_y; (i >= srodek_y - r - TOLERANCJA) && (i > 0); i--) // gora
        {
            if(tab[i][srodek_x] == -9)
            {
                punkty[ilosc_odbic].x = srodek_x;
                punkty[ilosc_odbic].y = i;
                ilosc_odbic++;
                break;
            }
        }

        for(int p = 0; p < ilosc_odbic; p++)
        {
            odleglosc_gora = 0;
            odleglosc_dol = 0;
            odleglosc_lewo = 0;
            odleglosc_prawo = 0;

            if(punkty[p].x > srodek_x)
                odleglosc_lewo = 2 * abs(srodek_x - punkty[p].x);
            else if(punkty[p].x < srodek_x)
                odleglosc_prawo = 2 * -abs(srodek_x - punkty[p].x);
            if(punkty[p].y > srodek_y)
                odleglosc_dol = 2 * abs(srodek_y - punkty[p].y);
            else if(punkty[p].y < srodek_y)
                odleglosc_gora= 2 * -abs(srodek_y - punkty[p].y);
            int mnoznik_x = 0, mnoznik_y = 0;
            if(odleglosc_dol != 0 || odleglosc_gora != 0)
                mnoznik_y = 1;
            if(odleglosc_prawo != 0 || odleglosc_lewo != 0)
                mnoznik_x = 1;

            for(i = (srodek_y - r - TOLERANCJA >= 0) ? srodek_y - r - TOLERANCJA : 0; (i <= srodek_y + r + TOLERANCJA) && (i < ROZMIAR_Y); i++)
            {
                x = srodek_y - i;

                for(j = (srodek_x - r - TOLERANCJA >= 0) ? srodek_x - r - TOLERANCJA : 0; (j <= srodek_x + r + TOLERANCJA) && (j < ROZMIAR_X); j++)
                {
                    y = srodek_x - j;

                    if((kat_obrotu >= 0 && kat_obrotu <= 90) || (kat_obrotu > 180 && kat_obrotu <= 270))
                    {
                        if(x * x + y * y <= r * r + TOLERANCJA && (y >= a1 * x || y <= a2 * x) && tab[i][j] == -9)
                        {
                              if(j + mnoznik_x * (-(srodek_x - j)*-2 + odleglosc_prawo + odleglosc_lewo) < 0)
                              {
                                    tab[i + mnoznik_y * (- (srodek_y - i)*-2 + odleglosc_gora + odleglosc_dol)][j] += stan;
                              }
                              else if(i + mnoznik_y * (- (srodek_y - i)*-2 + odleglosc_gora + odleglosc_dol) < 0)
                              {
                                  tab[i][j + mnoznik_x * (-(srodek_x - j)*-2 + odleglosc_prawo + odleglosc_lewo)] += stan;
                              }
                              else
                              {
                                  tab[i + mnoznik_y * (- (srodek_y - i)*-2 + odleglosc_gora + odleglosc_dol)][j + mnoznik_x * (-(srodek_x - j)*-2 + odleglosc_prawo + odleglosc_lewo)] += stan;
                              }
                        }
                    }
                    else if(kat_obrotu > 90 && kat_obrotu <= 180)
                    {
                        if((x * x + y * y <= r * r + TOLERANCJA) && (y <= a1 * x || y <= a2 * x) && tab[i][j] == -9)
                        {
                            if(j + mnoznik_x * (-(srodek_x - j)*-2 + odleglosc_prawo + odleglosc_lewo) < 0)
                            {
                                tab[i + mnoznik_y * (- (srodek_y - i)*-2 + odleglosc_gora + odleglosc_dol)][j] += stan;
                            }
                            else if(i + mnoznik_y * (- (srodek_y - i)*-2 + odleglosc_gora + odleglosc_dol) < 0)
                            {
                                tab[i][j + mnoznik_x * (-(srodek_x - j)*-2 + odleglosc_prawo + odleglosc_lewo)] += stan;
                            }
                            else
                            {
                                tab[i + mnoznik_y * (- (srodek_y - i)*-2 + odleglosc_gora + odleglosc_dol)][j + mnoznik_x * (-(srodek_x - j)*-2 + odleglosc_prawo + odleglosc_lewo)] += stan;
                            }
                        }
                    }
                    else if(kat_obrotu > 270 && kat_obrotu < 360)
                    {
                        if((x * x + y * y <= r * r + TOLERANCJA) && (y >= a1 * x || y >= a2 * x) && tab[i][j] == -9)
                        {
                            if(j + mnoznik_x * (-(srodek_x - j)*-2 + odleglosc_prawo + odleglosc_lewo) < 0)
                            {
                                tab[i + mnoznik_y * (- (srodek_y - i)*-2 + odleglosc_gora + odleglosc_dol)][j] += stan;
                            }
                            else if(i + mnoznik_y * (- (srodek_y - i)*-2 + odleglosc_gora + odleglosc_dol) < 0)
                            {
                                tab[i][j + mnoznik_x * (-(srodek_x - j)*-2 + odleglosc_prawo + odleglosc_lewo)] += stan;
                            }
                            else
                            {
                                tab[i + mnoznik_y * (- (srodek_y - i)*-2 + odleglosc_gora + odleglosc_dol)][j + mnoznik_x * (-(srodek_x - j)*-2 + odleglosc_prawo + odleglosc_lewo)] += stan;
                            }
                        }
                    }
                }
            }
        }
    }
    else if(kat == 360)
    {
        r = 200;
        stan = 1;

        for(i = (srodek_y - r - TOLERANCJA >= 0) ? srodek_y - r - TOLERANCJA : 0; (i <= srodek_y + r + TOLERANCJA) && (i < ROZMIAR_Y); i++)
        {
            x = srodek_y - i;

            for(j = (srodek_x - r - TOLERANCJA >= 0) ? srodek_x - r - TOLERANCJA : 0; (j <= srodek_x + r + TOLERANCJA) && (j < ROZMIAR_X); j++)
            {
                y = srodek_x - j;

                if(x * x + y * y <= r * r + TOLERANCJA)
                {
                    if(tab[i][j] >= 0)
                        tab[i][j] += stan;

                    if((tab[i][j] == -9 && tab[i][j+1] >= 0 && tab[i+1][j] >= 0 && tab[i+1][j+1] >= 0) ||
                   (tab[i][j] >= 0 && tab[i][j+1] == -9 && tab[i+1][j] >= 0 && tab[i+1][j+1] >= 0) ||
                   (tab[i][j] >= 0 && tab[i][j+1] >= 0 && tab[i+1][j] == -9 && tab[i+1][j+1] >= 0) ||
                   (tab[i][j] >= 0 && tab[i][j+1] >= 0 && tab[i+1][j] >= 0 && tab[i+1][j+1] == -9) ||

                   (tab[i][j] == -9 && tab[i][j+1] == -9 && tab[i+1][j] == -9 && tab[i+1][j+1] >= 0) ||
                   (tab[i][j] == -9 && tab[i][j+1] == -9 && tab[i+1][j] >= 0 && tab[i+1][j+1] == -9) ||
                   (tab[i][j] == -9 && tab[i][j+1] >= 0 && tab[i+1][j] == -9 && tab[i+1][j+1] == -9) ||
                   (tab[i][j] >= 0 && tab[i][j+1] == -9 && tab[i+1][j] == -9 && tab[i+1][j+1] == -9))
                   {
                       punkty[ilosc_odbic].x = j;
                       punkty[ilosc_odbic++].y = i;
                   }
                }
            }
       }

       for(int i = srodek_x; (i <= srodek_x + r + TOLERANCJA) && (i < ROZMIAR_X); i++) // prawo
        {
            if(tab[srodek_y][i] == -9)
            {
                punkty[ilosc_odbic].x = i;
                punkty[ilosc_odbic].y = srodek_y;
                ilosc_odbic++;
                break;
            }
        }
        for(int i = srodek_x; (i >= srodek_x - r - TOLERANCJA) && (i > 0); i--) // lewo
        {
            if(tab[srodek_y][i] == -9)
            {
                punkty[ilosc_odbic].x = i;
                punkty[ilosc_odbic].y = srodek_y;
                ilosc_odbic++;
                break;
            }
        }
        for(int i = srodek_y; (i <= srodek_y + r + TOLERANCJA) && (i < ROZMIAR_Y); i++) // dol
        {
            if(tab[i][srodek_x] == -9)
            {
                punkty[ilosc_odbic].x = srodek_x;
                punkty[ilosc_odbic].y = i;
                ilosc_odbic++;
                break;
            }
        }
        for(int i = srodek_y; (i >= srodek_y - r - TOLERANCJA) && (i > 0); i--) // gora
        {
            if(tab[i][srodek_x] == -9)
            {
                punkty[ilosc_odbic].x = srodek_x;
                punkty[ilosc_odbic].y = i;
                ilosc_odbic++;
                break;
            }
        }

        for(int p = 0; p < ilosc_odbic; p++)
        {
            if(punkty[p].x > srodek_x)
                odleglosc_lewo = 2 * abs(srodek_x - punkty[p].x);
            else if(punkty[p].x < srodek_x)
                odleglosc_prawo = 2 * -abs(srodek_x - punkty[p].x);
            if(punkty[p].y > srodek_y)
                odleglosc_dol = 2 * abs(srodek_y - punkty[p].y);
            else if(punkty[p].y < srodek_y)
                odleglosc_gora= 2 * -abs(srodek_y - punkty[p].y);

            int mnoznik_x = 0, mnoznik_y = 0;
            if(odleglosc_dol != 0 || odleglosc_gora != 0)
                mnoznik_y = 1;
            if(odleglosc_prawo != 0 || odleglosc_lewo != 0)
                mnoznik_x = 1;

            for(i = (srodek_y - r - TOLERANCJA >= 0) ? srodek_y - r - TOLERANCJA : 0; (i <= srodek_y + r + TOLERANCJA) && (i < ROZMIAR_Y); i++)
            {
                x = srodek_y - i;

                for(j = (srodek_x - r - TOLERANCJA >= 0) ? srodek_x - r - TOLERANCJA : 0; (j <= srodek_x + r + TOLERANCJA) && (j < ROZMIAR_X); j++)
                {
                    y = srodek_x - j;

                    if(x * x + y * y <= r * r + TOLERANCJA && tab[i][j] == -9)
                    {
                          if(j + mnoznik_x * (-(srodek_x - j)*-2 + odleglosc_prawo + odleglosc_lewo) < 0)
                          {
                                tab[i + mnoznik_y * (- (srodek_y - i)*-2 + odleglosc_gora + odleglosc_dol)][j] += stan;
                          }
                          else if(i + mnoznik_y * (- (srodek_y - i)*-2 + odleglosc_gora + odleglosc_dol) < 0)
                          {
                              tab[i][j + mnoznik_x * (-(srodek_x - j)*-2 + odleglosc_prawo + odleglosc_lewo)] += stan;
                          }
                          else
                          {
                              tab[i + mnoznik_y * (- (srodek_y - i)*-2 + odleglosc_gora + odleglosc_dol)][j + mnoznik_x * (-(srodek_x - j)*-2 + odleglosc_prawo + odleglosc_lewo)] += stan;
                          }
                    }
                }
            }
        }
    }
}
