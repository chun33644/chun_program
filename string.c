#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/*P-1 Using 'scanf()' read a string

int main(int argc, char *argv[]) {

    char test_character_length[15];
    printf("Enter a string: ");
    scanf("%14s",test_character_length);
    printf("The string you entered: %s\n",test_character_length);
}
*/

/*P-2 Using 'fgets()' read complete string

int main(int argc, char *argv[]) {
    
   char Read_CompleteStr[15];
   printf("Enter a string: ");
   fgets(Read_CompleteStr,sizeof(Read_CompleteStr),stdin);
   printf("The string you entered: %s\n",Read_CompleteStr);
}

    
    char *str = malloc( 15 * sizeof(char) );
    
    if (str == NULL) {
        printf("Dynamic Memory Allocation Error!\n");
        return 1;
    }

    printf("Enter a string: ");
    fgets(str, 15, stdin);
    printf("The string you entered: %s\n",str);    

    free(str);
    str = NULL;

    if (str != NULL) {
        printf("After free: %s\n", str);
    }

    printf("Memory freed successfully.\n");  //for verify
}
*/

/*P-4 Using 'strlen()' calculate string length (> \0) 

int main(int argc, char argv[]) {

   char strLength[] = "Chun Learning";
   printf("String Length: %zu\n", strlen(strLength));

}

*/

/*P-5 Using 'strcpy()' copy string

int main(int argc, char argv[]) {
    
    char User_enter[15];
    char UserEnterCopy[20];

    printf("Enter a string: ");
    fgets(User_enter, 15, stdin);
    printf("Before User Enter: %s\n",User_enter);
    
    strcpy(UserEnterCopy,User_enter);  // UserEnterCopy[size] > User_enter[]
    printf("After User Enter: %s\n",User_enter);  
    printf("Copy User enter: %s\n",UserEnterCopy);
}

*/

/*P-6 Using 'strcat(var1,var2)' merge the string of var2 after var1 
 */

int main(int argc, char argv[]) {
    
    char User_enter1[20];
    char User_enter2[20];

    printf("Enter first string: ");
    fgets(User_enter1, sizeof(User_enter1), stdin);

    printf("Enter second string: ");
    fgets(User_enter2, sizeof(User_enter2), stdin);
    
    printf("Before enter1 result: %s, length: %zu\n",User_enter1, strlen(User_enter1));   //for verify whether there is a line break
    printf("Before enter2 result: %s, length: %zu\n",User_enter2, strlen(User_enter2));  //for verify whether there is a line break

    size_t len1 = strlen(User_enter1);
    if ( (len1 > 0) && (User_enter1[len1 - 1] == '\n') ) {
        User_enter1[len1 - 1] = '\0';
    }

    printf("Removing line break: \n");
    printf("After enter1 result: %s, length: %zu\n",User_enter1, enter_len1); 

    strcat(User_enter1, User_enter2);
    printf("The string you entered: %s\n", User_enter1);

}
