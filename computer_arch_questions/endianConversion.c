#include<stdio.h>
#include<stdlib.h>

typedef union endianness{
    uint32_t data;
    uint8_t byte[4];
}RawData;

// using unions 
int changeEndianness(uint32_t num)
{
    
    RawData urawData,uChangedData;
    urawData.data=num;
    uChangedData.byte[0]=urawData.byte[3];
    uChangedData.byte[1]=urawData.byte[2];
    uChangedData.byte[2]=urawData.byte[1];
    uChangedData.byte[3]=urawData.byte[0];

    return (uChangedData.data);
}

int main()
{
    uint32_t num=0x12345678;
    printf("Before change : 0x%x\n",num);
    
    printf("After Change : 0x%x\n",changeEndianness(num));
    return 0;
}

