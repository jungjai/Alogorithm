#include<stdio.h>

int main()
{
	int num, map_1[51], map_2[51];
	int temp, min = 0;

	scanf("%d", &num);
	for (int i = 0; i < num; i++) scanf("%d", &map_1[i]);
	for (int i = 0; i < num; i++) scanf("%d", &map_2[i]);

	for (int i = 0; i < num; i++) {
		for (int j = i + 1; j < num; j++) {
			if (map_1[i] > map_1[j]) {
				temp = map_1[i];
				map_1[i] = map_1[j];
				map_1[j] = temp;
			}
			if (map_2[i] < map_2[j]) {
				temp = map_2[i];
				map_2[i] = map_2[j];
				map_2[j] = temp;
			}
		}
	}

	for (int i = 0; i < num; i++) min += a[i] * map_2[i];
	printf("%d\n", min);
}