#include<stdio.h>

int space[11][11];
int paper[5] = { 5, 5, 5, 5, 5 };
int result = 26;

int pair[101][2], count = 0;
bool possible_attach(int p, int q, int flag)
{
	if (flag == 4) {
		if (paper[4] > 0 && (p + 4 < 10) && (q + 4 < 10)) {
			int check = 1;
			for (int i = p; i < p + 5; i++) {
				for (int j = q; j < q + 5; j++) {
					if (!space[i][j]) { check = 0; i = 10; j = 10; }
				}
			}
			if (check) {
				for (int i = p; i < p + 5; i++)
					for (int j = q; j < q + 5; j++) space[i][j] = 0;

				paper[4]--;
				return true;
			}
		}
		return false;
	}

	if (flag == 3) {
		if (paper[3] > 0 && (p + 3 < 10) && (q + 3 < 10)) {
			int check = 1;
			for (int i = p; i < p + 4; i++) {
				for (int j = q; j < q + 4; j++) {
					if (!space[i][j]) { check = 0; i = 10; j = 10; }
				}
			}
			if (check) {
				for (int i = p; i < p + 4; i++)
					for (int j = q; j < q + 4; j++) space[i][j] = 0;

				paper[3]--;
				return true;
			}
		}
		return false;
	}

	if (flag == 2) {
		if (paper[2] > 0 && (p + 2 < 10) && (q + 2 < 10)) {
			int check = 1;
			for (int i = p; i < p + 3; i++) {
				for (int j = q; j < q + 3; j++) {
					if (!space[i][j]) { check = 0; i = 10; j = 10; }
				}
			}
			if (check) {
				for (int i = p; i < p + 3; i++)
					for (int j = q; j < q + 3; j++) space[i][j] = 0;

				paper[2]--;
				return true;
			}
		}
		return false;
	}

	if (flag == 1) {
		if (paper[1] > 0 && (p + 1 < 10) && (q + 1 < 10)) {
			int check = 1;
			for (int i = p; i < p + 2; i++) {
				for (int j = q; j < q + 2; j++) {
					if (!space[i][j]) { check = 0; i = 10; j = 10; }
				}
			}
			if (check) {
				for (int i = p; i < p + 2; i++)
					for (int j = q; j < q + 2; j++) space[i][j] = 0;

				paper[1]--;
				return true;
			}
		}
		return false;
	}

	if (flag == 0) {
		if (paper[0] > 0) {
			space[p][q] = 0;
			paper[0]--;
			return true;
		}
		return false;
	}
}

void dfs(int one) {
	if (one == count) {
		int tmp = 25;
		for (int i = 0; i < 5; i++) tmp -= paper[i];
		if (tmp < result) result = tmp;
	
		return;
	}

	int p = pair[one][0], q = pair[one][1];

	if (space[p][q]) {
		if (possible_attach(p, q, 4)) {
			dfs(one + 1);
			for (int i = p; i < p + 5; i++)
				for (int j = q; j < q + 5; j++) space[i][j] = 1;
			paper[4]++;
		}
		if (possible_attach(p, q, 3)) {
			dfs(one + 1);
			for (int i = p; i < p + 4; i++)
				for (int j = q; j < q + 4; j++) space[i][j] = 1;
			paper[3]++;
		}
		if (possible_attach(p, q, 2)) {
			dfs(one + 1);
			for (int i = p; i < p + 3; i++)
				for (int j = q; j < q + 3; j++) space[i][j] = 1;
			paper[2]++;
		}
		if (possible_attach(p, q, 1)) {
			dfs(one + 1);
			for (int i = p; i < p + 2; i++)
				for (int j = q; j < q + 2; j++) space[i][j] = 1;
			paper[1]++;
		}

		if (possible_attach(p, q, 0)) {
			dfs(one + 1);
			space[p][q] = 1;
			paper[0]++;
		}
		else return;
	}
	else dfs(one + 1);
}
int main()
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++) {
			scanf("%d", &space[i][j]);
			if (space[i][j]) {
				pair[count][0] = i; pair[count][1] = j;
				count++;
			}
		}

	dfs(0);

	if(result == 26) printf("-1\n");
	else printf("%d\n", result);

	return 0;
}