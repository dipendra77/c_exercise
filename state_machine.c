/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.


The state machine must run every 1 second and have an internal 32-bit counter. In the INC state, the counter increments, and in the DEC state it decrements.
The program must expose functions to start increment, start decrement or stop. It must also expose a function that returns the current counter value.
*******************************************************************************/


#include <stdio.h>
#include <time.h>
int counter=0;


void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;
 
    // Storing start time
    clock_t start_time = clock();
 
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}
 
 
int increment()
{
    counter++;
    return counter;
    
}

int decrement(){
    counter--;
    return counter;
    
}

int stop(){
    printf("Counter value is : %d \n",counter);
    return counter;
}

int main()
{
    
    enum state_code
    {
        INIT=0,
        DEC,
        INC,
        STOP
        
    };
    
    while(1)
    {
        int rec;
        printf("Enter a number: ");
        scanf("%d",&rec);
        int state=rec;
        printf("Entered state is: %d\n",state);
        switch(state)
        {
            case INIT:
                printf("Initialize \n");
                break;
            case INC:
                printf("Increment \n");
                increment();
                break;
            case DEC:
                printf("Decrement \n");
                decrement();
                break;
            case STOP:
                printf("STOP \n");
                stop();
                break;
        }
        delay(1);
            
    }
    
    return 0;
}

