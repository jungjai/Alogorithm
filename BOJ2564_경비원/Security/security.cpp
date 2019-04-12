#include<stdio.h>
#include<math.h>

#pragma warning (disable : 4996)

int min(int p, int q);

int main()
{
	freopen("input.txt", "r", stdin);

	int hori = 0, ver = 0, su;
	int dir[100], dis[100];
	int dondir, dondis;

	int i, check = 0, dirmul = 0;

	int shortsum = 0;

	scanf("%d %d", &hori, &ver);
	scanf("%d", &su);
	for (i = 0; i < su; i++)
		scanf("%d %d", &dir[i], &dis[i]);

	scanf("%d %d", &dondir, &dondis);

	for (i = 0; i < su; i++) {		
		dirmul = dir[i] * dondir;
		if (dir[i] == dondir) {
			shortsum += abs(dis[i] - dondis);
		}
		else if (dirmul == 2) {
			check = dis[i] + dondis;
			shortsum = shortsum + (min(check, (hori * 2 - check)) + ver);
		}
		else if (dirmul == 12) {
			check = dis[i] + dondis;
			shortsum = shortsum + (min(check, (ver * 2 - check)) + hori);
		}
		else if (dirmul == 3) {
			shortsum += dis[i] + dondis;
		}
		else if (dirmul == 4) {
			if (dondir < dir[i])
				shortsum += dis[i] + (hori - dondis);
			else
				shortsum += dondis + (hori - dis[i]);
		}
		else if (dirmul == 6) {
			if (dondir < dir[i])		
				shortsum += (dondis + (ver - dis[i]));
			else
				shortsum += (dis[i] + (ver - dondis));
		}
		else if (dirmul == 8) {
			shortsum += ((ver + hori) - (dis[i] + dondis));
		}
	}

	printf("%d\n", shortsum);
}

int min(int p, int q)
{
	if (p <= q) return p;
	else return q;
}