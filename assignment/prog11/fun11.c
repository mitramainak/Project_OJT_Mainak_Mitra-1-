
#include<stdio.h>


void mask(int num)
{
	int bitmask,num2;


	bitmask=(1<<3)|(1<<4)|(1<<5);
	

	num2=num^bitmask;

	printf("%d",num2);




}
