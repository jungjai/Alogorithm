#include<stdio.h>
#pragma warning (disable : 4996)

int main()
{
	int n, x;
	scanf("%d %d", &n, &x);
	for (int i = 0; i < n; i++) {
		int com_num;
		scanf("%d", &com_num);
		if (com_num < x)
			printf("%d ", com_num);
	}

	return 0;
}