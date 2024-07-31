/*
Program to display no. of occurencer of a character in a string.
Eg: input String: aabbccde
    Output String: 2a2b2c1d1e 
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void char_occurence_number();

int main(){
	char_occurence_number();	
	return 0;
}


void char_occurence_number(){

char a[]= "ccaaabbd";
int size=sizeof(a);
char out[size];
int count=1;
int id=0;

for(int i=0;a[i]!='\0';i++)
{
	if(a[i]==a[i+1])
	{
	count++;
// 	printf("Count is : %d\n",count);
	
	}
	else
	{
		printf("Count of : %c : %d \n",a[i],count);
		
		sprintf(out+id,"%d", count);
		id++;
		out[id] = a[i];
		id++;
		count=1;

	}
}


printf("%s",out);

}
