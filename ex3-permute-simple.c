//
// Created by Aloïs Fournier on 06/05/2024.
//

#include "ex3-permute-simple.h"
#include <stdio.h>

void permute(int a, int b)
{
    printf("1. a: %d\nb: %d\n", a, b);
    int temp = a;
    a = b;
    b = temp;
    printf("2. a: %d\nb: %d\n", a, b);
}

void ex3permutesimple()
{
    int x = 10;
    int y = 999;
    printf("x = %d\ny = %d\n",x ,y);
    permute(x, y);
    printf("x = %d\ny = %d\n",x ,y);
}