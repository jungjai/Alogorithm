#include<stdio.h>

#pragma warning (disable : 4996)

int x, y;
int map[52][52];
int checkLL = 10000;

int short_D(int p, int q);
void bothLL(int (*m)[52], int check, int x1, int y1, int x2, int y2);

int main()
{
	freopen("input.txt", "r", stdin);
	int k = 0;
	for (k = 0; k < 10; k++) {
		int i, j, temp;

		int ts_time = 0;

		char m[51];

		scanf("%d %d", &x, &y);

		for (i = 0; i <= x + 1; i++)
			for (j = 0; j <= y + 1; j++)
				map[i][j] = 2;

		for (i = 1; i <= x; i++) {
			scanf("%s", m);
			for (j = 1; j <= y; j++)
			{
				if (m[j - 1] == 'L')
					map[i][j] = 1;
				else
					map[i][j] = 0;
			}
		}
		for (i = 1; i <= x; i++) {
			for (j = 1; j <= y; j++) {
				if (map[i][j] == 1) {
					temp = short_D(i, j);
					if (ts_time < temp)
						ts_time = temp;
				}
			}
		}

		printf("%d\n", ts_time);
	}
}

int short_D(int p, int q)
{
	int time = 0;
	int check = 0;

	int i, j;

	for (i = q + 1; i <= y; i++) {
		if (map[p][i] == 1) {
			check = -1; checkLL = 10000;
			bothLL(map, check, p, q, p, i);
			if (checkLL != 10000 && time<checkLL)
				time = checkLL;
		}
	}

	for (i = p + 1; i <= x; i++) {
		for (j = 1; j <= y; j++) {
			if (map[i][j] == 1) {
				check = -1; checkLL = 10000;
				bothLL(map, check, p, q, i, j);
				if(checkLL !=10000 && time<checkLL)
					time = checkLL;
			}
		}
	}
	return time;
}

void bothLL(int (*m)[52], int check, int x1, int y1, int x2, int y2)
{
	int i, j;
	int m_copy[52][52];

	for (i = 0; i < x + 1; i++)
		for (j = 0; j < y + 1; j++)
			m_copy[i][j] = m[i][j];

	check++;

	if (x1 == x2 && y1 == y2) {
		if (checkLL > check) 
			checkLL = check;
	}
	else {
		
		m_copy[x1][y1] = 0;

		if (m_copy[x1 + 1][y1] == 1)
			bothLL(m_copy, check, x1 + 1, y1, x2, y2);	

		if (m_copy[x1][y1 + 1] == 1) 
			bothLL(m_copy, check, x1, y1 + 1, x2, y2);

		if (m_copy[x1 - 1][y1] == 1) 
			bothLL(m_copy, check, x1 - 1, y1, x2, y2);
	
		if (m_copy[x1][y1 - 1] == 1) 
			bothLL(m_copy, check, x1, y1 - 1, x2, y2);
		
	}
}