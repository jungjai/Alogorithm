#include<stdio.h>

#pragma warning (disable : 4996)

int su, list[100001], list_c[100001];

void Sort();
void TroubleSort();
int Compare();

int main()
{
	freopen("input.txt", "r", stdin);

	int Test_Case;

	scanf("%d", &Test_Case);

	for (int tc = 1; tc <= Test_Case; tc++)
	{
		
		int i;
		int check;

		scanf("%d", &su);
		list[su] = -1;
		for (i = 0; i < su; i++) {
			scanf("%d", &list[i]);
			list_c[i] = list[i];
		}
		Sort();
		TroubleSort();
		check = Compare();
		if (check == -1) printf("Case #%d: OK\n", tc);
		else printf("Case #%d: %d\n", tc, check);
	}

	return 0;
}

void Sort()
{
	int i, j, temp;

	for (i = 0; i < su - 1; i++) {
		for (j = i + 1; j < su; j++) {
			if (list_c[i] > list_c[j]) {
				temp = list_c[i];
				list_c[i] = list_c[j];
				list_c[j] = temp;
			}
		}
	}

}

void TroubleSort()
{
	int i, temp;
	int done = 0;
	
	while (done == 0)
	{
		done = 1;
		for (i = 0; i < su - 2; i++) {
			if (list[i] > list[i + 2]) {
				done = 0;
				
				temp = list[i];
				list[i] = list[i + 2];
				list[i + 2] = temp;

			}
		}
	}
}

int Compare()
{
	int i;
	for (i = 0; i < su; i++)
		if (list[i] != list_c[i])
			return i;

	return -1;
}