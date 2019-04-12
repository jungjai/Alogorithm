#include<stdio.h>

#pragma warning (disable : 4996)

int su;
int pair;
int vi[10000][2];
int virus_pc[10001];

void virus_check(int vp);

int main()
{
	freopen("input.txt", "r", stdin);

	int i, j, temp;
	
	int V = 0;

	scanf("%d", &su);
	scanf("%d", &pair);

	for (i = 0; i < pair; i++) {
		scanf("%d %d", &vi[i][0], &vi[i][1]);
		if (vi[i][0] > vi[i][1])
		{
			temp = vi[i][0];
			vi[i][0] = vi[i][1];
			vi[i][1] = temp;
		}
	}

	for (i = 2; i <=su; i++)
		virus_pc[i+1] = 0;
	virus_pc[1] = 1;

	virus_check(1);

	for (i = 2; i <= su; i++)
		if (virus_pc[i] == 1)
			V++;

	printf("%d\n", V);

	return 0;
}

void virus_check(int vp)
{
	int i;
	for (i = 0; i < pair; i++) {
		if (vi[i][0] == vp && virus_pc[vi[i][1]] != 1) {
			virus_pc[vi[i][1]] = 1;
			virus_check(vi[i][1]);
		}
		else if (vi[i][1] == vp && virus_pc[vi[i][0]] != 1) {
			virus_pc[vi[i][0]] = 1;
			virus_check(vi[i][0]);
		}
	}
}