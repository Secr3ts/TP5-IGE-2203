//
// Created by Aloïs Fournier on 06/05/2024.
//

#include "ex5-tableau.h"
#include <stdio.h>
#include <string.h>

void modifystep(int (*tab)[100], int step, int value) {
    for (int i = 0; i < sizeof(*tab)/sizeof(int); i += step)
    {
        (*tab)[i] = value;
    }
}

void ex5tableau() {
    int tab[100];

    for (int i = 0; i < sizeof(tab)/sizeof(int); i++)
    {
        tab[i] = i;
    }

    printf("Tableau Originel: \n");

    for (int i = 0; i < sizeof(tab)/sizeof(int); i++)
    {
        printf("tab[%d] = %d\n", i, tab[i]);
    }

    int (*ptab)[100] = &tab;

    modifystep(ptab, 2, 0);

    printf("Tableau modifié avec pas de 2: \n");

    for (int i = 0; i < sizeof(tab)/sizeof(int); i++)
    {
        printf("tab[%d] = %d\n", i, tab[i]);
    }

    modifystep(ptab, 3, 0);

    printf("Tableau modifié avec pas de 3: \n");
    for (int i = 0; i < sizeof(tab)/sizeof(int); i++)
    {
        printf("tab[%d] = %d\n", i, tab[i]);
    }

    modifystep(ptab, 5, 0);

    printf("Tableau modifié avec pas de 5: \n");
    for (int i = 0; i < sizeof(tab)/sizeof(int); i++)
    {
        printf("tab[%d] = %d\n", i, tab[i]);
    }
}