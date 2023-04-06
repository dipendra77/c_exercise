// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

typedef struct var {
    int (*ptr)(int x,int y);
    int *ptr1;
} var1;

int sum(int a, int b){
    int result = a+b;
    printf("Result of func ptr is : %d \n",result);
    return result;
}

int main() {
    // Write C code here
    var1 op;
    op.ptr1=malloc(sizeof(op.ptr1));  // assigining memory to the pointer is mandatory 
    int b=10;
    *op.ptr1=b;
    printf("Result of pointer to a variable of struct type is: %d\n",*op.ptr1);
    // int * temp;
    // temp=&b;
    // printf("Result of pointer  variable : %d\n",temp);

    op.ptr=&sum;    // or op.ptr=sum
    (op.ptr)(5,6); 
    return 0;
}