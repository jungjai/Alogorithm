#include<stdio.h>

#pragma warning(disable : 4996)

int data(int); 
int data1(int, int, char **);

int main()
{
	printf("%d", data(5));
}
int data(int su)
{
	if (su == 5) { data(1); data1(1); }
	else if (su == 1) return 3;
}

int data1(int suss)
{

	return 2;
}