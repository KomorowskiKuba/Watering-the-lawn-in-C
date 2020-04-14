#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **args)
{
    srand(time(NULL));
    char tab[40][80];
    char *nazwa_pliku = (argc > 1) ? args[1] : "Mapa.txt";
    int ilosc_ksztaltow = (argc > 2) ? atoi(args[2]) : 7;
    int max_rozmiar = (argc > 3) ? atoi(args[3]) : 7;
    FILE * out = fopen(nazwa_pliku, "w");

    for(int i = 0; i < 80; i++)
        tab[0][i] = '*';

    for(int i = 1; i < 39; i++)
    {
        tab[i][0] = '*';
        for(int j = 1; j < 79; j++)
        {
            tab[i][j] = '#';
        }
        tab[i][79] = '*';
    }

    for(int i = 0; i < 80; i++)
        tab[39][i] = '*';

    for(int i = 0; i < ilosc_ksztaltow; i++)
    {
        int kwadrat_czy_prostokat = rand()%2;
        if(kwadrat_czy_prostokat == 0) // kwadrat
        {
            int wielkosc = rand()%5 + 1;
            int x = rand()%78 + 1;
            int y = rand()%38 + 1;
            for(int j = y; j < (y + wielkosc) && j < 39; j++)
            {
                for(int k = x; k < (x + wielkosc) && k < 79; k++)
                    tab[j][k] = '*';
            }
        }
        else // prostokat
        {
            int wielkosc_x = rand()%max_rozmiar + 1;
            int wielkosc_y = rand()%max_rozmiar + 1;
            int x = rand()%78 + 1;
            int y = rand()%38 + 1;
            for(int j = y; j < (y + wielkosc_y) && j < 39; j++)
            {
                for(int k = x; k < (x + wielkosc_x) && k < 79; k++)
                    tab[j][k] = '*';
            }
        }
    }

    for(int i = 0; i < 40; i++)
    {
        for(int j = 0; j < 80; j++)
        {
            fprintf(out, "%c", tab[i][j]);
        }
        fprintf(out, "%c", '\n');
    }
    return 0;
}
