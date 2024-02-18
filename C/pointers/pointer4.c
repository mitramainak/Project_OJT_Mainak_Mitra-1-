// C Program to access array elements using pointer
#include <stdio.h>

void geeks()
{
	// Declare an array
	int val[3] = { 5, 10, 15 };

	// Declare pointer variable
	int* ptr;

	// Assign address of val[0] to ptr.
	// We can use ptr=&val[0];(both are same)
	ptr = val;

	printf("Elements of the array are: ");

	printf("%d, %d, %d", ptr[0], *(ptr+1), ptr[2]);

	return;
}

// Driver program
int main()
{
	geeks();
	return 0;
}

