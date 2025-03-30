
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEMBERS 2
#define MAX_FAMILY 2


typedef struct {
    char m_name [50];
    int age;
}Member;

typedef struct {
    char f_name [50];
    int m_count ;
    Member member[MAX_MEMBERS];
}Family;

static Family family[MAX_FAMILY];
int f_count = 0;
//int add_multi_familys (const char *name[]) {

int how_much_familys(void) {
    return f_count;
}    
    
int add_family (const char *name) {
    
    if (f_count >= MAX_FAMILY) {
        printf("Error: Maximum limit: %d\n",MAX_FAMILY);
        return -1;
    }

    strncpy(family[f_count].f_name, name, sizeof(family[f_count].f_name)-1);
    f_count ++;
    
    return 0;

    // -----

   /* if (f_count < MAX_FAMILY) {
        strncpy(family[f_count].f_name, name, sizeof(family[f_count].f_name)-1);
        f_count ++;
        return 0;
        
    } else {
        printf("Error: Maximum limit: %d\n",MAX_FAMILY);
        return -1;
    }*/
       
    //printf("Current family count: %d",f_count);
}

int add_mamber_to_family () {


}


void how_much_people (void) {



}


int main (int argc, char *argv[]) {
    
    add_family("Lin");
    add_family("Chen");
    printf("current familys : %d\n", how_much_familys());
    //add_family("Wang");


}            
