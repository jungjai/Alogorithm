#include<stdio.h>
#include<string.h>

#pragma warning (disable : 4996)

int damage = 0;
char pg[31];
int len = 0, check = 0;

int Short_hack();
void swap(char *px, char *py);

int main()
{
	freopen("input.txt", "r", stdin);

	int Test_Case;

	scanf("%d", &Test_Case);

	for (int tc = 1; tc <=Test_Case; tc++)
	{
		scanf("%d %s", &damage, pg);

		len = strlen(pg);
		check = 0;
		check = Short_hack();

		if(check == -1) printf("Case #%d: IMPOSSIBLE\n", tc);
		else printf("Case #%d: %d\n", tc, check);
	}
	
}

int Short_hack()
{
	int sh = 0, dm = 0;
	int i, j;
	char temp;

	int check_i = 0;
	int two = 1;

	for (i = 0; i < len; i++) {
		if (pg[i] == 'C') two *= 2;
		else if (pg[i] == 'S') dm += two;
	}

	if (dm <= damage) return 0;
	else {
		i = len - 1;
		while (i >= 0) {
			if (pg[i] == 'C') {
				two /= 2;

				check_i = i;
				for (j = i + 1; j < len; j++) {
					if (pg[j] == 'S') {
						swap(&pg[j], &pg[check_i]);
						check_i = j;
						dm -= two;
						sh++;
						if (dm <= damage) return sh;
					}
					else if (pg[j] == 'C')
						j = len;
				}
			}
			i--;
		}
		if (dm <= damage) return sh;
		return -1;
	}	
}

void swap(char *px, char *py)
{
	int temp = *px;
	*px = *py;
	*py = temp;
}