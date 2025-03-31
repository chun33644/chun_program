
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_MEMBERS 3
#define MAX_FAMILY 3


typedef struct {

    char m_name [50];
    int age;

} Member;


typedef struct {

    char f_name [50];
    Member m_arr[MAX_MEMBERS];
    int m_count;

} Family;


typedef struct {

    Family f_arr[MAX_FAMILY];
    int f_count;

} Manage;


Manage family = {0};


int add_family (const char *name) {

    if (family.f_count >= MAX_FAMILY) {
        return -1;
    }

    strncpy(family.f_arr[family.f_count].f_name, name, sizeof(family.f_arr[family.f_count].f_name)-1);
    family.f_count ++;
    return family.f_count - 1; // get ID number

}


int add_member_to_family (int f_id, const char *name, int age) {

    if (f_id >= MAX_FAMILY) {
        printf("Invalid family ID %d\n", f_id);
        return -1;
    } else if (f_id >= family.f_count) {
        printf("Invalid family ID %d\n", f_id);
        return -1;
    } else if (f_id < 0) {
        printf("Invalid family ID %d\n", f_id);
        return -1;
    }
        
    if (family.f_arr[f_id].m_count >= MAX_MEMBERS) {
        printf("Memberx exceeded maximum limit.....%d\n", f_id);
        return -1;
    }
    
    Family *ptr_family = &family.f_arr[f_id];

    strncpy(ptr_family->m_arr[ptr_family->m_count].m_name, name, sizeof(ptr_family->m_arr[ptr_family->m_count].m_name)-1);
    


    /*
    strncpy(family.f_arr[f_id].m_arr[family.f_arr[f_id].m_count].m_name, name, sizeof(family.f_arr[f_id].m_arr[family.f_arr[f_id].m_count].m_name)-1);
    */
    
    family.f_arr[f_id].m_arr[family.f_arr[f_id].m_count].age = age;
    family.f_arr[f_id].m_count ++;
    

    return 0;
    
}   

void show_all_of_family_and_members (void) {
    
    for (int fidx = 0; fidx < MAX_FAMILY ; fidx++) {
        for (int midx = 0; midx < MAX_MEMBERS ; midx++) {
            printf("[%s] [%s] [%d]\n",family.f_arr[fidx].f_name, family.f_arr[fidx].m_arr[midx].m_name, family.f_arr[fidx].m_arr[midx].age);
        }
        printf("----------------------------\n");
    }
    
}


void show_all_address (void) {

    printf("Manage Address [%p]\n",&family);
    printf("--------------------------\n");
    
    for (int fidx = 0; fidx < MAX_FAMILY; fidx ++) {
        for (int midx = 0; midx < MAX_MEMBERS; midx ++) {
         printf("[%p] [%p] [%p]\n", &family.f_arr[fidx].f_name, &family.f_arr[fidx].m_arr[midx].m_name, &family.f_arr[fidx].m_arr[midx].age);
        }   
    }
}



void show_all_size (void) {

    printf("Manage size [%zu]\n",sizeof(family));
    printf("--------------------------\n");
    
    for (int fidx = 0; fidx < MAX_FAMILY; fidx ++) {
        for (int midx = 0; midx < MAX_MEMBERS; midx ++) {
         printf("[%zu] [%zu] [%zu]\n", sizeof(family.f_arr[fidx].f_name), sizeof(family.f_arr[fidx].m_arr[midx].m_name), sizeof(family.f_arr[fidx].m_arr[midx].age));
        }   
    }
}



int main(int argc, char *argv[]) {
    
    int Chen_id = add_family("Chen");
    if (Chen_id < 0) {
        printf("Chen add error: %d\n", Chen_id);
        return -1;
    }
    if (add_member_to_family(Chen_id, "Joeyoung3", 35)) {
        printf("add member for Chen family error : Joeyoung3\n");
        return -1;
    }
       


    int Shih_id = add_family("Shih");
    if (Shih_id < 0) {
        printf("Shih add error: %d\n", Shih_id);
        return -1;
    }
    if (add_member_to_family(Shih_id, "Chun", 30)) {
        printf("add member for Shih family error : Chun\n");
        return -1;
    }
    if (add_member_to_family(Shih_id, "Happy", 13)) {
        printf("add member for Shih family error : Happy\n");
        return -1;
    }




    int Wang_id = add_family("Wang");
    if (Wang_id < 0) {
        printf("Wang add error: %d\n", Wang_id);
        return -1;
    }
    if (add_member_to_family(Wang_id, "Joe", 36)) {
        printf("add member for Wang family error : Joe\n");
        return -1;
    }
    if (add_member_to_family(Wang_id, "Lisa", 26)) {
        printf("add member for Wang family error : Lise\n");
        return -1;
    }
    if (add_member_to_family(Wang_id, "Judy", 28)) {
        printf("add member for Wang family error : Judy\n");
        return -1;
    }
    /*if (add_member_to_family(Wang_id, "Alisa", 33)) {
        printf("add member for Wang family error : Alisa\n");
        return -1;
    }*/




    /*int Wang2_id = add_family("Wang");
    if (Wang2_id < 0) {
        printf("Wang2 add error: %d\n", Wang2_id);
        return -1;
    }
    if (add_member_to_family(Wang2_id, "Ping", 28)) {
        printf("add member for Wang2 family error : Ping\n");
        return -1;
    }
    if (add_member_to_family(Shih_id, "Wei", 32)) {
        printf("add member for Wang2 family error : Wei\n");
        return -1;
    } */

    show_all_of_family_and_members();
    show_all_address();
    show_all_size();

    return 0;
}    
