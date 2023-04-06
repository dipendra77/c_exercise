// check Endianness
#include<stdio.h>
#include<stdint.h>

typedef union checkEndian{
    uint16_t data;
    uint8_t byte[2];
} RawData;

// Using asssignment to unsigned char and visually printing the variable
int check_endianness1(int number){
    
    unsigned char * c=(unsigned char *)&number;
    printf("\n0x"); 
    for(int i=0;i<sizeof(number);i++)
    {
        printf("%x", c[i]); // if this output is 78563412 it is Little Endian 
    }

    return 0;
}

// Using asssignment to unsigned char with value 1 
int check_endianness2(uint16_t number){
    unsigned char *c;
    c=(unsigned char *)&number;
    printf("\nEndianness Result: %d\n",*c);
    if(*c==1){
        printf("\nLittle Endian method 3\n");
        return 1;

    }
    else{
        printf("\nBig Endian method 3\n");
        return 0;
    }
}



// Using unions
int check_endianness3(uint32_t number){

    RawData endianness;
    endianness.data=number;
    if(endianness.byte[0] ==1)
    {
        printf("\nLittle Endian method 3\n");
    }   
    else{
        printf("\nBig Endian method 3\n");
    }
 return 0;
}

int main(){

    int num1=0x12345678;
    check_endianness1(num1);

    uint16_t num2=1;
    check_endianness2(num2);

    uint16_t num3=1;
    check_endianness3(num3);
    return 0;
}