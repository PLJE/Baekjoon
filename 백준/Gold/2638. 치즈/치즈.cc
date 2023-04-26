#include <iostream>
#include <deque>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>

using namespace std;

int N, M, cheese;
int arr[101][101];
int visit[101][101];
int air[101][101];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int range(int x, int y) {
    if (x>=0 && y>=0 && x<N && y<M) return 1;
    return 0;
}
bool is_edge(int x, int y) {
    if (x>=1 && y>=1 && x<N-1 && y<M-1) return 0;
    return 1;
}
void outer_air() {
    // outer air : air[x][y] = 2
    memset(visit, 0, sizeof(visit));
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (is_edge(i, j) && arr[i][j] == 0 && !visit[i][j]) {
                visit[i][j] = 1;
                air[i][j] = 2;

                queue <pair<int,int>> q;
                q.push({i, j});
                while(!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    air[x][y] = 2;

                    for (int d=0; d<4; d++) {
                        int nx = x + dx[d];
                        int ny = y + dy[d];
                        if (range(nx,ny) && !visit[nx][ny] && arr[nx][ny] == 0) {
                            visit[nx][ny] = 1;
                            q.push({nx, ny});
                        }
                    }
                }
            }
        }
    }
}
void print_air() {
    for (int i=0; i<N; i++) {
        for (int j=0; j<M;j ++) {
            cout << air[i][j] << " ";
        }
        cout << "\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M;j ++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) cheese++;
        }
    }
    int hour = 0;
    while (cheese > 0) {
        outer_air(); // make element 2 of air[][]

        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                if (arr[i][j] == 0) continue;
                int outer_air_cnt = 0;
                for (int d=0; d<4; d++) {
                    int ni = i + dx[d];
                    int nj = j + dy[d];
                    if (range(ni, nj) && air[ni][nj] == 2) outer_air_cnt++;
                }
                if (outer_air_cnt >= 2) {
                    arr[i][j] = 0;
                    cheese--;
                }
            }
        }
        hour++;
    }
    cout << hour;
} 