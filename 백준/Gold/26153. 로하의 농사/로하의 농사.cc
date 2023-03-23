#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <stdlib.h>
#include <map>

using namespace std;

int N, M, sx, sy, p, ans;
int arr[55][55];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int visit[55][55];

bool range_chk(int x, int y) {
    if (x>=0 && y>=0 && x<=N+1 && y<=M+1) return true;
    return false;
}
void dfs(int x, int y, int dir, int cost, int water) {
    ans = max(ans, water);
    if (x == 0 || y == 0 || x == N + 1 || y == M + 1) return;

    for (int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (visit[nx][ny] == 0 && range_chk(nx,ny)) {
            visit[nx][ny] = 1;
            if (dir == i) {
                if (cost + 1 <= p) {
                    dfs(nx, ny, i, cost + 1, water + arr[x][y]);
                }
            }
            else {
                if (cost + 2 <= p) {
                    dfs(nx, ny, i, cost + 2, water + arr[x][y]);
                }
            }
            visit[nx][ny] = 0;
        }
    }
    return;
}
int main()
{
    cin >> N >> M;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            cin >> arr[i][j];
        }
    }
    cin >> sx >> sy >> p;
    visit[sx+1][sy+1] = 1;
    for (int i=0; i<4; i++) {
        int nx = sx + 1 + dx[i];
        int ny = sy + 1 + dy[i];
        if (range_chk(nx, ny)) {
            visit[nx][ny] = 1;
            dfs(nx, ny, i, 0, 0);
            visit[nx][ny] = 0;
        }
    }
    cout << ans + arr[sx+1][sy+1];
}
