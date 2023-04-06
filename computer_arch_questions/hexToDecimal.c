#include<stdio.h>
#include<stdint.h>
#include<ctype.h>
#include<math.h>
#include<string.h>

int hex_to_decimal(char *hexNo){
    int decimalNumber=0;
    uint8_t digit=0;
    for(int i=0;i<=strlen(hexNo)-1;i++){
        // printf("%c",hexNo[i]));

        switch(tolower(hexNo[i])){
            case 'a':
                digit=10;
                break;
            case 'b':
                digit=11;
                break;
            case 'c':
                digit=12;
                break;
            case 'd':
                digit=13;
                break;
            case 'e':
                digit=14;
                break;
            case 'f':
                digit=15;
                break;
            default:
                digit=(hexNo[i] - 48 );
                break;
        }
        printf("Digit is: %d\n",digit);
        decimalNumber+=(digit*pow(16,i));
     }
    printf("Decimal no. is : %d\n",decimalNumber);
    return decimalNumber;

}


int main(){
    char hex[] = "F2";
    hex_to_decimal(hex);
    return 0;
}