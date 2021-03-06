#include<stdio.h>
#pragma warning (disable : 4996)

int main()
{
	int N, map[101][101], L;
	int result = 0;

	scanf("%d %d", &N, &L);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) scanf("%d", &map[i][j]);

	for (int i = 0; i < N; i++) {
		int check = 0;
		int same = 1;
		for (int j = 1; j < N; j++) {
			if (map[i][j] == map[i][j - 1]) same++;
			else if (map[i][j] == map[i][j - 1] + 1) {
				if (same - L < 0) {
					check = 1; j = N;
				}
				same = 1;
			}
			else if (map[i][j] == map[i][j - 1] - 1) {
				for (int z = j + 1; z <= (j + L - 1); z++) {
					if (z < N) {
						if (map[i][z] != map[i][j]) {
							check = 1; j = N;
						}
					}
					else {
						check = 1; j = N;
					}
				}
				if (j != N) {
					j += (L - 1);
					same = 0;
				}
			}
			else {
				check = 1; j = N;
			}
		}
		if (check == 0) result++;
	}

	for (int i = 0; i < N; i++) {
		int check = 0;
		int same = 1;
		for (int j = 1; j < N; j++) {
			if (map[j][i] == map[j-1][i]) same++;
			else if (map[j][i] == map[j - 1][i] + 1) {
				if (same - L < 0) {
					check = 1; j = N;
				}
				same = 1;
			}
			else if (map[j][i] == map[j - 1][i] - 1) {
				for (int z = j + 1; z <= (j + L - 1); z++) {
					if (z < N) {
						if (map[z][i] != map[j][i]) {
							check = 1; j = N;
						}
					}
					else {
						check = 1; j = N;
					}
				}
				if (j != N) {
					j += (L - 1);
					same = 0;
				}
			}
			else {
				check = 1; j = N;
			}
		}
		if (check == 0) result++;
	}
	
	printf("%d\n", result);
    return 0;
}

