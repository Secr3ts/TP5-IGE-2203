//
// Created by Aloïs Fournier on 06/05/2024.
//
#include <float.h>
#include <stdlib.h>
#include "ex2-min.h"

int fcomp(const void* p1, const void* p2)
{
   float f1 = *(const float*)p1;
   float f2 = *(const float*)p2;

   return f1 - f2;
}

float Min3Float(float x1, float x2, float x3)
{
    float xs[3] = { x1, x2, x3 };

    qsort(xs, 3, sizeof(float), fcomp);

    return xs[0];
}

void ex2min()
{
    float x1 = (float)(10.0);
    float x2 = (float)(45.90);
    float x3 = (float)(1999.0);
    float res;

    printf("Entrez x1: \n>");
    scanf("%f", &x1);
    printf("Entrez x2: \n>");
    scanf("%f", &x2);
    printf("Entrez x3: \n>");
    scanf("%f", &x3);

    res = Min3Float(x1, x2, x3);

    printf("res: %f\n", res);
}