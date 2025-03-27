#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 3

/*#include "ptr_struct_function.h"*/


typedef struct Person_own {
    char *name;
    int age;
} Other;


typedef struct Person_user {
    char name [50];
    int age;
    Other *other_ptr;
} User;



static User user;
static Other other;

static int count = 0; 
static int current_count = 0;
static User user_arr[MAX_USERS];


void add_person (const char *name, int age) {
    
    current_count ++;

    if(count < MAX_USERS) {
    strncpy(user_arr[count].name, name, sizeof(user_arr[count].name)-1);
    user_arr[count].age = age;
    count ++;
    }         
}


void how_much_people () {
    printf("Currently has been added %d people, exceedes maximum limit of %d.\n",current_count, MAX_USERS);
}

void people_list (){
    
    printf("Person Information: \n");
    
    for(int i = 0; i < count; i++) {
           printf("[%d] Name: %s , Age: %d\n", i+1, user_arr[i].name, user_arr[i].age);
    }
}


void my_data () {
    other.name = "Chun";
    other.age = 31;
    user.other_ptr = &other;
}    

void input  (){
    
    char name[50];
    int age;

    printf("Name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("Age: ");
    scanf("%d", &age);
    
    add_person(name,age);
    //printf("Your enter: %s, %d\n", user.name, user.age);
    //printf("My name & age: %s, %d\n", user.other_ptr->name, user.other_ptr->age);
}


void test_1 (User *user_ptr) {
    printf("-----------------------------------\n");
    printf("[Struct *]Memory Address: %p\n", &user_ptr);
    printf("[Struct *]Memory Size: %zu\n", sizeof(user_ptr));
    printf("-----------------------------------\n");
    printf("[Struct member]Address and Size: \n");
    printf("Address of Name: %p\n", &user_ptr->name);
    printf("Address of Age: %p\n", &user_ptr->age);
    printf("Sixe of Name: %zu\n", sizeof(user_ptr->name));
    printf("Size of Age: %zu\n", sizeof(user_ptr->age));
}


void test_2 () {
    printf("-----------------------------------\n");
    printf("[test2]Your Name and Age: %s, %d\n", user.name, user.age); 
    //Result:user var is a brand new struct and has nothing to do with main user var.
    printf("[test2]user var address: %p\n", &user); 
    //confirm whether the same as the main function user var.
    user.other_ptr->age = 18;
    printf("[test2]:change age: %s, %d\n",user.other_ptr->name, user.other_ptr->age);
} 


int main () {
    
    input();
    add_person("YYYY",36);
    add_person("CCCC",37);
    add_person("IIII",38);
    how_much_people();
    people_list();

}    
