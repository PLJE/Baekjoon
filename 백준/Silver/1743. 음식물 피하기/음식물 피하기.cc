#include <iostream>
#include <deque>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>

using namespace std;

int N, M, K;
int arr[101][101];
int visit[101][101];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int range(int x, int y) {
    if (x>=0 && y>=0 && x<N && y<M) return 1;
    return 0;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;
    int x, y;
    for (int k=0; k<K; k++) {
        cin >> x >> y;
        arr[x-1][y-1] = 1;
    }
    int trash = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (visit[i][j] == 0 && arr[i][j] == 1) {
                visit[i][j] = 1;
                int cnt = 0;
                queue <pair<int, int>> q;
                q.push({i, j});

                while (!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    cnt++;

                    for (int d=0; d<4; d++) {
                        int nx = x + dx[d];
                        int ny = y + dy[d];
                        if (visit[nx][ny] == 0 && arr[nx][ny] == 1 && range(nx, ny)) {
                            q.push({nx, ny});
                            visit[nx][ny] = 1;
                        }
                    }
                }
                trash = max(trash, cnt);
            }
        }
    }
    cout << trash;
} 