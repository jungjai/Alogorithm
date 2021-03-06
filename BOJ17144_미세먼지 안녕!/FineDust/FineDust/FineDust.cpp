#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstring>
#include <queue>
using namespace std;
int arr[50][50];
vector<pair<int, int>> aircon;
const int dx[] = { 0,1,0,-1 };
const int dy[] = { -1,0,1,0 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//미세먼지 안녕
	int r, c, t;
	cin >> r >> c >> t;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == -1) {
				aircon.push_back({ i,j });
			}
		}
	}
	while (t--) {
		//미세먼지 확산
		//(x,y),value
		queue<pair<pair<int, int>, int>> q;
		//큐에 먼지를 넣는다.
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (arr[i][j]>0) {
					q.push({ { i,j },arr[i][j] });
				}
			}
		}
		//먼지확산
		while (!q.empty()) {
			int x = q.front().first.first;
			int y = q.front().first.second;
			int num = q.front().second;
			q.pop();
			int cnt = 0;
			for (int dir = 0; dir < 4; dir++) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (nx >= 0 && nx < r&&ny >= 0 && ny < c && arr[nx][ny] != -1) {
					arr[nx][ny] += num / 5;
					cnt++;
				}
			}
			arr[x][y] -= num / 5 * cnt;
		}

		// 위로 청정기 가동
		int x = aircon[0].first;
		int y = aircon[0].second;
		x--;
		while (x > 0) {
			arr[x][y] = arr[x - 1][y];
			x--;
		}
		while (y < c - 1) {
			arr[x][y] = arr[x][y + 1];
			y++;
		}
		while (x<aircon[0].first) {
			arr[x][y] = arr[x + 1][y];
			x++;
		}
		while (y > 1) {
			arr[x][y] = arr[x][y - 1];
			y--;
		}
		arr[x][y] = 0;

		//아래로 청정기 가동
		x = aircon[1].first;
		y = aircon[1].second;
		x++;
		while (x < r - 1) {
			arr[x][y] = arr[x + 1][y];
			x++;
		}
		while (y < c - 1) {
			arr[x][y] = arr[x][y + 1];
			y++;
		}
		while (x>aircon[1].first) {
			arr[x][y] = arr[x - 1][y];
			x--;
		}
		while (y > 1) {
			arr[x][y] = arr[x][y - 1];
			y--;
		}
		arr[x][y] = 0;
	}
	//남은 미세먼지 계산
	int sum = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j]>0) {
				sum += arr[i][j];
			}
		}
	}
	cout << sum;
	return 0;
}