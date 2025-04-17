

#include <stdio.h>
#include <stdint.h>




void print_8binary (uint8_t num) {

    for (int idex = 7; idex >= 0; idex--) {
        printf("%d", (num >> idex) & 1);
    }
    printf("\n");
}

#define FLAG_A 0x01 //0b00000001
#define FLAG_B 0x02 //0b00000010
#define FLAG_C 0x04 //0b00000100
#define FLAG_D 0x08 //0b00001000

void flag_management_system_for_test () {

    int flag = 0;

// A   -0-0-0-0-0-0-0-1
// C   -0-0-0-0-0-1-0-0
// |=  -0-0-0-0-0-1-0-1

    flag |= (FLAG_A | FLAG_C);
    print_binary(flag);

//flag -0-0-0-0-0-1-0-1
// B   -0-0-0-0-0-0-1-0
// &   -0-0-0-0-0-0-0-0  if(0) --> false  


    if (flag & FLAG_B) {
        printf("has been set\n");
    } else {
        printf("not set\n");
    }
    
// ~A  -1-1-1-1-1-1-1-0
//flag -0-0-0-0-0-1-0-1
// &=  -0-0-0-0-0-1-0-0  
    
    flag &= ~FLAG_A;
    print_binary(flag);

}


void confirm_network_segment_of_IPaddr () {

    uint32_t ip = (192 << 24) | (168 << 16) | (0 << 8) | 13;
    uint32_t subnet_mask = (255 << 24) | (255 << 16) | (255 << 8) | 0;
    
    uint32_t network = (ip & subnet_mask);
    printf("Network address(Hex): 0x%X\n", network);
    printf("Network address(Dec): %u.%u.%u.%u\n", (network >> 24) & 0xFF, (network >> 16) & 0xFF, (network >> 8) & 0xFF, network & 0xFF);

//------ broadcast address ------//
// ~sub 00000000,00000000,00000000,11111111
// netw   
    uint32_t broadcast = network | (~subnet_mask);



}


int main () {

    //flag_management_system_for_test();
    confirm_network_segment_of_IPaddr();
/*
    int value = 0b10110010;   //OCT=262
    int mask = 0b01000101;    //OCT=105


    printf("---------- bit ------------\n");

//value      = -1-0-1-1-0-0-1-0
//mask       = -0-1-0-0-0-1-0-1
//&(result)  = -0-0-0-0-0-0-0-0  (OCT=0) --> false

    if (value & mask) {
        printf("true\n");
        printf("value = ");
        print_binary(value);
        printf("mask  = ");
        print_binary(mask);
   }else {
        printf("false\n");
        printf("value = ");
        print_binary(value);
        printf("mask  = ");
        print_binary(mask);
   }


    printf("---------- logic ------------\n");

// value  =  OCT(262)
// mask   =  OCT(105)
// if ( 262 && 105 ) non-zero --> true    

    if (value && mask) {
        printf("true\n");
        printf("value = %d, mask = %d\n", value, mask);
    } else {    
        printf("false\n");
        printf("value = %d, mask = %d\n", value, mask);
    }

    printf("---------- (for test) ------------\n");

    value |= mask;
    printf("value = ");
    print_binary(value);

    value &= ~mask;
    printf("value = ");
    print_binary(value);

    value ^= mask;
    printf("value = ");
    print_binary(value);
*/



}


