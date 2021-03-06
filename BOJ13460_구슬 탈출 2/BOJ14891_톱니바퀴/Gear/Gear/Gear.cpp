#include <stdio.h> 

int block[4][8];
bool check[3];
int K;
int N, D;

void moveFunc(int, int);
void SolveFunc(int, int);

int main()
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			scanf("%1d", &block[i][j]);
		}
	}
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		check[0] = check[1] = check[2] = false;

		scanf("%d %d", &N, &D);
		for (int j = 0; j < 3; j++) {
			if (block[j][2] != block[j + 1][6]) check[j] = true;
		} SolveFunc(N, D);
	}
	int ans = 0; 

	if (block[0][0]) 
		ans += 1; 
	if (block[1][0]) 
		ans += 2;
	if (block[2][0]) 
		ans += 4;
	if (block[3][0])
		ans += 8; 
	printf("%d\n", ans); 
	return 0;
}

void SolveFunc(int n, int dir) 
{
	if (n == 1) {
		moveFunc(0, dir);
		if (check[0]) {
			moveFunc(1, -dir);
			if (check[1]) {
				moveFunc(2, dir);
				if (check[2]) {
					moveFunc(3, -dir);
				}
			}
		}
	}
	else if (n == 2) {
		moveFunc(1, dir);
		if (check[0]) moveFunc(0, -dir);
		if (check[1]) {
			moveFunc(2, -dir);
			if (check[2]) {
				moveFunc(3, dir);
			}
		}
	}
	else if (n == 3) {
		moveFunc(2, dir);
		if (check[2]) moveFunc(3, -dir);
		if (check[1]) {
			moveFunc(1, -dir);
			if (check[0]) {
				moveFunc(0, dir);
			}
		}
	}
	else if (n == 4) {
		moveFunc(3, dir);
		if (check[2]) {
			moveFunc(2, -dir);
			if (check[1]) {
				moveFunc(1, dir);
				if (check[0]) {
					moveFunc(0, -dir);
				}
			}
		}
	}
}

void moveFunc(int idx, int dir)
{
	int temp;
	if (dir == 1) {
		temp = block[idx][7];
		for (int i = 6; i >= 0; i--) { block[idx][i + 1] = block[idx][i]; }
		block[idx][0] = temp;
	}
	else if (dir == -1) {
		temp = block[idx][0];
		for (int i = 1; i < 8; i++) { block[idx][i - 1] = block[idx][i]; }
		block[idx][7] = temp;
	}
}