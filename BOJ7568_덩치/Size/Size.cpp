#include<stdio.h>
#pragma warning (disable : 4996)
int n, h[51][2];

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &h[i][0], &h[i][1]);

	for (int i = 0; i < n; i++) {
		int cnt = 1;
		for (int j = 0; j < n; j++) {
			// i == j�� ���� �����Կ� Ű�� ���� ������ ����� ������ ����
			if (h[i][0] < h[j][0] && h[i][1] < h[j][1])
				cnt++;
		}
		printf("%d ", cnt);
	}
	printf("\n");
	return 0;
}