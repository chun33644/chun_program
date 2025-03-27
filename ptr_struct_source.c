#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ptr_struct_function.h"


int main() {
    
    //input(user);
    //test_1(&user);
    //test_2(user);
    //printf("[main]userdata address: %p\n", &user);
    add_person("Alice",36);
    add_person("Joe",38);
    add_person("Lisa",28);
    add_person("Leo",36);

    how_much_people();
    people_list();

    return 0;

}



