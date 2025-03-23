
#include "stdio.h"
#include "stdlib.h"
#include "limits.h"
#include "time.h"
#include "string.h" 
#include "math.h"

void otherfunction(void) {


    printf("---------------------------------------------------\n");

/*

P-1.Printf & Scanf
    int n;
	float f;
	double d;
	char c;

	printf("Please enter an integer: ");
	scanf("%d",&n);
	printf("The integer you enter is: %d\n",n);

	printf("Please enter a float: ");
	scanf("%f",&f);
	printf("The float you enter is: %f\n",f);

	printf("Please enter a double: ");
	scanf("%lf",&d);
    printf("The double you enter is: %lf\n",d);


    printf("Please enter a char:  ");
    scanf("%c",&c);
    printf("The char you enter is: %c\n",c);   


P-2.MIN & MAX with #include <limits.h>
 
    //printf("minimum of unsigned short is: %d\n", USHRT_MIN);
    // value=0 (no this constant)   
    printf("Maximum of unsigned short is: %d\n", USHRT_MAX);
    printf("Minimum of short is: %d\n", SHRT_MIN);
    printf("Maximum of short is: %d\n", SHRT_MAX);


    unsigned short unsh= 30000;
    short sh= 30000;
    unsh+= 30000;
    sh+= 30000;
    printf("Unsigned short sum the result: %d\n",unsh);
    printf("Short sum the result: %d\n",sh);    


P-3.to add two integers

    int num1, num2, sum;

    printf("Enter two integers: ");
    scanf("%d %d",&num1, &num2);
    sum= num1+num2;

    printf("%d +%d =%d\n", num1, num2, sum);


P-4.Multiply
    
    double num3, num4, mul;
   
    printf("Enter two integers: ");
    scanf("%lf %lf", &num3, &num4);
    mul= num3*num4;

    printf("Multiply= %lf\n", mul);
    printf("Multiply(0.00)= %.2lf\n", mul);

P-5.ASCII Value
    
    printf("%d\n",'a');
    printf("%c\n",97);
    printf("%X\n",'a');
   
    for(int idx = 0; idx < 257; ++idx) {
        printf("%c|%d|%X\n",idx ,idx ,idx);
    }

    char num5;
    printf("Enter a character: ");
    scanf("%c", &num5);
    printf("ASCII value of %C & %X = %d",num5 ,num5 ,num5);

P-6.Quotient and Remainder

    int dividend, divisor, quo, rem;
    
    printf("Enter dividend: ");
    scanf("%d",&dividend);
    printf("Enter divisor: ");
    scanf("%d",&divisor);
    quo = dividend / divisor;
    rem = dividend % divisor;

    printf("Quotient = %d\n", quo);
    printf("Remainder = %d\n", rem);
    
P-7.Returned the result by sizeof()

    int intType;
    float floatType;
    double doubleType;
    char charType;
    short shortType;
    long longType;
    long longdouType;
    unsigned int unintType;
    unsigned short unshortType;
    unsigned long unlongType;
    unsigned long long unlongdouType;

    printf("Size of int: %lu bytes\n", sizeof(intType));
    printf("Size of float: %lu bytes\n", sizeof(floatType));
    printf("Size of double: %lu bytes\n", sizeof(doubleType));
    printf("Size of char: %lu bytes\n", sizeof(charType));
    printf("Size of short: %lu bytes\n", sizeof(shortType));
    printf("Size of long: %lu bytes\n", sizeof(longType));
    printf("Size of long long: %lu bytes\n", sizeof(longdouType));
    printf("Size of unsigned int: %lu bytes\n", sizeof(unintType));
    printf("Size of unsigned short: %lu bytes\n", sizeof(unshortType));
    printf("Size of unsigned long: %lu bytes\n", sizeof(unlongType));
    printf("Size of unsigned long long: %lu bytes\n", sizeof(unlongdouType));

    printf("Size of int: %zu bytes\n", sizeof(intType));
    printf("Size of float: %zu bytes\n", sizeof(floatType));
    printf("Size of double: %zu bytes\n", sizeof(doubleType));
    printf("Size of char: %zu bytes\n", sizeof(charType));
    printf("Size of short: %zu bytes\n", sizeof(shortType));
    printf("Size of long: %zu bytes\n", sizeof(longType));
    printf("Size of long long: %zu bytes\n", sizeof(longdouType));
    printf("Size of unsigned int: %zu bytes\n", sizeof(unintType));
    printf("Size of unsigned short: %zu bytes\n", sizeof(unshortType));
    printf("Size of unsigned long: %zu bytes\n", sizeof(unlongType));
    printf("Size of unsigned long long: %zu bytes\n", sizeof(unlongdouType));

P-9.Swap numbers using temporary variable
    

    double num6, num7, temp;
    printf("Enter frist number: ");
    scanf("%lf", &num6);
    printf("Enter second number: ");
    scanf("%lf", &num7);
    
    temp = num6;
    num6 = num7;
    num7 = temp;

    printf("After swapping, frist number = %.2lf\n", num6);
    printf("After swapping, second number = %.2lf\n", num7);

P-9.[with rand function]
        
    double num8, num9, num10;
    printf("Enter frist number: ");
    scanf("%lf", &num8);
    printf("Enter second number: ");
    scanf("%lf", &num9);
    printf("Enter third number: ");
    scanf("%lf", &num10);

    srand(time(NULL));
    int random_index1 = rand()%3;
    
    double random_num;
    if(random_index1 == 0){
        random_num = num8;
    }else if(random_index1 == 1){
        random_num = num9;
    }else{
        random_num = num10;
    }

    printf("Random number = %.2lf\n",random_num);

P-10.Check number is even or odd
   
    int num11;
    printf("Enter number: ");
    scanf("%d", &num11);

    if(num11 % 2 == 0){
        printf("%d is even.", num11);
    } else {
        printf("%d is odd.", num11);
    }

P-11.Check character is vowel or consonant

    char char1;
    printf("Enter an alphabet: ");
    scanf("%c", &char1);

    
    if(char1 == 'a' || char1 == 'e' || char1 == 'i' || char1 == 'o' || char1 == 'u' || char1 == 'A' || char1 == 'E' || char1 == 'I' || char1 == 'O' || char1 == 'U'){
        printf("%c is a vowel.\n", char1);
} else {
        printf("%c is a consonant.\n", char1);
}


P-11.[with strchr function]Check character is vowel or consonant

    char char2;
    printf("Enter an alphabet: ");
    scanf("%c", &char2);

    char vowel[] = "aeiouAEIOU";
    if (strchr(vowel, char2)){
            printf("%c is a vowel.\n", char2);
    } else {
            printf("%c is a consonant.\n", char2);
    }

P-12.[with &&]Find the largest number among three numbers
        
    double num121, num122, num123;
    
    printf("Enter three different number: ");
    scanf("%lf %lf %lf", &num121, &num122, &num123);

    if(num121>=num122 && num121>=num123)
        printf("%.2lf is the largest number.\n", num121);
    if(num122>=num121 && num122>=num123)
        printf("%.2lf is the largest number.\n", num122);
    if(num123>=num121 && num123>=num122)
        printf("%.2lf is the largest number.\n", num123);

P-12.[with else]Find the largest number among three numbers

    double num121, num122, num123;
    
    printf("Enter three different number: ");
    scanf("%lf %lf %lf", &num121, &num122, &num123);

    if(num121>=num122 && num121>=num123){
        printf("%.2lf is the largest number.\n", num121);
    }else if(num122>=num121 && num122>=num123){
        printf("%.2lf is the largest number.\n", num122);
    }else{
        printf("%.2lf is the largest number.\n", num123);
    }

P-12.[with nested if...else]Find the largest number among three numbers

    double num121, num122, num123;
    
    printf("Enter three different number: ");
    scanf("%lf %lf %lf", &num121, &num122, &num123);

    if(num121>=num122){
        if(num121>=num123)
            printf("%.2lf is the largest number.\n", num121);
        else
            printf("%.2lf is the largest number.\n", num123);
    }
    else{
        if(num122>=num123)
            printf("%.2lf is the largest number.\n", num122);
        else
            printf("%.2lf is the largest number.\n", num123);
    }

P-12.[with assume a value]Find the largest number among three numbers

    double num121, num122, num123;
    
    printf("Enter three different number: ");
    scanf("%lf %lf %lf", &num121, &num122, &num123);

    double largestnum = num121;

    if(num122 > largestnum){
        largestnum = num122;
    }
    if(num123 > largestnum){
        largestnum = num123;
    }

    printf("%.2lf is the largest number.\n", largestnum);

P-13.Find Roots of a Quadratic Equation

    double a,b,c;
    printf("Enter coefficients a, b and c: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    
    double discriminant, root1, root2, realPart, imagPart;
    discriminant = b*b-4*a*c;
    
    if(discriminant>0){
        root1 = (-b+sqrt(discriminant))/(2*a);
        root2 = (-b-sqrt(discriminant))/(2*a);
        printf("root1 = %.2lf and root2 = %.2lf\n", root1, root2);
    }else if(discriminant==0){
        root1 = root2 = -b/(2*a);
        printf("root1 = root2 = %.2lf\n", root1);
    }else{
        realPart = -b/(2*a);
        imagPart = sqrt(-discriminant)/(2*a);
        printf("root1 = %.2lf+%.2lfi and root2 = %.2lf-%.2lfi",realPart, imagPart, realPart, imagPart);
    }

P-14.Calculate the sum of natural numbers

    int sumnum = 0;
    for (int num = 1; num <=10; ++num){
         sumnum += num;
      }
    printf("total: %d\n",sumnum);
    
P-14.[with wile]Calculate the sum of natural numbers
    
    int i=1,sumnum=0;

    while(i<=10){
        sumnum += i;
        ++i;
    }
    printf("total: %d\n", sumnum);

P-14.[with wile & do]Calculate the sum of natural numbers

    int n, i, sum=0;
    
    do{
        printf("Enter a positive integer: ");
        scanf("%d", &n);
    }while (n<=0);
                    
    for (i=1; i<=n; ++i){
        sum += i;
    }

    printf("total = %d\n",sum);

P-18.Factorial of number

    int num15, i ;
    unsigned long long fact = 1 ;
    
    do {
    printf("Enter an integer: ");
    scanf("%d", &num15);
        if (num15 <= 0){
        }    printf("Error! Please Enter positive number.\n ");
    }while(num15 < 0);
        
    for (i = 1; i <= num15 ; ++i){
            fact *= i ;
    }
    printf("Factorial of %d = %llu\n", num15, fact);

P-19. Multiplication table up to a range

    int num19, i, mulrange = 1;
    printf("Enter an integer: ");
    scanf("%d", &num19);
    printf("Enter a range: ");
    scanf("%d", &mulrange);
    
    for (i = 1 ; i <= mulrange ; ++i ){
        printf("%d * %d = %d\n", num19, i , num19*i);
    }
    
P-19.[99 multable + separator]Multiplication table up to a range

    int i, r ;
    for (i = 1; i <= 9 ; ++i){
        if (i > 1){
            printf("-------------------------\n");
        }
        for ( r = 1; r <= 9 ; ++r )          
        printf("%d * %d = %d\n", i, r, i * r);
    }    

P-20.Display Fibonacci Sequence
    
    int t1 = 0, t2 = 1, nextterm = t1 + t2 ;    
  
    while (nextterm <= 100){    
        printf("%d, ", nextterm);
        nextterm = t1 + t2;
        t1 = t2;
        t2 = nextterm;
    }

*/
    int arr[5] = {1, 2, 3, 4, 5};
    
    for (int i = 0 ; i < 5 ; i++){
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    
    printf("-----------------------End-------------------------\n");
    return ;
}    

int joeyoung_calc(int a, int b) {
    return a + b;
}

int joeyoung_do_somthing(void) {

    if (error) {
        return -1;
    }

    return 0;
}

int main(int argc, char *argv[]) {

/*	for (int idx = 0; idx < 10 ; ++idx){
		printf("idx = %d\n",idx);
	}

*/    
   
    if (joeyoung_do_something()) {
        printf("%s() joeyoung_do_something : error \r\n", __func__);
    }


    srand(time(NULL));

    int random_index= rand()%3;

    if(random_index ==0) {
        printf("-------------------- Fighting ---------------------\n");
    } 
    else if(random_index ==1) {
        printf("----------------- You can do it! ------------------\n");
    }
    else{
        printf("----------------- Keep pushing! -------------------\n");
    }

    
    otherfunction();

    printf("joeyoung calc : %d\r\n", joeyoung_calc(200, 30));
    printf("joeyoung calc : %d\r\n", joeyoung_calc(20, 30));

    return -1;
}

