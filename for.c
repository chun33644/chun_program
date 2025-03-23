
#include "stdio.h"
#include "stdlib.h"


int show(int start, int count) {

    if (start != 1) {
        return -1;
    }

    if (count > 1000) {
        return -2;
    }

    for (int idx = start; idx < count; ++idx) {
        printf("%d ", idx);
    }
    printf("\n");

    return 0;
}

int main(int argc, char *argv[]) {

    printf("---------------------------\n");

    printf("argument count: %d\n",argc);    
    for (int idx = 0; idx < argc; ++idx) {
        printf("[%d] %s\n", idx, argv[idx]);
    }

    printf("---------------------------\n");

    int ret = show(1, 10);
    if (ret == 0) {
        printf("show ok\n");
    } else {
        printf("show error\n");
    }
 
    ret = show(0, 10);

    if (ret == 0) {
        printf("show ok\n");
    } else {
        printf("show error\n");
    }

    ret = show(0, 20000);
    if (ret == 0) {
        printf("show ok\n");
    } else {
        printf("show error\n");
    }
    /*
    for (int num = 1; num <= 10 ; num++) {

        printf("%d ",num);

    }
        printf("\n");
    
    for (int num2 = 1; num2 <=5 ; num2++){
        printf("%d ",num2);
    
    }
    */

}

