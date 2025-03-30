
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

typedef struct _country {

    int f_count;
    Family familys[MAX_FAMILY];
    
} country;

country taipei = {0};

// if return >= 0 : family_id 
// if return < 0  : error code
int add_family(const char *name) {

    if (taipei.f_count >= MAX_FAMILY) {
        return -1;
    }

    strncpy(taipei.familys[taipei.f_count].f_name, name, sizeof(taipei.familys[taipei.f_count].f_name)-1);
    taipei.f_count ++;
    return taipei.f_count - 1;
}

/* input arguments : 
 * 'f_id'     : from "add_family" function , please use that first get a family ID
 * 'name'     : the new member name for current family
 * 'age'      : the new member age for current family
 *
 * return value :
 * ( == 0 )   : represented add memebr success
 * ( != 0 )   : add memeber error
 */
int add_member_for_family(int f_id, const char *name, int age) {

    if (f_id >= MAX_FAMILY) {
        printf("invalid family ID ... %d\n", f_id);
        return -1;
    } else if (f_id >= taipei.f_count) {
        printf("invalid family ID ... %d\n", f_id);
        return -1;
    } else if (f_id < 0) {
        printf("invalid family ID ... %d\n", f_id);
        return -1;
    }

    // ---- already check f_id is save ----

    if (taipei.familys[f_id].m_count >= MAX_MEMBERS) {
        printf("family %d member too much ... \n", f_id);
        return -1;
    }

    Family *family = &taipei.familys[f_id];

    strncpy(family->member[family->m_count].m_name, name, sizeof(family->member[family->m_count].m_name)-1);
    family->member[family->m_count].age = age;
    family->m_count++;
    return 0;
}

void show_all_of_family_and_memebr(void) {

    for (int fidx = 0; fidx < MAX_FAMILY; ++fidx) {
        for (int midx = 0; midx < MAX_MEMBERS; ++midx) {
            printf("[%s] [%s] [%d]\n", taipei.familys[fidx].f_name, taipei.familys[fidx].member[midx].m_name, taipei.familys[fidx].member[midx].age);
        }
        printf("------------------\n");
    }
}

int main (void) {

    int chen_family_id = add_family("Chen");
    if (chen_family_id < 0) {
        printf("add family error : %d\n", chen_family_id);
        return -1;
    }

    if (add_member_for_family(chen_family_id, "Joeyoung", 36)) {
        printf("add_member_for_family error : Joeyoung\n");
        return -1;
    }
    if (add_member_for_family(chen_family_id, "Joeyoung1", 37)) {
        printf("add_member_for_family error : Joeyoung1\n");
        return -1;
    }

    int shi_family_id = add_family("Shi");
    if (shi_family_id < 0) {
        printf("add family error : %d\n", shi_family_id);
        return -1;
    }

    if (add_member_for_family(shi_family_id, "Chun", 30)) {
        printf("add_member_for_family error : Chun\n");
        return -1;
    }
    if (add_member_for_family(shi_family_id, "Happy", 13)) {
        printf("add_member_for_family error : Happy\n");
        return -1;
    }

    show_all_of_family_and_memebr();
}

// ----- 
