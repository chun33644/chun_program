
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int *ptr_arr;
    int size; //for arr[]
    int capacity; //for init size
    bool is_allocated; //trun =1, false=0
} DynamicArray;



//-----initial arr size------
int init_arr (DynamicArray *arr, int init_size) {

    if (arr->is_allocated) {
        printf("Memory already allocated! Please free memory.\n");
        return -1;
    }
    
    arr->is_allocated = true;
    arr->size = 0;
    arr->capacity = init_size;
    arr->ptr_arr = (int *)calloc(arr->capacity, sizeof(int));
    if (arr->ptr_arr == NULL) {
        printf("Memory allocation failed!\n");
        return -1;
    }

}



int add_element (DynamicArray *arr, int value) {
    
    if (arr->size >= arr->capacity) {
        printf("Capacity [%d] exceeded.\n", arr->capacity);
        return -1;
    }   

    arr->ptr_arr[arr->size] = value;
    arr->size ++;
    return 0;
}


void display_arr (DynamicArray *arr) {

    
    for (int idex = 0; idex < arr->size; idex ++) {
        printf("[%d] [%d] [%d] [%p]\n", idex, arr->is_allocated, arr->ptr_arr[idex], &arr->ptr_arr[idex]);
    }

}

int free_arr(DynamicArray *arr) {

    if (arr->ptr_arr == NULL) {
        return -1;
    }

    free(arr->ptr_arr);
    arr->ptr_arr = NULL;
    arr->is_allocated = false;
    return 0;

}    

    
    

int main (int argc, char *argv[]) {
    
    DynamicArray array;
    if (init_arr(&array,3) == -1){
        printf("Initial error\n");
    }

    printf("*ptr_arr of addr:%p\n", array.ptr_arr);
    printf("ptr_arr of addr:%p\n",&array);

    add_element(&array,10);
    add_element(&array,80);
    add_element(&array,30);
    //add_element(&array,50);

    display_arr(&array);

    //init_arr(&array,5);

    printf("free: %d\n", free_arr(&array));
        
    printf("*ptr_arr after free of addr: %p\n", array.ptr_arr);
    
}














int for_practise (void) {
/*
    //allocate a memory block that can hold 5 integers.
    int *arr = (int *)malloc(5 * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return -1;
    }

    memset(arr, 0, 5 * sizeof(int));
*/    


    int *arr = (int *)calloc(5, sizeof(int));

    printf("array: \n");
    for (int idex = 0; idex < 5; idex++) { 
        printf("[%d] [%d]\n", idex, arr[idex]);
    }



    //arr[ ]={0,10,20,30,40}
    for (int idex = 0; idex < 5; idex++) {
        arr[idex] = idex * 10;
    }

    //display malloc arr result 
    printf("Initial array to *10: \n");
    for (int idex = 0; idex < 5; idex++) { 
        printf("[%d] [%d]\n", idex, arr[idex]);
    }
    
 
    //use realloc to add 10 integers for arr.
    arr = (int *)realloc(arr, 10 * sizeof(int));
    if (arr == NULL) {
        printf("Reallocation failed!\n");
        return -1;
    }
    
    
    //arr[ ]={0,10,20,30,40,100,120,140,160,180}
    for (int idex = 5; idex < 10; idex++) {
        arr[idex] = idex * 20;
    }



    printf("Increase the original arr size to 10 integers, and initial to *10:\n");
    for (int idex = 0; idex < 10; idex++) {
        printf("[%d] [%d]\n", idex, arr[idex]);
    }  


    free(arr);
    printf("Memory freed.\n");

}




    
