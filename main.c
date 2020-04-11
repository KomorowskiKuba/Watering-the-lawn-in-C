#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "okrag.h"
#include "rysowanie.h"
#include "kolka.h"
#include "krawedzie.h"
#include "rogi.h"

int tab[ROZMIAR_Y][ROZMIAR_X] = {{0}};

void informacje()
{
    printf("Uzycie programu: \n");
    printf("./a.out(Nazwa pliku wyjsciowego) -m nazwa_pliku_wejsciowego -c ilosc_cykli(z zakresu 1 - 100, domyslnie 1) -h nazwa_pliku_wyjscia_heatmapy(w formacie .ppm, domyslnie Heatmapa.ppm) -z nazwa_pliku_wyjscia_wspolrzednych(domyslnie Wspolrzedne.txt\n");
}

int main(int argc, char *argv[])
{
    int opt, ilosc_cykli = 1, errorlevel = -1;
    int flaga1 = 0, flaga2 = 0, flaga3 = 0, flaga4 = 0;
    char *nazwa_pliku_wejsciowego, *nazwa_pliku_wyjscia_wspolrzednych, *nazwa_pliku_wyjscia_heatmapy;
    FILE *in, *out_hmapa, *out_zraszacze;

    while((opt = getopt(argc, argv, ":m:c:h:z:")) != -1)
    {
        switch(opt)
        {
            case 'm': // Nazwa pliku wejsciowego
            {

                flaga1 = 1;
                nazwa_pliku_wejsciowego = optarg;
                break;
            }
            case 'c': // Ilosc cykli
            {
                flaga2 = 1;
                //if(isdigit(optarg))
                    ilosc_cykli = atoi(optarg);
                //else
                //{
                    //fprintf(stderr, "Format zmiennej jest nieprawidlowy!");
                    //return errorlevel--;
                //}
                break;
            }
            case 'h': // Nazwa pliku heatmapy
            {
                flaga3 = 1;
                nazwa_pliku_wyjscia_heatmapy = optarg;
                break;
            }
            case 'z': // Nazwa pliku ze wspolrzednymi
            {
                flaga4 = 1;
                nazwa_pliku_wyjscia_wspolrzednych = optarg;
                break;
            }
        }
    }

    if(flaga1 == 0)
    {
        fprintf(stderr, "Nie podano nazwy pliku wejsciowego!\n");
        informacje();
        return errorlevel--;
    }
    else if(flaga1 == 1)
    {
        if((in=fopen(nazwa_pliku_wejsciowego, "r")) == NULL)
        {
            fprintf(stderr, "Nie mozna otworzyc pliku pliku %s!\n", nazwa_pliku_wejsciowego);
            return errorlevel--;
        }
    }

    if(flaga2 == 1)
    {
        if(ilosc_cykli > 100 || ilosc_cykli <= 0)
        {
            fprintf(stderr, "Ilosc cykli musi byc z zakresu 1 - 100!\n", nazwa_pliku_wejsciowego);
            informacje();
            return ilosc_cykli;
        }
    }

    if(flaga3 == 0)
    {
        nazwa_pliku_wyjscia_heatmapy = "Heatmapa.ppm";
        flaga3 = 1;
    }
    if(flaga3 == 1)
    {
        if((out_hmapa=fopen(nazwa_pliku_wyjscia_heatmapy, "wb")) == NULL)
        {
            fprintf(stderr, "Nie mozna otworzyc pliku pliku %s!\n", nazwa_pliku_wejsciowego);
            return errorlevel--;
        }
    }

    if(flaga4 == 0)
    {
        nazwa_pliku_wyjscia_wspolrzednych = "Wspolrzedne.txt";
        flaga4 = 1;
    }
    if(flaga4 == 1)
    {
        if((out_zraszacze=fopen(nazwa_pliku_wyjscia_wspolrzednych, "w")) == NULL)
        {
            fprintf(stderr, "Nie mozna otworzyc pliku pliku %s!\n", nazwa_pliku_wejsciowego);
            return errorlevel--;
        }
    }

    //printf("%s, %d, %s, %s\n", nazwa_pliku_wejsciowego, ilosc_cykli, nazwa_pliku_wyjscia_heatmapy, nazwa_pliku_wyjscia_wspolrzednych);

    int x,y = 0;
//    indx = 0;

    for(x = 0; x < 40; x++)
    {
        for(y = 0; y < 81; y++)
        {
            char c = getc(in);
            int k,l;

            if( c == '*')
            {
                for(k = 100*x; k < 100*(x+1); k++)
                {
                    for(l = 100*y; l < 100*(y+1); l++)
                    {
                        tab[k][l] = -999;
                    }
                }
    	    }
            else if( c == '#')
            {
                for(k=100*x; k < 100*(x+1); k++)
                {
                    for(l=100*y; l < 100*(y+1); l++)
                    {
                        tab[k][l] = 0;
                    }
                }
            }
            else if( c == '\n')
            {
            }
            else
            {
                fprintf(stderr, "W kolumnie: %5d, wierszu: %5d podano zly znak!", x, y);
                return errorlevel--;
            }
        }
    }

    double test = 0.5;
    int p_x = 300;
    int p_y = 300;

    wypelnij_rogi(tab, in, nazwa_pliku_wejsciowego);
    wypelnij_krawedzie(tab, in, nazwa_pliku_wejsciowego);
    wypelnij360(tab, p_x, p_y, test);

    if(ilosc_cykli > 1 && ilosc_cykli <= 100)
        przemnoz_przez_czas(tab, ilosc_cykli);

    rysuj_heatmape(tab, out_hmapa, nazwa_pliku_wyjscia_heatmapy);

    //fprintf(out_zraszacze, "Polozenie x, polozenie y, kat, kat obrotu\n");

    //for(int i = 0; i < indx; i++)
       // fprintf(out_zraszacze, ("%7d,%12d, %7d,%7d,\n"), tab_okregow[i].x, tab_okregow[i].y, tab_okregow[i].kat, tab_okregow[i].kat_obrotu);

    fclose(in);
    fclose(out_hmapa);
    fclose(out_zraszacze);

    return 0;
}
