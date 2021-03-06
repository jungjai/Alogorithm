#include<stdio.h>
#pragma warning (disable : 4996)
int N, M, fr[5001][2]; //fr : freind relationship
int person;
int visit[101];

void relation(int p);
void dfs(int a, int b, int su);
int main()
{
	scanf("%d %d", &N, &M);
	int result = 0, num = 0;;
	for (int i = 0; i < M; i++) scanf("%d %d", &fr[i][0], &fr[i][1]);

	for (int i = 1; i <= N; i++) {
		person = 0;
		relation(i);
		if (person < result || i == 1) {
			result = person;
			num = i;
		}
	}
	printf("%d",num);
    return 0;
}

void relation(int p)
{
	for (int i = 1; i <= N; i++) {
		if (p != i) {
			for (int j = 1; j <= N; j++) visit[j] = 0;
			dfs(p, i, 1);
		}
	}
}

void dfs(int a, int b, int su)
{
	if (visit[a] == 0) {
		int check = 0;
		for (int i = 0; i < M; i++) {
			if ((fr[i][0] == a && fr[i][1] == b) || (fr[i][0] == b && fr[i][1] == a)) {
				check = 1; i = M;
			}
		}

		if (check == 1) person += su;
		else {
			visit[a] = 1;
			for (int i = 0; i < M; i++) {
				if (fr[i][0] == a)
					dfs(fr[i][1], b, su + 1);
				else if (fr[i][1] == a)
					dfs(fr[i][0], b, su + 1);
			}
		}
	}
}
