#include<stdio.h>
#pragma warning (disable : 4996)

int max = -1000000001, min = 1000000001;
int N, su[12];
void cal(int sum, int p, int *opc);
int main()
{
	int op[4];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &su[i]);
	for (int i = 0; i < 4; i++) scanf("%d", &op[i]);

	cal(su[0], 1, op);

	printf("%d\n%d\n", max, min);
    return 0;
}

void cal(int sum, int p, int *opc)
{
	int co[4];

	for (int i = 0; i < 4; i++) co[i] = opc[i];
	if (co[0] > 0) {
		co[0]--;
		if (p == N - 1) {
			if (max < (sum + su[p])) max = sum + su[p];
			if (min > (sum + su[p])) min = sum + su[p];
		}
		else cal(sum + su[p], p + 1, co);
	}
	for (int i = 0; i < 4; i++) co[i] = opc[i];
	if (co[1] > 0) {
		co[1]--;
		if (p == N - 1) {
			if (max < (sum - su[p])) max = sum - su[p];
			if (min >(sum - su[p])) min = sum - su[p];
		}
		else cal(sum - su[p], p + 1, co);
	}
	for (int i = 0; i < 4; i++) co[i] = opc[i];
	if (co[2] > 0) {
		co[2]--;
		if (p == N - 1) {
			if (max < (sum * su[p])) max = sum * su[p];
			if (min >(sum * su[p])) min = sum * su[p];
		}
		else cal(sum * su[p], p + 1, co);
	}
	for (int i = 0; i < 4; i++) co[i] = opc[i];
	if (co[3] > 0) {
		co[3]--;
		if (p == N - 1) {
			if (max < (sum / su[p])) max = sum / su[p];
			if (min >(sum / su[p])) min = sum / su[p];
		}
		else cal(sum / su[p], p + 1, co);
	}
}

