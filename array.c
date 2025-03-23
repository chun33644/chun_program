#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//int main(int argc, char *argv[]) {

/*P-1    
    
    int arr[5]={1,2,3,4,5,6};

    for (int i = 0; i < 7; i++){
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    return 0;
*/

/*P-2
     
    int arr[10];
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("陣列的元素個數: %d\n",size);
    
    return 0 ;
*/

/*P-3

    int matrix[3][2]={
        {1,2},
        {3,4},
        {5,6}
    };
       
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 2; j++)
            printf("matrix[%d][%d] = %d\n", i, j, matrix[i][j]);
    }
*/

/*P-4
 
    int arr[3] = {40,20,30};

    //printf("arr[0] = %d\n", *(arr+0));
    //printf("arr[1] = %d\n", *(arr+1));
    //printf("arr[2] = %d\n", *(arr+2));
    
    printf("arr[0] = %d\n", arr[0]);
    printf("arr[1] = %d\n", arr[1]);
    printf("arr[2] = %d\n", arr[2]);
*/

    int compare (const void *a, const void *b) {
        return (*(int *)a - *(int *)b);
    }

    int main (int argc, char *argv[]){

        int arr [4] = {66,12,28,10};
    
        qsort (arr, 4, sizeof(int), compare);

        for (int i = 0; i < 4; i++){
            printf("%d, ",arr[i]);
        }

    return 0;



}
