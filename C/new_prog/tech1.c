#include<stdio.h>


int main()
{
	int count=0;
	char a[10];
	
	#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
	printf("Enter the string : ");
	gets(a);
	
	/*int rem,res=0;
	while(a)
	{
		rem=a%10;
		if(rem%2!=0)
			res=res+rem;
		a=a/10;
	}*/

	for(int i=0;a[i]!='\0';i++)
	{
		if(a[i]=='a')
			count++;
	}
	printf("%d",count);

}

