#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*void print_int(int num) {
    printf("num = %d\n", num);
}

void other_func(int *val, int count) {

    for (int idx = 0; idx < count; ++idx) {
        printf("val[%d] = %d\n", idx, val[idx]);
    }

}
*/
int main(int argc, char *argv[]) {

    int variable = 100;
    printf("variable = %d\n", variable);
    printf("&variable (address) = %08p\n", &variable);

    int *pointer = NULL; 
    printf("pointer = %d\n", pointer);
    pointer = &variable;
    printf("pointer = %08p\n", pointer);
    printf("*pointer = %d\n", *pointer);

    printf("---------\n");
    variable = 200;
    printf("variable = %d , &variable = %08p, pointer = %08p, *pointer = %d\n", variable, &variable, pointer, *pointer);
    variable = 300;
    printf("variable = %d , &variable = %08p, pointer = %08p, *pointer = %d\n", variable, &variable, pointer, *pointer);
    printf("---------\n");
  
    int variable2 = 999;
    printf("variable2 = %d\n", variable2);
    printf("&variable2 (address) = %08p\n", &variable2);
    pointer = &variable2;
    printf("variable = %d , &variable = %08p\n", variable, &variable);
    printf("variable2 = %d , &variable2 = %08p\n", variable2, &variable2);
    printf("pointer = %08p, *pointer = %d\n", pointer, *pointer);

    char name[10] = "JoeyoungCh";

    for (int idx = 0; idx < sizeof(name); ++idx) {
        // printf("%08p : %c\n", &name[idx], name[idx]);
        printf("%08p : %c\n", name + idx, *(name+idx));
    }

    // int pointer
    /*
    int val[10] = {0};

    printf("val = %d\n", val);

    for (int idx = 0; idx < 10; ++idx) {
        // printf("%08p : %d\n", &val[idx], val[idx]);
        printf("%08p : %d\n", val + idx, *(val + idx));
    }
    */

    int num = 3000;
    unsigned char cnum = (unsigned char)num;

    // 4 bytes
    int val = 0;
    printf("[VAL] %08X\n", val);

    // 2 bytes (WORD)
    short *lo = (short *)&val;

    short *hi = lo + 1;

    // void *vpoint 
    // short *hi = ((short *)&val) + 1;

    *lo = 0xAA;
    *hi = 0x55;

    printf("[LO] %08X\n", *lo);
    printf("[HI] %08X\n", *hi);
    printf("[VAL] %08X\n", val);

    // 1 byte
    // unsigned char or char

    // nums is address point to a big area
    //int nums[100];
    //for (int  idx = 0; idx < 100; ++idx) { nums[idx] = idx; }

    //other_func     (nums,     sizeof(nums)/sizeof(nums[0]));
    // other_func     (&nums[0],     sizeof(nums)/sizeof(nums[0]));
    /*
    void other_func(int *val, int count) {

        for (int idx = 0; idx < count; ++idx) {
            printf("val[%d] = %d\n", idx, val[idx]);
        }

    }
    */

    return 0;
}

// hello I'm Joeyoung ~ 
