#include<stdio.h>
#include<string.h>
#pragma warning (disable : 4996)

char dish[51];

int main()
{
	int height = 0, check = -1;
	scanf("%s", dish);

	for (int i = 0; i < strlen(dish); i++)
	{
		if (dish[i] == '(') {
			if (check == 1 || check == -1) height += 10;
			else height += 5;

			check = 0;
		}
		else if (dish[i] == ')') {
			if (check == 0 || check == -1) height += 10;
			else height += 5;

			check = 1;
		}
	}

	printf("%d\n", height);

	return 0;
}