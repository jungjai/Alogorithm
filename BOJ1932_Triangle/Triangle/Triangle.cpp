#include <stdio.h>

const int MAX = 501; 
int N, max = -1, i, j; 
int v[MAX][MAX]; 

void input() 
{ 
	scanf("%d", &N); 
	for (int i = 1; i <= N; i++) 
		for (int j = 1; j <= i; j++) 
			scanf("%d", &v[i][j]); 
} 
int main() 
{ 
	input();	
	for (i = 2; i <= N; i++) { 
		for (j = 1; j <= i; j++) { 
			int l = v[i - 1][j]; 
			int r = v[i - 1][j - 1];
			if (l > r) v[i][j] += l; 
			else v[i][j] += r; 
			
			if (max < v[i][j]) max = v[i][j];
		} 
	} 
	printf("%d\n", max); 
	return 0; 
}
