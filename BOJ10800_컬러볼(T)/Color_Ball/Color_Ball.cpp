#include<stdio.h>
#include<stdlib.h>
#pragma warning (disable : 4996)

int n;

int score[200001];
int color[4] = { 0, 0, 0, 0 };
int sum = 0;

typedef struct ball {
	int color;
	int count;
	int seat;
} Ball;
//void swap(int *p, int *q);

Ball ball[200001] = { 0, };

int compare(const void *arg1, const void *arg2) {
	Ball *a = (Ball *)arg1;
	Ball *b = (Ball *)arg2;

	if (a->count > b->count) return 1;
	else if (a->count == b->count) return 0;
	else return -1;
}

int main()
{
	int check = 0;
	
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &ball[i].color, &ball[i].count);
		ball[i].seat = i + 1;
	}
	qsort(ball, n, sizeof(ball), compare);
	/*
	for (int i = 0; i < n-1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (ball[i][1] > ball[j][1]) {
				swap(&ball[i][0], &ball[j][0]);
				swap(&ball[i][1], &ball[j][1]);
				swap(&seat[i], &seat[j]);
			}
			
			else if (ball[i][1] == ball[j][1] && ball[i][0] > ball[j][0]) {
				swap(&ball[i][0], &ball[j][0]);
				swap(&ball[i][1], &ball[j][1]);
				swap(&seat[i], &seat[j]);
			}
		}
	}*/

	for (int i = 0; i < n; i++) {
		score[ball[i].seat - 1] = sum - color[ball[i].color-1] - check;
		sum += ball[i].count;
		color[ball[i].color - 1] += ball[i].count;

		if (ball[i].count == ball[i + 1].count) check += ball[i].count;
		if (ball[i].count != ball[i + 1].count) check = 0;
	}

	for (int i = 0; i < n; i++)
		printf("%d\n", score[i]);

	return 0;
}

/*
void swap(int *p, int *q)
{
	int temp = *p;
	*p = *q;
	*q = temp;
}
*/