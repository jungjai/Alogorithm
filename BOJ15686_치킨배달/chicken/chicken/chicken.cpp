#include <stdio.h>
#include <math.h>

#pragma warning (disable : 4996)

int N, M, chic = 0, house[50][50], min= 2147483647;


int chicken(int di[][50][15], int ch, int start);
int main()
{
	freopen("input.txt", "r", stdin);

	
	int dis[50][50][15];
	scanf("%d %d", &N, &M);	

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &house[i][j]);
			dis[i][j][0] = 2147483647;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (house[i][j] == 2) {
				chic++;
				for (int p = 0; p < N; p++) {
					for (int q = 0; q < N; q++) {
						if (house[p][q] == 1) dis[p][q][chic] = abs(i - p) + abs(j - q);
					}
				}
			}
		}
	}
	
	chicken(dis, M-1, 1);
	printf("%d\n", min);

	return 0;
}

int chicken(int di[][50][15], int ch, int start) {
	int d_copy[50][50][15];
	for (int i = start; i <= chic; i++) {
		for (int j = 0; j < N; j++) {
			for (int p = 0; p < N; p++) {
				if (house[j][p] == 1) {
					for (int q = 0; q <= chic; q++)
						d_copy[j][p][q] = di[j][p][q];
					if(d_copy[j][p][i] < d_copy[j][p][0]) d_copy[j][p][0] = d_copy[j][p][i];
				}
			}
		}

		if (ch > 0) {
			chicken(d_copy, ch - 1, start + 1);			
		}	
		else if (ch == 0 ) {
			int total = 0;
			for (int r = 0; r < N; r++) {
				for (int t = 0; t < N; t++) {
					if (house[r][t] == 1) total += d_copy[r][t][0];
				}
			}
			if (total < min) min = total;
		}
	}
	
	return 0;
}