#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include <utility.h>
#include "reg.h"

int main(int argc, char **argv)
{
    dword NameSum, NameLen, i, RegID, TestID;

    if ( argc != 3 )
        return 1;

    NameSum = NameLen = strlen(argv[1]);

    for ( i = 0; i < NameLen; i++) {
        NameSum += _rotl((dword)argv[1][i], i);
        }

    NameSum ^= REG_XOR;
    NameSum %= REG_INCR;

    srand(time(NULL));

    sscanf(argv[2], "%X", &TestID);
 
    TestID ^= REG_XOR;
    TestID -= REG_BASE + NameSum;
    TestID %= REG_INCR;

    printf("Diff: %u\n", TestID);

    return 0;
}


