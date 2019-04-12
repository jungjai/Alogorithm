#include<cstdio>
#include<algorithm>
using namespace std;
int n, a[10001], b[10001], dp[10001][10];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%1d", a + n - i);
	for (int i = 0; i < n; i++) scanf("%1d", b + n - i);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 10; j++) dp[i][j] = dp[i - 1][j] + (a[i] - b[i] - j + 20) % 10;
		for (int j = 1; j < 20; j++) dp[i][j % 10] = min(dp[i][j % 10], dp[i][(j - 1) % 10] + 1);
	}
	printf("%d\n", dp[n][0]);
	return 0;
}