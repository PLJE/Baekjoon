#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <string>
#include <string.h>
#include <iostream>
#include <map>

using namespace std;

int N, M;
int arr[300][300];
int zero[300][300];
int visit[300][300];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

int getcount(int x, int y) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (arr[nx][ny] == 0) cnt++;
	}
	return cnt;
}
int range(int x, int y) {
	if (x >= 0 && y >= 0 && x < N && y < M && !visit[x][y])
		return 1;
	return 0;
}
void dfs(int x, int y) {
	visit[x][y] = 1;
	//cout << x << " " << y << "\n";
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if ( range(nx, ny) && arr[nx][ny] > 0) {
			dfs(nx, ny);
		}
	}
	return;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	int first = 0;
	for (int i = 1; i <= N - 2; i++) {
		for (int j = 1; j <= M - 2; j++) {
			if (arr[i][j] != 0 && visit[i][j] == 0) {
				dfs(i, j);
				first++;
			}
		}
	}
	if (first >= 2) {
		cout << 0;
		return 0;
	}

	int years = 0;
	while (true) {
		memset(visit, 0, sizeof(visit));
		memset(zero, 0, sizeof(visit));
		for (int i = 1; i <= N-2; i++) {
			for (int j = 1; j <= M-2; j++) {
				if (arr[i][j] != 0) {
					zero[i][j] = getcount(i, j);
				}
			}
		}

		for (int i = 1; i <= N-2; i++) {
			for (int j = 1; j <= M-2; j++) {
				arr[i][j] -= zero[i][j];
				if (arr[i][j] < 0) arr[i][j] = 0;
				//cout << arr[i][j] << " ";
			}
			//cout << "\n";
		}
		int numzero = 0;
		for (int i = 1; i <= N - 2; i++) {
			for (int j = 1; j <= M - 2; j++) {
				if (arr[i][j] != 0) numzero++;
			}
		}

		int island = 0;
		for (int i = 1; i <= N-2; i++) {
			for (int j = 1; j <= M-2; j++) {
				if (arr[i][j] != 0 && visit[i][j] == 0) {
					dfs(i, j);
					island++;
				}
			}
		}
		years++;
		if (island >= 2) break;
		if (island < 2 && numzero == 0) {
			cout << 0;
			return 0;
		}
	}
	cout << years;
} 