#include <iostream>
#include <deque>
#include <string>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#include <climits>
#include <set>
#include <vector>

using namespace std;

int N, q;
int snail[1002][1002];
int visit[1002][1002];
int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};

int turn_left(int dir) {
    if (dir == 0) return 1;
    if (dir == 1) return 2;
    if (dir == 2) return 3;
    if (dir == 3) return 0;
}
int range(int x, int y) {
    if (x>=1 && y>=1 && x<=N && y<=N && !visit[x][y]) return 1;
    return 0;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int sx, sy;
    cin >> N >> q;
    int dir = 3;
    int total_n = N * N;
    int x = 1;
    int y = 1;
    while (total_n > 0) {
        snail[x][y] = total_n--;
        visit[x][y] = 1;
        if (snail[x][y] == q) {
            sx = x;
            sy = y;
        }
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (!range(nx, ny)) {
            dir = turn_left(dir);
        }
        x = x + dx[dir];
        y = y + dy[dir];
    }
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            cout << snail[i][j] << " ";
        }
        cout << "\n";
    }
    cout << sx << " " << sy;
    return 0;
}
