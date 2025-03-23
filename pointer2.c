#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void change_pointer_value(int *pnum) {
    printf("%s() Before : %d\n", __func__, *pnum);
    *pnum = 999;
    printf("%s() After : %d\n", __func__, *pnum);
}

void change_value(int num) {
    printf("%s() Before : %d\n", __func__, num);
    num = 888;
    printf("%s() After : %d\n", __func__, num);
}

int main(int argc, char *argv[]) {

    int val = 100;

    change_value(val);

    printf("Main Func val = %d\n", val);

    change_pointer_value(&val);

    printf("Main Func val = %d\n", val);

    return 0;
}

// hello I'm Joeyoung ~ 
