#include<stdio.h>

#pragma warning(disable : 4996)

int main()
{
	//freopen("input.txt", "r");

	int a[10], b[10];
	int ca = 0, cb = 0;

	for (int i = 0; i < 10; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < 10; i++)
		scanf("%d", &b[i]);

	for (int i = 0; i < 10; i++) {
		if (a[i] > b[i]) ca++;
		else if (a[i] < b[i]) cb++;
	}

	if (ca == cb) printf("D\n");
	else if (ca > cb) printf("A\n");
	else printf("B\n");

	return 0;

}