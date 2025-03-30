
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEMBERS         (2)
#define MAX_FAMILY          (2)
#define MAX_NAME_SIZE       (50)

typedef struct {
    char m_name [MAX_NAME_SIZE];
    int age;
}Member;

typedef struct {
    char f_name [MAX_NAME_SIZE];
    Member member[MAX_MEMBERS];
}Family;

#define ARRAY_SIZE(x) \
    (sizeof(x) / sizeof(x[0]))

static Family familys[MAX_FAMILY] = {0};

// if return >= 0 : family_id 
// if return < 0  : error code
int add_family(const char *name) {

    for (int idx = 0; idx < ARRAY_SIZE(familys); ++idx) {

        if (familys[idx].f_name[0] != '\0') {
            // current family alreay used
            continue;
        }

        strncpy(familys[idx].f_name, name, MAX_NAME_SIZE);
        return 0;
    }

    printf("no available family ... \n");
    return -1;
}


// return !- 0 fail , == 0 success
int add_member_for_family(const char *fname, const char *name, int age) {

    for (int idx = 0; idx < ARRAY_SIZE(familys); ++idx) {

        if (strncmp(fname, familys[idx].f_name, strlen(familys[idx].f_name))) {
            // enter here represented family name mismatch
            continue;
        }

        for (int midx = 0; midx < ARRAY_SIZE(familys[idx].member); ++midx) {

            if (familys[idx].member[midx].m_name[0] != '\0') {
                continue;
            }

            strncpy(familys[idx].member[midx].m_name, name, MAX_NAME_SIZE);
            familys[idx].member[midx].age = age;
            return 0;
        }

        printf("the \"%s\" has no available member ... \n", fname);
        return -1;
    }

    printf("family name \"%s\" not found ... \n", fname);
    return -1;
}

void show_all_familys_and_member(void) {
    for (int idx = 0; idx < ARRAY_SIZE(familys); ++idx) {
        for (int midx = 0; midx < ARRAY_SIZE(familys[idx].member); ++midx) {
            printf("[%s] [%s] [%d]\n", familys[idx].f_name, familys[idx].member[midx].m_name, familys[idx].member[midx].age);
        }
        printf("--------------\n");
    }
}

int main (void) {

    if (add_family("Chen")) {
        printf("add \"Chen\" family error ...\n");
        return -1;
    }

    if (add_member_for_family("Chen", "Joeyoung", 36)) {
        printf("add \"Joeyoung\" in \"Chen\" family error ...\n");
        return -1;
    }
    if (add_member_for_family("Chen", "Joeyoung2", 37)) {
        printf("add \"Joeyoung\" in \"Chen\" family error ...\n");
        return -1;
    }

    if (add_family("Shi")) {
        printf("add \"Chen\" family error ...\n");
        return -1;
    }

    if (add_member_for_family("Shi", "Chun", 30)) {
        printf("add \"Chen\" family error ...\n");
        return -1;
    }

    if (add_member_for_family("Shi", "Happy", 13)) {
        printf("add \"Chen\" family error ...\n");
        return -1;
    }

    show_all_familys_and_member();
}

// ----- 
