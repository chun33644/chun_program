#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 50


/*P-1
    struct Person{
    char name[50];
    int age;
    float height;
};


void person_data (struct Person *p) {
    printf("Before Name: %s\n", p->name);
    printf("Before Age: %d\n", p->age);
    printf("Before Height: %.2f\n", p->height);    

 
}

void update_person_data (struct Person *p) {

    snprintf(p->name, sizeof(p->name), "JoeYoung");
    p->age = 37;
    p->height = 166;
    
    printf("After Name: %s\n", p->name);
    printf("After Age: %d\n", p->age);
    printf("After Height: %.1f\n", p->height);    

}


int main(int argc, char *argv[]) {

    struct Person person1 = {"Chun", 31, 153.2};
    person_data(&person1);
    update_person_data(&person1);


    printf("Before Age: %d\n", person1.age);
    printf("Before Height %.2f\n", person1.height);

    //var name is an array, need to be converted using strcpy(=string copy)
    strcpy(person1.name, "JoeYoung");
    person1.age = 37;
    person1.height = 166.3;

    printf("After Name: %s\n", person1.name);
    printf("After Age: %d\n", person1.age);
    printf("After Height %.2f\n", person1.height);

    struct Person person3[3] = {
      {"Alice",30,155.6},
      {"Bob",25,159},
      {"Charlie",35,160.6}
    };
    
    for (int idex = 0; idex < 3; idex++){
        printf("Person %d: %s, Age: %d, Height: %.2f\n", idex+1, person3[idex].name, person3[idex].age, person3[idex].height);
    }

*/

/*P-2
    struct Student{
    char name[50];
    int age;
};

void updateAge(struct Student *mod_age, int newAge){
    mod_age->age = newAge;
}    

void updateName(struct Student *mod_name){
    snprintf(mod_name->name, sizeof(mod_name->name),"JoyYoung");
}
    

int main (int argc, char *argv[]){
    
    struct Student stu;

    printf("Enter the name: \n");
    scanf("%s",stu.name);
    printf("Enter the age: \n");
    scanf("%d",&stu.age);

    printf("Before Age: %d\n", stu.age);
    printf("Before Name: %s\n",stu.name);

    updateAge(&stu, 30);
    printf("After Age: %d\n", stu.age);

    updateName(&stu);
    printf("After Name: %s\n", stu.name);
*/
/*P-3    
    struct Address{
        char street[100];
        char city[50];
        int postalCode;
    };

    struct Student{
        char name[50];
        int age;
        float score;
        struct Address address;
    };

    int main (int argc, char *argv[]){
        struct Student student1 = {"Chun",31,85.5};
        
        struct Student addr;
        printf("Enter address of street: ");
        scanf("%s",addr.address.street);
        printf("Enter address of city: ");
        scanf("%s",addr.address.city);
        printf("Enter address of postalCode: ");
        scanf("%d",&addr.address.postalCode);

        printf("Student Information: \n");
        printf("Name: %s\n", student1.name);
        printf("Age: %d\n", student1.age);
        printf("Score: %.2f\n", student1.score);
        printf("Address: %s, %s, %d\n", addr.address.street, addr.address.city, addr.address.postalCode);
*/
/*P-4

    struct Address{
        char street[100];
        char city[50];
        int postalCode;
    };

    struct Student{
        char name[50];
        int age;
        float score;
        struct Address address;
    };

    int compare (const void *a, const void *b) {
        struct Student *studentA = (struct Student *)a;
        struct Student *studentB = (struct Student *)b;

        if (studentA->score < studentB->score) {
            return 1;
          } else if (studentA->score > studentB->score) {
              return -1;
            } else {
                return 0;
              }
    }
            


    int main (int argc, char *argv[]){
    
    int n;
    
    while (1) {
        printf("Enter number of students: ");
        
        if (scanf("%d",&n) == 1) {
            break;
        
        } else {
            printf("Please enter an integer \n");
            while (getchar() != '\n');
          }
    }

    struct Student students[n];

    for (int i = 0; i < n; i++){
        printf("Enter information for student %d\n",i+1);

        printf("Enter name: ");
        scanf("%s",students[i].name);
        printf("Enter age: ");
        scanf("%d",&students[i].age);
        printf("Enter score: ");
        scanf("%f",&students[i].score);
        printf("Enter street: ");
        scanf("%s",students[i].address.street);
        printf("Enter city: ");
        scanf("%s",students[i].address.city);
        printf("Enter postalCode: ");
        scanf("%d",&students[i].address.postalCode);
        
    }
    
    qsort (students, n, sizeof(struct Student), compare);

    printf("Student Information(by score): \n");
    
    for (int i = 0; i < n; i++){
        if (i<n) {
            printf("-------------------------------\n");
        }    
        
        printf("Name: %s\n",students[i].name);
        printf("Age: %d\n",students[i].age);
        printf("score: %.2f\n",students[i].score);
        printf("Address: %s, %s, %d\n",students[i].address.street, students[i].address.city, students[i].address.postalCode);    
    }
    
*/

struct Address {
    char street [100];
    char city [50];
    int postalcode;
};

struct Information {
    char name [50];
    int age;
    unsigned char birthday_month;
    unsigned char birthday_day;
    struct Address address;
};

struct Information users[MAX_USERS]; 

int input () {
    
   int num_users ;
   char ch;

   while (1) {
       
       printf("Enter the number of user records(<50): ");                
       if ( (scanf("%d", &num_users) == 1) && (num_users < MAX_USERS) && (num_users > 0)  ) {
           ch = getchar();
               if (ch != '\n'){
                   printf("Error : Please enter only one integer!\n");
                   while (getchar() != '\n');
               }   
       }
       else {    
           printf("Please Enter an integer! \n");
           while (getchar() != '\n');
        }    
    }               
  
    
    for (int i = 0; i < num_users; i++){
        
        printf("Information of User: %d\n", i+1);

        printf("Enter Name: \n");
        scanf("%s",users[i].name);
        printf("Enter Age: \n");
        scanf("%d",&users[i].age);
        printf("Enter Birthday Month: \n");
        scanf("%hhu",&users[i].birthday_month);
        printf("Enter Birthday Day: \n");
        scanf("%hhu",&users[i].birthday_day);
        printf("Enter Street of Address: \n");
        scanf("%s",users[i].address.street);
        printf("Enter City of Address: \n");
        scanf("%s",users[i].address.city);
        printf("Enter PostalCode of Address: \n");
        scanf("%d",&users[i].address.postalcode);
    }
    return num_users; 
}
    

int output(int n) {

        
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            printf("--------------------\n"); 
        }
        printf("Information of User: %d\n", i+1);
            
        printf("Name: %s\n",users[i].name);
        printf("Age: %d\n",users[i].age);
        printf("Birthday: %hhu / %hhu\n",users[i].birthday_month, users[i].birthday_day);
        printf("Address: %s, %s, %d\n",users[i].address.street, users[i].address.city, users[i].address.postalcode); 
    }
    return 0;
}                  
        
int main (int argc, char *argv[]) {

    while (1) {
        int n = input();
        while ( (n > MAX_USERS) && (n < 0) ) {
            output(n); }
        printf("Input error!\n");
    }
}

/*int main (int argc, char *argv[]) {    
    //int a;
    char b;

    printf("Enter: ");
    //scanf("%d", &a);
    scanf("%c", &b);
    printf("scanf=%c\n",b);
    b = getchar();
    printf("getchar= %c", b);
    //return 0;

}*/  
