#include<stdio.h>

struct tree {
	int x;
	struct tree * l;
	struct tree * r;
};
int visit[50001];
int result = 0;
int dfs(struct tree * T, int count);
int solution(struct tree *);
int main()
{
	int N, A[101];
	tree *T;
	printf("%d", solution(T));

	return 0;
}

int dfs(struct tree * T, int count)
{
	if (visit[T->x] == 0) {
		visit[T->x] = 1;
		count++;
	}
	else visit[T->x]++;

	if (T->l != NULL) dfs(T->l, count);
	if (T->l != NULL) dfs(T->l, count);

	if (result < count) result = count;
	visit[T->x]--;
}
int solution(struct tree * T) {
	if (T->l != NULL) dfs(T->l, 1);
	if (T->l != NULL) dfs(T->l, 1);

	return result;
}