#include<stdio.h>
#include<stdint.h>
#include<ctype.h>
#include<math.h>
#include<string.h>

// 2 & 3 only works for Upper cap Hex characters

int hex_to_decimal_1(char *hexNo){
    int decimalNumber=0;
    uint8_t digit=0;
    for( int i = strlen(hexNo) - 1  ; i >= 0; i-- ) 
    {
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
        decimalNumber += ( digit * pow( 16,strlen( hexNo ) - i - 1) );
     }
    printf("Decimal 1 no. is : %d\n",decimalNumber);
    return decimalNumber;

}


int hex_to_decimal_2(char *hexNo){
    int decimalNumber=0;
    uint8_t digit=0;
    for( int i = strlen(hexNo) - 1  ; i >= 0; i-- ) 
    {
        // printf("%c",hexNo[i]));

        switch( tolower(hexNo[i]) )
        {
            case 'a':
            case 'b':
            case 'c':
            case 'd':
            case 'e':
            case 'f':
                digit = ( hexNo[i] - 55 );
                break;
            default:
                digit=( hexNo[i] - 48 );
                break;
        }
        printf("Digit 2 is: %d\n",digit);
        decimalNumber += ( digit * pow( 16,strlen( hexNo ) - i - 1) );
     }
    printf("Decimal 2 no. is : %d\n",decimalNumber);
    return decimalNumber;

}


int hex_to_decimal_3(char *hex)
{
    int decimalNum = 0;
    int base = 1;
    for(int i = strlen(hex) - 1; i >= 0; i--)
    {
        if( tolower(hex[i]) >= '0' && tolower(hex[i] <= '9' ))
        {
            decimalNum += (hex[i]- 48 ) * base;
            base = base * 16;
        }
        else if( tolower( hex[i]) >= 'a' && tolower( hex[i] <= 'f' ))
        {
            decimalNum += ( hex[i]- 55 ) * base;
            base = base * 16;
        }
        
    }
    printf("Decimal 3 is: %d\n",decimalNum);
    return decimalNum;
}

int main(){
    // char hex[] = "F2";
    char *hex;
    gets(hex);
    hex_to_decimal_1(hex);
    hex_to_decimal_2(hex);
    hex_to_decimal_3(hex);
    return 0;
}