// Online C compiler to run C program online
#include <stdio.h>

typedef struct var {
    int (*func_ptr)(int x,int y);
    int *ptr1;
} var1;

int sum(int a, int b){
    int result = a+b;
    printf("Result is : \n%d",result);
    return result;
}

int main() {
    // Write C code here
    var1 op;
    int b=10;
    int *a=&b;
    // printf("A: %d\n",*a);
    op.ptr1=a;
    printf("\nA is: %d\n",op.ptr1);
    (op.func_ptr)=sum;
    (op.func_ptr)(9,6); 
    return 0;
}