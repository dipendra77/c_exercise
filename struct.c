#include<stdio.h>
#include<stdlib.h>

typedef struct abc{
    char b;
    int a;
    char c;
    uint8_t d;
    int e;
} xyz[2];

int main(){
    xyz[2] f[2];

    printf("Size of struct: %d\n",sizeof());
    return 0;
}