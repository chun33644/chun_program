#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

    int ival = 100;

    short *lsh = (short *)&ival;
    short *hsh = (short *)&ival + 1;

    printf("int %d [%08X]\r\n", ival, ival);

    printf("*lsh %d [%04X]\r\n", *lsh, *lsh);
    printf("*hsh %d [%04X]\r\n", *hsh, *hsh);

    return 0;
}
