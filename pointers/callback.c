// Online C compiler to run C program online
#include <stdio.h>

// typedef struct var {
//     void (*func_ptr)((void *));
// } func;

int print_message(){
    printf("Callback Executed \n");
    return 0;
}

void function(int (*ptr)()){
    (*ptr)();
    printf("Callback Done: \n");
}


int main() {
    // Write C code here
    // void (*ptr1_callback)();
    // (ptr1_callback) = &print_message; 
    int (*ptr1_callback)(int) = print_message; 
    function((ptr1_callback));
    return 0;
}