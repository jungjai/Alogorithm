#include <stdio.h>

int main()
{
	char arr[100];
	int len = 0, count = 0;

	scanf("%s", arr);

	while (arr[len])
	{
		len++;
	}

	for (int i = 0; i < len; i++)
	{
		if (arr[i] == 'c' && (arr[i + 1] == '=' || arr[i + 1] == '-'))
			count++;

		if (arr[i] == 'd' && (arr[i + 1] == '-' || (arr[i + 1] == 'z' && arr[i + 2] == '=')))
			count++;

		if (arr[i] == 'j' && (arr[i - 1] == 'l' || arr[i - 1] == 'n'))
			count++;

		if (arr[i] == '=' && (arr[i - 1] == 's' || arr[i - 1] == 'z'))
			count++;

	}
	len = len - count;
	printf("%d", len);
	return 0;

}