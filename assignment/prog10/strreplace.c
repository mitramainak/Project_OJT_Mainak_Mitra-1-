


#include<stdio.h>
#include"header10.h"



int main(){


	char a[30];
	gets(a);
	char b[20];
	gets(b);
	__fpurge(stdin);
	char c[20];
	gets(c);

	

		

	strreplace(a,b,c);


}



