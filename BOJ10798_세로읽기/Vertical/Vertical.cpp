#include<stdio.h>
#include<string.h>

#pragma warning (disable : 4996)

int main()
{
	char str[6][16];
	int len[5], max = 0;

	for (int i = 0; i < 5; i++) {
		scanf("%s", str[i]);
		len[i] = strlen(str[i]);
		if (max < len[i]) max = len[i];
	}

	for (int i = 0; i < max; i++) {
		for (int j = 0; j < 5; j++) {
			if (i < len[j]) printf("%c", str[j][i]);
		}
	}
	return 0;
}