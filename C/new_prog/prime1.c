

#include<stdio.h>


int main()
{
	int range=21;
	
	for(int i=1;i<range;i++)
	{
		int count=0;
		for(int j=1;j<i;j++)
		{
			if(i%j==0)
			{
				count++;
			}
		}
		if(count==1)
		{
			printf("%d\t",i);
		}
	}
}
