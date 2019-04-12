#include<stdio.h>

#pragma warning (disable : 4996)

int main()
{
	int su, a[51], b[51];
	int temp, min = 0;

	scanf("%d", &su);
	for (int i = 0; i < su; i++) scanf("%d", &a[i]);
	for (int i = 0; i < su; i++) scanf("%d", &b[i]);

	for (int i = 0; i < su; i++) {
		for (int j = i + 1; j < su; j++) {
			if (a[i] > a[j]) {
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
			if (b[i] < b[j]) {
				temp = b[i];
				b[i] = b[j];
				b[j] = temp;
			}
		}
	}

	for (int i = 0; i < su; i++) min += a[i] * b[i];
	printf("%d\n", min);
}