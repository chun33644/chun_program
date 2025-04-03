
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




#define MAX_STUDENTS 5
#define ARRAY_SIZE(x)  (sizeof(x)/sizeof(x[0]))


typedef struct {
    char ownner[50];
    char name[50];
    float score;
    int in_used; // in use == 1 , unuse == 0
} Student;


/*
for (int idx = id; idx < ARRAY_SIZE(x) - 1; ++idx) {
    memcpy(&stud_addr[idx], &stud_addr[idx + 1], sizeof(Student));
}
for (int idx = id + 1; idx < ARRAY_SIZE(x); ++idx) {
    memcpy(&stud_addr[idx - 1], &stud_addr[idx], sizeof(Student));
}

*/

typedef struct {   
    Student stud_arr[MAX_STUDENTS];
} S_Manage;



static S_Manage Information = {0};
// also equicalent to ------> memset(&Information, 0, sizeof(Information));

/*
|< out  >|<   name      >|< in >|
*/
Student *get_student_addr (const char *ownner) {

    for (int idex = 0; idex < ARRAY_SIZE(Information.stud_arr); idex++) {

        if (Information.stud_arr[idex].in_used == 1) {
            continue;
        } else {
            // represented in_used == 0
            Information.stud_arr[idex].in_used = 1;
            snprintf(Information.stud_arr[idex].ownner, 50, "%s", ownner);
            return &Information.stud_arr[idex]; //return ID of student
        }
    }

    return NULL;
}

//----- Use method(add_student) to get student id -----
// [0] [1] name=ooo, score=100
// [1] [1] name=ccc, score=100
// [2] [1] name=aaa, score=100
// [3] [0] name=, score=     (unuse)

int add_student (const char *name, float score) {
    
    for (int idex = 0; idex < ARRAY_SIZE(Information.stud_arr); idex++) {

        if (Information.stud_arr[idex].in_used == 1) {
            continue;
        } else {
            // represented in_used == 0
            Information.stud_arr[idex].in_used = 1;
            strncpy(Information.stud_arr[idex].name,
                    name, sizeof(Information.stud_arr[idex].name)-1);
            Information.stud_arr[idex].score = score;
            return idex; //return ID of student

        }
    }

    return -1;
    printf("Error : exceeded quantity restriction !\n");
}
    
/*
    if (Information.stud_count >= MAX_STUDENTS {
        printf("Error : exceeded quantity restriction !\n");
        return -1;
    }

    strncpy(Information.stud_arr[Information.stud_count].name, name, sizeof(Information.stud_arr[Information.stud_count].name)-1);
    Information.stud_arr[Information.stud_count].score = score;
    Information.stud_count ++;
    return Information.stud_count-1; 

}
*/

 //----- Use method(add_student) to get student id -----
 // [0] [1] name=ooo, score=100
 // [1] [1] name=ccc, score=100
 // [2] [0] name=, score=     (delete)
 // [3] [1] name=bbb, score=100    


int remove_student_byID (int id) {

    if (id >= ARRAY_SIZE(Information.stud_arr)) {
        printf("Error: no such ID.\n");
        return -1;
    }
    
    if (id < 0) {
        printf("Error: no such ID.\n");
        return -1;
    }


    if (Information.stud_arr[id].in_used == 0) {
        printf("Empty student ..\n");
        return -1;
    }

    memset(&Information.stud_arr[id], 0, sizeof(Student));
    return 0;
    // -------
/* 
    memset(Information.stud_arr[id].name, 0, sizeof(Information.stud_arr[id].name));
    memset(&Information.stud_arr[id].score, 0, sizeof(Information.stud_arr[id].score));  
    //also can --->  Information.stud_arr[id].sorce = 0.0f;
*/  
    
    return 0;

}

int readd_student (int id, const char *name, float score) {

    if (id >= MAX_STUDENTS) {
        printf("Error: no such ID.\n");
        return -1;
    }
    
    if (id < 0) {
        printf("Error: no such ID.\n");
        return -1;
    }
    
    if ( (strlen(Information.stud_arr[id].name) != 0) || (Information.stud_arr[id].score != 0.0f)) {
        printf("ID[%d] already exists.\n",id);
        return -1;
    }

    strncpy(Information.stud_arr[id].name, name, sizeof(Information.stud_arr[id].name)-1);
    Information.stud_arr[id].score = score;
 
    return 0;

}    

void display_all_studentsInfo (void) {

    Student *stud = Information.stud_arr;

    // -----
    for (int sidx = 0; sidx < ARRAY_SIZE(Information.stud_arr); sidx ++) {

        if (Information.stud_arr[sidx].in_used == 0) {
            continue;
        }

        printf("[%d] [%s] [%s] [%.2f]\n", sidx, stud[sidx].ownner, stud[sidx].name, stud[sidx].score);
    }    
/*
    
    for (int sidx = 0; sidx < Information.stud_count; sidx ++) {
        printf("[%d] [%s] [%.2f]\n", sidx, stud[sidx].name, stud[sidx].score);
    }    
*/
}

int how_many_students(void) {
    
    int count = 0;
    for (int sidx = 0; sidx < ARRAY_SIZE(Information.stud_arr); sidx ++) {

        if (Information.stud_arr[sidx].in_used == 1) {
            count++;
        }
    }
    return count;

}

int find_studentInfo_byID (int id) {
    
    if (id >= ARRAY_SIZE(Information.stud_arr)) {
        printf("Error: no such ID.\n");
        return -1;
    }
    
    if (id < 0) {
        printf("Error: no such ID.\n");
        return -1;
    }

    if (Information.stud_arr[id].in_used == 0) {
        printf("Error: no such ID \n");
        return -1;
    }

    printf("[%d] [%s] [%.2f]\n", id, Information.stud_arr[id].name, Information.stud_arr[id].score);
    
}



int main (int argc, char *argv[]) {

    int chun_id = add_student("Chun", 62.5);
    if (chun_id < 0) {        
        printf("Error: Chun_ID: %d\n", chun_id);
        return -1;
    }
    

    int lee_id = add_student("Lee",68);
    if (chun_id < 0) {
        printf("Error: Lee_ID: %d\n", lee_id);
        return -1;
    }
    
    
    int joe_id = add_student("Joe99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999", 37.2);
    if (joe_id < 0) {
        printf("Error: Joe_ID:%d\n", joe_id);
        return -1;
    }


    display_all_studentsInfo();

    remove_student_byID (1);

    printf("------- removed(1) ---------\n");

    display_all_studentsInfo();

    printf("-----------------------------\n");

/*
    int ken_id = add_student("Ken", 62.5);
    if (ken_id < 0) {        
        printf("Error: Ken_ID: %d\n", ken_id);
        return -1;
    }

    printf("%d\n",how_many_students());

    int sam_id = add_student("Sam", 62.5);
    if (sam_id < 0) {        
        printf("Error: Sam_ID: %d\n", sam_id);
        return -1;
    }
    

    display_all_studentsInfo();

    printf("-----------------------------\n");

    printf("------- re-add ---------\n");

    readd_student(1, "Fiona", 68.9);

    display_all_studentsInfo();

    printf("-----find student Infomation----\n");

    find_studentInfo_byID(0);
*/


    // ---- new example ----
    Student *new_student = get_student_addr(__func__);

    if (new_student == NULL) {
        printf("%s() no student at all \n", __func__);
        return -1;
    }

    add_student("aaaa", 37.2);
    add_student("bbb", 37.2);
    add_student("eee", 38.7);
    printf("LINE ?? %d\n", __LINE__);

    // (char *)
    snprintf(new_student->name, 50, "Joe%d", 100);
    new_student->score = 10000;

    printf("-----------------------------\n");

    display_all_studentsInfo();
}
