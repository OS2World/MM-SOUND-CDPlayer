#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include <utility.h>
#include "reg.h"

int main(int argc, char **argv)
{
    dword NameSum, NameLen, i, RegID;

    if ( argc != 2 )
        return 1;

    NameSum = NameLen = strlen(argv[1]);
 
    for ( i = 0; i < NameLen; i++) {
        NameSum += _rotl((dword)argv[1][i], i);
        }
 
    NameSum ^= REG_XOR;
    NameSum %= REG_INCR;

    srand(time(NULL));
    RegID = ((rand() * (RAND_MAX+1) + rand()) % REG_MAX) * REG_INCR + REG_BASE + NameSum;
    RegID ^= REG_XOR;

    printf("%8.8X - %s\n", RegID, argv[1]);

    return 0;
}


 

