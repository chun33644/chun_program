
#ifndef PTR_STRUCT_FUNCTION_H
#define PTR_STRUCT_FUNCTION_H

typedef struct Person_own {
    char *name;
    int age;
} Other;


typedef struct Person_user {
    char name [50];
    int age;
    Other *other_ptr;
} User;


void add_person (const char *name, int age);

void how_much_people ();

void people_list ();

void my_data ();


void input ();
//Please user enter name & age.


void test_1 (User *);
//Test the allocation of memory address and size of functions(struct & pointer).

void test_2 ();
//Test whether the global var has an effect.

#endif
