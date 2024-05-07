### Aloïs Fournier

# TP5 IGI-2203

## Exercice 1

1. `float f = 10.0;`
2. `int *pf;`
3. On affiche f, on constate que ca affiche `10.000000`
4. `pf = &f;`
5. on affiche en utilisant %d et *pf. On retrouve bien la valeur de f.
6. On modifie la valeur de f en utilisant `*pf = 999.5`
7. On affiche les deux, on retrouve bien la valeur demandée dans la question précédente.

### Code
```
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
```

### Output
```
f: 10.000000
f: 10.000000
f: 999.500000
f: 999.500000
```

## Exercice 2

1. La fonction Min3Float() utilise la fonction qsort() pour trier un tableau que je crée à partir des 3 arguments. Ceci n'est peut être pas la méthode la plus efficace.
2. 1. On déclare et initialise les 3 variables et on déclare une variable res.
   2. On utilise scanf() pour récuprer l'input de l'utilisateur.
   3. En testant mon programme je constate que ça retourne bel et bien le float minimum des 3 arguments.

### Code
```
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
```

### Output
```
Entrez x1: 
>1.431541
Entrez x2: 
>2.43151
Entrez x3: 
>0.1
res: 0.100000
```

## Exercice 3
1. Cette fonction ne nous permettra pas de modifier directement les variables a et b dans la fonction de base car il y a une différence de scope.
2. On effectue les instructions demandées et on remarque bien que les variables dans la fonction ex3permutationsimple() ne changent pas.

### Code
```
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
```

### Output
```
x = 10
y = 999
1. a: 10
b: 999
2. a: 999
b: 10
x = 10
y = 999
```

## Exercice 4

1. j'ai utilisé `#include <sys/types.h>` pour simplifier les types (uint au lieu de unsigned int)
2. On initialise: `x = 0x0E2C;`
3. On le convertit en héxadécimal : 0xFF00
4. Le résultat est correct, j'ai fait le calcul manuellement et on trouve le même résultat.
5. on utilise `res2 = res1 >> 8;` pour garder que les 8 bits forts.
6. On vient d'opérer une division par 4 sur x. La valeur est correcte.
7. J'ai codé une méthode grâce à l'algorithme écrit ci-après la question 7. Tout est reporté [ici](#code-3)

### Code
```
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

    printf("res3: %d\n", res3);

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
```
### Output

```
x_d: 3628
x_b: 0000 1110 0010 1100
res1_d: 3584
res1_x: 0xE00
res2_d, 14
res2_x: 0xE
res3_d: 400
res3_x: 1900000111000000000
0000000000001110
0000000110010000
```


## Exercice 5

1. `int tab[100];`
2. On utilise un for qui affecte `tab[i] = i`.
3. On l'affiche en utilisant un second for.
4. Pour cette question jusqu'à la sixième, il suffit de remplacer le pas dans le for (`for (int i = 0; i < j; i += k)` ici remplacer k) par le pas que l'on souhaite obtenir.
5. voir question 4
6. voir question 4

J'ai eu le temps d'écrire la fonction `modifystep()` qui permet de choisir un pas et une valeur à remplacer. Elle utilise des pointeurs afin de pouvoir modifier le tableau originel bien qu'il ne soit pas dans le même scope. Le code est dans la section ci dessous.

### Code
```
//
// Created by Aloïs Fournier on 06/05/2024.
//

#include "ex5-tableau.h"
#include <stdio.h>

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

void modifystep(int (*tab)[100], int step, int value) {
    for (int i = 0; i < sizeof(*tab)/sizeof(int); i += step)
    {
        (*tab)[i] = value;
    }
}
```

### Output
```
Tableau Originel: 
tab[0] = 0
tab[1] = 1
tab[2] = 2
tab[3] = 3
tab[4] = 4
tab[5] = 5
tab[6] = 6
tab[7] = 7
tab[8] = 8
tab[9] = 9
tab[10] = 10
tab[11] = 11
tab[12] = 12
tab[13] = 13
tab[14] = 14
tab[15] = 15
tab[16] = 16
tab[17] = 17
tab[18] = 18
tab[19] = 19
tab[20] = 20
tab[21] = 21
tab[22] = 22
tab[23] = 23
tab[24] = 24
tab[25] = 25
tab[26] = 26
tab[27] = 27
tab[28] = 28
tab[29] = 29
tab[30] = 30
tab[31] = 31
tab[32] = 32
tab[33] = 33
tab[34] = 34
tab[35] = 35
tab[36] = 36
tab[37] = 37
tab[38] = 38
tab[39] = 39
tab[40] = 40
tab[41] = 41
tab[42] = 42
tab[43] = 43
tab[44] = 44
tab[45] = 45
tab[46] = 46
tab[47] = 47
tab[48] = 48
tab[49] = 49
tab[50] = 50
tab[51] = 51
tab[52] = 52
tab[53] = 53
tab[54] = 54
tab[55] = 55
tab[56] = 56
tab[57] = 57
tab[58] = 58
tab[59] = 59
tab[60] = 60
tab[61] = 61
tab[62] = 62
tab[63] = 63
tab[64] = 64
tab[65] = 65
tab[66] = 66
tab[67] = 67
tab[68] = 68
tab[69] = 69
tab[70] = 70
tab[71] = 71
tab[72] = 72
tab[73] = 73
tab[74] = 74
tab[75] = 75
tab[76] = 76
tab[77] = 77
tab[78] = 78
tab[79] = 79
tab[80] = 80
tab[81] = 81
tab[82] = 82
tab[83] = 83
tab[84] = 84
tab[85] = 85
tab[86] = 86
tab[87] = 87
tab[88] = 88
tab[89] = 89
tab[90] = 90
tab[91] = 91
tab[92] = 92
tab[93] = 93
tab[94] = 94
tab[95] = 95
tab[96] = 96
tab[97] = 97
tab[98] = 98
tab[99] = 99
Tableau modifié avec pas de 2: 
tab[0] = 0
tab[1] = 1
tab[2] = 0
tab[3] = 3
tab[4] = 0
tab[5] = 5
tab[6] = 0
tab[7] = 7
tab[8] = 0
tab[9] = 9
tab[10] = 0
tab[11] = 11
tab[12] = 0
tab[13] = 13
tab[14] = 0
tab[15] = 15
tab[16] = 0
tab[17] = 17
tab[18] = 0
tab[19] = 19
tab[20] = 0
tab[21] = 21
tab[22] = 0
tab[23] = 23
tab[24] = 0
tab[25] = 25
tab[26] = 0
tab[27] = 27
tab[28] = 0
tab[29] = 29
tab[30] = 0
tab[31] = 31
tab[32] = 0
tab[33] = 33
tab[34] = 0
tab[35] = 35
tab[36] = 0
tab[37] = 37
tab[38] = 0
tab[39] = 39
tab[40] = 0
tab[41] = 41
tab[42] = 0
tab[43] = 43
tab[44] = 0
tab[45] = 45
tab[46] = 0
tab[47] = 47
tab[48] = 0
tab[49] = 49
tab[50] = 0
tab[51] = 51
tab[52] = 0
tab[53] = 53
tab[54] = 0
tab[55] = 55
tab[56] = 0
tab[57] = 57
tab[58] = 0
tab[59] = 59
tab[60] = 0
tab[61] = 61
tab[62] = 0
tab[63] = 63
tab[64] = 0
tab[65] = 65
tab[66] = 0
tab[67] = 67
tab[68] = 0
tab[69] = 69
tab[70] = 0
tab[71] = 71
tab[72] = 0
tab[73] = 73
tab[74] = 0
tab[75] = 75
tab[76] = 0
tab[77] = 77
tab[78] = 0
tab[79] = 79
tab[80] = 0
tab[81] = 81
tab[82] = 0
tab[83] = 83
tab[84] = 0
tab[85] = 85
tab[86] = 0
tab[87] = 87
tab[88] = 0
tab[89] = 89
tab[90] = 0
tab[91] = 91
tab[92] = 0
tab[93] = 93
tab[94] = 0
tab[95] = 95
tab[96] = 0
tab[97] = 97
tab[98] = 0
tab[99] = 99
Tableau modifié avec pas de 3: 
tab[0] = 0
tab[1] = 1
tab[2] = 0
tab[3] = 0
tab[4] = 0
tab[5] = 5
tab[6] = 0
tab[7] = 7
tab[8] = 0
tab[9] = 0
tab[10] = 0
tab[11] = 11
tab[12] = 0
tab[13] = 13
tab[14] = 0
tab[15] = 0
tab[16] = 0
tab[17] = 17
tab[18] = 0
tab[19] = 19
tab[20] = 0
tab[21] = 0
tab[22] = 0
tab[23] = 23
tab[24] = 0
tab[25] = 25
tab[26] = 0
tab[27] = 0
tab[28] = 0
tab[29] = 29
tab[30] = 0
tab[31] = 31
tab[32] = 0
tab[33] = 0
tab[34] = 0
tab[35] = 35
tab[36] = 0
tab[37] = 37
tab[38] = 0
tab[39] = 0
tab[40] = 0
tab[41] = 41
tab[42] = 0
tab[43] = 43
tab[44] = 0
tab[45] = 0
tab[46] = 0
tab[47] = 47
tab[48] = 0
tab[49] = 49
tab[50] = 0
tab[51] = 0
tab[52] = 0
tab[53] = 53
tab[54] = 0
tab[55] = 55
tab[56] = 0
tab[57] = 0
tab[58] = 0
tab[59] = 59
tab[60] = 0
tab[61] = 61
tab[62] = 0
tab[63] = 0
tab[64] = 0
tab[65] = 65
tab[66] = 0
tab[67] = 67
tab[68] = 0
tab[69] = 0
tab[70] = 0
tab[71] = 71
tab[72] = 0
tab[73] = 73
tab[74] = 0
tab[75] = 0
tab[76] = 0
tab[77] = 77
tab[78] = 0
tab[79] = 79
tab[80] = 0
tab[81] = 0
tab[82] = 0
tab[83] = 83
tab[84] = 0
tab[85] = 85
tab[86] = 0
tab[87] = 0
tab[88] = 0
tab[89] = 89
tab[90] = 0
tab[91] = 91
tab[92] = 0
tab[93] = 0
tab[94] = 0
tab[95] = 95
tab[96] = 0
tab[97] = 97
tab[98] = 0
tab[99] = 0
Tableau modifié avec pas de 5: 
tab[0] = 0
tab[1] = 1
tab[2] = 0
tab[3] = 0
tab[4] = 0
tab[5] = 0
tab[6] = 0
tab[7] = 7
tab[8] = 0
tab[9] = 0
tab[10] = 0
tab[11] = 11
tab[12] = 0
tab[13] = 13
tab[14] = 0
tab[15] = 0
tab[16] = 0
tab[17] = 17
tab[18] = 0
tab[19] = 19
tab[20] = 0
tab[21] = 0
tab[22] = 0
tab[23] = 23
tab[24] = 0
tab[25] = 0
tab[26] = 0
tab[27] = 0
tab[28] = 0
tab[29] = 29
tab[30] = 0
tab[31] = 31
tab[32] = 0
tab[33] = 0
tab[34] = 0
tab[35] = 0
tab[36] = 0
tab[37] = 37
tab[38] = 0
tab[39] = 0
tab[40] = 0
tab[41] = 41
tab[42] = 0
tab[43] = 43
tab[44] = 0
tab[45] = 0
tab[46] = 0
tab[47] = 47
tab[48] = 0
tab[49] = 49
tab[50] = 0
tab[51] = 0
tab[52] = 0
tab[53] = 53
tab[54] = 0
tab[55] = 0
tab[56] = 0
tab[57] = 0
tab[58] = 0
tab[59] = 59
tab[60] = 0
tab[61] = 61
tab[62] = 0
tab[63] = 0
tab[64] = 0
tab[65] = 0
tab[66] = 0
tab[67] = 67
tab[68] = 0
tab[69] = 0
tab[70] = 0
tab[71] = 71
tab[72] = 0
tab[73] = 73
tab[74] = 0
tab[75] = 0
tab[76] = 0
tab[77] = 77
tab[78] = 0
tab[79] = 79
tab[80] = 0
tab[81] = 0
tab[82] = 0
tab[83] = 83
tab[84] = 0
tab[85] = 0
tab[86] = 0
tab[87] = 0
tab[88] = 0
tab[89] = 89
tab[90] = 0
tab[91] = 91
tab[92] = 0
tab[93] = 0
tab[94] = 0
tab[95] = 0
tab[96] = 0
tab[97] = 97
tab[98] = 0
tab[99] = 0
```

Le code est disponible à l'adresse suivante : [Secr3ts/TP5-IGI-2203](https://github.com/Secr3ts/TP5-IGE-2203)
