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

int N, M, ans;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};
int score[501][501];
int visit[501][501];

bool chk_range(int x, int y) {
    if (x>=1 && y>=1 && x<=N && y<=M) return true;
    return false;
}
void dfs(int sc, int cnt, int x, int y) {
    if (cnt == 4) {
        ans = max(ans, sc);
        return;
    }
    for (int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (chk_range(nx, ny) && visit[nx][ny] == 0) {
            visit[nx][ny] = 1;
            dfs(sc+score[nx][ny], cnt+1, nx, ny);
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
            cin >> score[i][j];
        }
    }
    // 1. 나머지 4개 도형
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            visit[i][j] = 1;
            dfs(score[i][j], 1, i, j);
            visit[i][j] = 0;
        }
    }
    // 2. 성 모양
    for (int i=2; i+1<=N; i++) {
        for(int j=1; j<=M; j++) {
            int sero_hab = score[i][j] + score[i-1][j] + score[i+1][j];
            if (chk_range(i, j-1)) { // left
                ans = max(ans, sero_hab + score[i][j-1]);    
            }
            if (chk_range(i, j+1)) { // right
                ans = max(ans, sero_hab + score[i][j+1]);
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 2; j + 1 <= M; j++) {
            int garo_hab = score[i][j] + score[i][j-1] + score[i][j+1];
            if (chk_range(i-1, j)) { // upper
                ans = max(ans, garo_hab + score[i-1][j]);
            }
            if (chk_range(i+1, j)) { // lower
                ans = max(ans, garo_hab + score[i+1][j]);
            }
        }
    }
    cout << ans;
}
