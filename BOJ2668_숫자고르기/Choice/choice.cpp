#include<stdio.h>

#pragma warning(disable : 4996)
#define MAX 100

int n, su[MAX + 1], check = 0;
int choi = 0, ch[MAX];

void dfs(int choice, int K, int p);
int main()
{
	freopen("input.txt", "r", stdin);

	scanf("%d", &n);

	if (1 <= n && n <= 100)
	{
		int i, j, temp;

		for (i = 1; i <= n; i++)
			scanf("%d", &su[i]);

		for (i = 1; i <= n; i++) {
			check = 0;
			dfs(su[i], i, 1);
			if (check == 1) {
				int check2 = 1;
				for (j = 0; j < choi; j++) {
					if (ch[j] == i) check2 = 0;
				}

				if (check2 == 1) {
					ch[choi] = i;
					choi++;
				}
			}
		}

		for (i = 0; i < choi - 1; i++) {
			for (j = i + 1; j < choi; j++) {
				if (ch[i] > ch[j]) {
					temp = ch[i];
					ch[i] = ch[j];
					ch[j] = temp;
				}
			}
		}

		printf("%d\n", choi	);
		for (i = 0; i < choi; i++) printf("%d\n", ch[i]);
	}

	return 0;
}

void dfs(int choice, int K, int p)
{
	if (p < n) {
		if (K == su[choice])
			check = 1;
		else dfs(su[choice], K, p + 1);

		if (check == 1) {
			int check2 = 1;
			for (int i = 0; i < choi; i++) {
				if (ch[i] == choice) check2 = 0;
			}
			if (check2 == 1) {
				ch[choi] = choice;
				choi++;
			}
		}
	}
}