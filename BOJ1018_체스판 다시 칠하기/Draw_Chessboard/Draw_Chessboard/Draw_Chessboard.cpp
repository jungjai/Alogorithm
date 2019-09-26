#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int M, N;
char chess[51][51];
char correct_white[9][9] = { "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW" };
char correct_black[9][9] = { "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB" };
int main()
{
	scanf("%d %d", &M, &N);
	for (int i = 0; i < M; i++)
		scanf("%s", &chess[i]);
		

	int min = 64;
	for (int i = 0; i < (M - 7); i++) {
		for (int j = 0; j < (N - 7); j++) {
			int check1 = 0, check2 = 0;
			for (int k = 0; k < 8; k++) {
				char subbuff[9];
				strncpy(subbuff, chess[k+i]+j, 8);
				subbuff[8] = 0;
				
				if (strcmp(subbuff, correct_white[k])) {
					for (int p = 0; p < 8; p++) {
						if (subbuff[p] != correct_white[k][p]) check1++;
					}
				}
				if (strcmp(subbuff, correct_black[k])) {
					for (int p = 0; p < 8; p++) {
						if (subbuff[p] != correct_black[k][p]) check2++;
					}
				}
			}
			if (check1 > check2) check1 = check2;
			if (check1 < min) min = check1;
		}
	}
	printf("%d", min);
}
