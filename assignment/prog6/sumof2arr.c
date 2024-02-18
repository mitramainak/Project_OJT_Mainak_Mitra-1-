

#include<stdio.h>
#include"header6.h"

int main(){
int arr[5];

int arr1[5];
int i;

for(i=0;i<5;i++){
	scanf("%d",&arr[i]);
}
for(i=0;i<5;i++){
	scanf("%d",&arr1[i]);

}
	printf("%d",fun6(arr,arr1));



}
