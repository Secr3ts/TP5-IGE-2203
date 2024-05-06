//
// Created by Aloïs Fournier on 06/05/2024.
//
#include "ex1-pointeurs.h"

void ex1pointeurs()
{
    float f = (float)(10.0);
    float *pf;

    printf("f: %f\n", f);

    pf = &f;

    printf("f: %f\n", *pf);

    *pf = (float)(999.5);

    printf("f: %f\nf: %f\n", f, *pf);
}