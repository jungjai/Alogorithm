#pragma warning(disable : 4996)

#include <stdio.h>
#include <string.h>
#include <algorithm>

#define INF (int)2e9

using namespace std;

int go(int);

int T, N;
int D[12];

int main(void)
{
	scanf("%d", &T);

	while (T--) {
		memset(D, -1, sizeof(D));
		scanf_s("%d", &N);

		printf("%d\n", go(0));
	}

	return 0;
}

int go(int n)
{
	if (n > N)
		return 0;

	if (n == N)
		return 1;

	int& ret = D[n];

	if (ret != -1)
		return ret;

	ret = go(n + 1) + go(n + 2) + go(n + 3);

	return ret;
}