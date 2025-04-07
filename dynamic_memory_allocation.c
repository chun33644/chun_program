
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




DynamicArray *init_ptr (int init_size) {

    if (init_size <= 0){
        printf("Invalid size or initialized!\n");
        return NULL;
    }


    //dynamically allovated structures
    DynamicArray *arr = (DynamicArray *)malloc(sizeof(DynamicArray));
    if (arr == NULL) {
        printf("Memory allocation for DynamicArray failed!\n");
        return NULL;
    }

    //if memory has been allicated, release the allocated memory first.
    if (arr->is_allocated) {
        free(arr->ptr_arr);
        arr->ptr_arr = NULL;
        free(arr);
        arr = NULL;
        arr->is_allocated = false;
        printf("Old memory ha been freed!\n");
    }


    //initial structure 
    arr->size = 0;
    arr->capacity = init_size;
    arr->ptr_arr = NULL;

    //allocated memory
    arr->ptr_arr = (int *)calloc(arr->capacity, sizeof(int));
    if (arr->ptr_arr == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    arr->is_allocated = true;
    return arr;

}



//-----initial arr size------
int init_arr (DynamicArray *arr, int init_size) {

    if (arr == NULL) {
        printf("Invalid * \n");
        return -1;
    }


    if (arr->is_allocated) {
        printf("Memory already allocated! Please free memory.\n");
        return -1;
    }

    arr->size = 0;
    arr->capacity = init_size;
    arr->ptr_arr = (int *)calloc(arr->capacity, sizeof(int));
    if (arr->ptr_arr == NULL) {
        printf("Memory allocation failed!\n");
        return -1;
    }
    
    arr->is_allocated = true;
    return 0;
}



int add_element (DynamicArray *arr, int value) {
   
    if (arr->is_allocated && arr->size <= arr->capacity) {
        arr->ptr_arr[arr->size] = value;
        arr->size ++;
        return 0;
    }else {
        printf("Capacity exceeded or not free and initial.\n");
        return -1;
     }
}


void display_arr (DynamicArray *arr) {


    for (int idex = 0; idex < arr->size; idex ++) {
        printf("[%d] [%d] [%d] [%p]\n", idex, arr->is_allocated, arr->ptr_arr[idex], &arr->ptr_arr[idex]);
    }

}

int free_arr(DynamicArray *arr) {

    if (arr == NULL){
        return -1;
    }

    if (arr->ptr_arr == NULL) {
        return -1;
    }

    if (arr->is_allocated) {
        free(arr->ptr_arr);
        arr->ptr_arr = NULL;
        arr->is_allocated =false;
        return 0;
    } else {
        printf("Memory already freed or not allocated.\n");
        return -1;

      }

}    




int main (int argc, char *argv[]) {

printf("-----------------*ptr--------------------------\n");

    DynamicArray *ptr = init_ptr(2);
    if (ptr == NULL) {
        printf("init_ptr error\n");
    }

    add_element(ptr,20);
    add_element(ptr,30);
    //add_element(arr,40);

    printf("*ptr address [%p], *ptr value [%p] size [%d], capacity [%d]\n", &ptr, ptr, ptr->size, ptr->capacity);
    display_arr(ptr);
    printf("free: %d\n", free_arr(ptr));
    //ptr = NULL; (add to init_ptr function)

    printf("----try again init----\n"); 
    //try again init
    ptr = init_ptr(3);
    if (ptr == NULL) {
        printf("again init_ptr error\n");
    }
    add_element(ptr,50);
    printf("*ptr address [%p], *ptr value [%p] size [%d], capacity [%d]\n", &ptr, ptr, ptr->size, ptr->capacity);
    display_arr(ptr);


printf("--------------------arr-----------------------\n");

    DynamicArray arr;
    if (init_arr(&arr,3) == -1){
        printf("Initial error\n");
    }

    add_element(&arr,10);
    add_element(&arr,80);
    
    printf("arr address [%p] size [%d], capacity [%d]\n", &arr, arr.size, arr.capacity);
    display_arr(&arr);
    printf("free: %d\n", free_arr(&arr));
    add_element(&arr,99); //for test


    printf("-----try again init-------\n");
    if (init_arr(&arr,3) == -1) {
        printf("again inirial error\n");
    }

    add_element(&arr,66);
    add_element(&arr,33);
    printf("arr address [%p] size [%d], capacity [%d]\n", &arr, arr.size, arr.capacity);
    display_arr(&arr);
    

/*
    //init_arr(&array,5);

    printf("free: %d\n", free_arr(&array));
        
    printf("*ptr_arr after free of addr: %p\n", array.ptr_arr);
*/ 
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




    
