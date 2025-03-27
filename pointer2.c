#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*P-1.test value at main whether have change after change pointer and int function value 

void change_pointer_value(int *pnum) {
    printf("%s() Before : %d\n", __func__, *pnum);
    *pnum = 999;
    printf("%s() After : %d\n", __func__, *pnum);
}

void change_value(int num) {
    printf("%s() Before : %d\n", __func__, num);
    num = 888;
    printf("%s() After : %d\n", __func__, num);
}

int main(int argc, char *argv[]) {

    int val = 100;

    change_value(val);

    printf("Main Func val = %d\n", val);

    change_pointer_value(&val);

    printf("Main Func val = %d\n", val);

    return 0;
}
*/


/*P-2.*/
typedef struct Person_own {
    char *name;
    int age;
} Own;    

typedef struct Person_user {
    char name [50];
    int age;
    Own *chundata;
} User;

void person_data (User *userdata){

    printf("Your Name: ");
    scanf("%s", userdata.name);
    printf("Your Age: ");
    scanf("%d", &userdata.age);
    printf("Your enter: %s, %d\n", userdata.name, userdata.age);
    printf("Hi My name & age: %s, %d\n", userdata.chundata->name, userdata.chundata->age);
    userdata.chundata->age = 18;
}

/*void person_data (User *data){
    printf("Your Name: ");
    scanf("%s", data->name);
    printf("Your Age: ");
    scanf("%d", &data->age);
    printf("Hi My name & age: %s, %d\n", data->chundata->name, data->chundata->age);
}*/

void test (User *data, User userdata) {
    printf("[test1]Your Name and Age: %s, %d\n", userdata.name, userdata.age);
    printf("[test2]userdata address: %p\n", &userdata); 
    printf("[test3]chundata: %s, %d\n",userdata.chundata->name, userdata.chundata->age);
    printf("-----------------------------------\n");
    printf("* size: %zu",sizeof(data));
    printf("-----------------------------------\n");
    printf("[User *data]Memory address: %p\n", &data);
    printf("[User *data]Memory size: %zu\n", sizeof(User));
    printf("-----------------------------------\n");
    printf("[User userdata]Address and size of Struct member: \n");
    printf("Address_Name: %p\n", &data->name);
    printf("Address_Age: %p\n", &data->age);
    printf("Size_Name: %zu\n", sizeof(data->name));
    printf("Size_age: %zu\n", sizeof(data->age));
}

int main(int argc, char *argv[]) {
    User userdata;
    Own mydata;

    mydata.name = "Chun";
    mydata.age = 31;
    userdata.chundata = &mydata;
    
    //User *ptr = &data;   // !!!
    person_data(userdata);
    test (&userdata, userdata);

    printf("userdata address at main fun: %p\n", &userdata);
}


/* for test address, no need to read !
typedef struct user{
    char name[50];
    int age;
} users;

int main(int argc, char *argv[]) {
    users data = {"chun",31};
    
    printf("Address: %p\n",&data);
    printf("Name_Address of struct member: %p\n", &data.name);
    printf("Age_Address of struct member: %p\n", &data.age);
}
*/
