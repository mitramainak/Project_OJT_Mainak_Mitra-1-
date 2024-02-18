#include<stdio.h>
#include<stdlib.h>
int fun(int a);





void logic(int s)
{
	char arr[3];
	int k,i=0;
	while(s)
	{
		k=s%10;
		arr[3-i-2]=k;
		s=s/10;
		i++;
	}
	arr[2]='\0';
	for(int i=0;i<3;i++)
		printf("%c",arr[i]);
	printf("%s",arr);


}





int main()
{

	int a,b;
	printf("Enter a: ");
	scanf("%d",&a);
	printf("Enter b: ");
	scanf("%d",&b);
	logic(fun(a)+fun(b));
}
int fun(int a)
{
	int c,r=0,i=0;
        while(a)
        {
                int d=1;
                c=a%10;
                for(int j=1;j<=i;j++)
                        d=d*2;
                r=r+c*d;
                a=a/10;
                i++;
        }
        
	
	return r;
}
