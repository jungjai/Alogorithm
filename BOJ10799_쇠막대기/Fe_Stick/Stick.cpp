#include<stdio.h>
#include<string.h>
#pragma warning(disable : 4996)

char str[100001];

void checkstick();

int main()
{
	scanf("%s", str);
	checkstick();
	return 0;
}

void checkstick()
{
	int len, stick = 0;
	len = strlen(str);
	
	int cstr[100001], clen = 0;
	for (int i = 0; i < len; i++) {
		if (str[i] == '(' && str[i + 1] != ')' && i != len-1) {
			cstr[clen] = -1;
			clen++;
		}
		else if (str[i] == '(' && str[i + 1] == ')' && i != len - 1) {
			if (clen != 0 && cstr[clen - 1] >= 1) cstr[clen - 1]++;
			else {
				cstr[clen] = 1;
				clen++;
			}
			i++;
		}
		else if(str[i] == ')') {
			//printf("%d %d\n", i, cstr[clen - 1]);
			stick += (cstr[clen - 1] + 1);
			int ch = 0, detail = 0;
			while (!(cstr[clen - 1] == -1 && ch == 1) && clen >0) {
				if (cstr[clen - 1] == -1) ch++;
				else
					detail += cstr[clen - 1];
				cstr[clen - 1] = 0;
				clen--;
			}
			cstr[clen] = detail;
			clen++;
		}
	}
	printf("%d\n", stick);
}