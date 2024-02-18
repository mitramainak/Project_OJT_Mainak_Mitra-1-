#include <stdio.h>

void fun(int n);


int main()
{
	int num,n;
	printf("Enter how many numbers you want to search : \n");
	scanf("%d",&num);
	int arr1[num];
	for(int i=0;i<num;i++)
	{
		printf("Enter %d- number: \n",i);
		scanf("%d",&n);
		arr1[i]=n;
	}
	for(int i=0;i<num;i++)
	{
		fun(arr1[i]);
	}
}


void fun(int n)
{

	int k=1;long int arr[10000];
        long int i,j;
        arr[0]=2;
        for(i=3;i<=10000;i++)
        {
                int count=0;
                for(j=2;j<i;j++)
                {
                        if(i%j==0 && k<n)
                        {
                                count++;
                        }
                }
                if(count==0 && k<n)
                {
                        arr[k]=i;
                        k++;
                }
        }
 printf("the number at position %d is %ld",n,arr[n-1]);
}













