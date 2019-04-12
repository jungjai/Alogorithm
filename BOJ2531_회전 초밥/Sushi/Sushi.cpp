#include <stdio.h>

#pragma warning(disable :4996)

int N, D, K, C;
int sushi[30000 + 3000 + 3];
int cur_cnt[3000 + 3], cur_ans;

int max(int a, int b)
{
	if (a >= b) return a;
	else return b;
}
void push(int sushi_num) {
	if (!cur_cnt[sushi_num]) ++cur_ans;
	++cur_cnt[sushi_num];
}

void pop(int sushi_num) {
	--cur_cnt[sushi_num];
	if (!cur_cnt[sushi_num]) --cur_ans;
}

int main() {
	scanf("%d %d %d %d", &N, &D, &K, &C);
	for (int i = 0; i < N; ++i)
		scanf("%d", &sushi[i]);

	for (int i = 0; i < K - 1; ++i)
		sushi[i + N] = sushi[i];

	push(C);
	for (int i = 0; i < K - 1; ++i)
		push(sushi[i]);

	int ans = 0;
	for (int i = 0; i < N; ++i) {
		push(sushi[i + K - 1]);
		ans = max(ans, cur_ans);
		pop(sushi[i]);
	}

	printf("%d\n", ans);

	return 0;
}