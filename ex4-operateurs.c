//
// Created by Aloïs Fournier on 06/05/2024.
//

#include <sys/types.h>
#include <stdio.h>
#include "ex4-operateurs.h"

void ex4operateurs()
{
    uint x;
    uint masque;
    uint res1;
    uint res2;
    uint res3;

    x = 0x0E2C;

    printf("x_d: %u\nx_b: 0000 1110 0010 1100\n", x);

    // 1111 1111 0000 0000 = 0xFF00

    masque = 0xFF00;

    // 0000 1110 0010 1100 &
    // 1111 1111 0000 0000
    // 0000 1110 0000 0000 = 0xE00 = 3584 ?
    res1 = x & masque;

    printf("res1_d: %u\nres1_x: 0x%X\n", res1, res1);

    res2 = res1 >> 8;

    printf("res2_d, %u\nres2_x: 0x%X\n", res2, res2);

    x = 1600;

    res3 = x >> 2; // division par 4

    printf("res3_d: %d\nres3_x: %x", res3, res3);

    displayBinary(res1);
    displayBinary(res2);
    displayBinary(res3);
}

void displayBinary(ushort b)
{
    uint mask = 0b1000000000000000;

    for (int i = 0; i < 16; i++)
    {
        if (b & mask)
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
        mask >>= 1;
    }
    printf("\n");
}