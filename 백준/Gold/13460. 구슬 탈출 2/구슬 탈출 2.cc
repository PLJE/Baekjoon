#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
int hx, hy;
char board[11][11];
int dx[4] = {-1,0,1,0}; 
int dy[4] = {0,1,0,-1};
int visit [11][11][11][11];
struct cur {
    int rx;
    int ry;
    int bx;
    int by;
    int cnt;
};

pair<int, bool> move(int x, int y, int dir) {
    bool reach_hole = false;
    int distance = 0;
    while (true) {
        if (x == hx && y == hy) {
            reach_hole = true;
            break;
        }
        x += dx[dir];
        y += dy[dir];
        if (board[x][y] == '#') break;
        distance++;
    }
    return {distance, reach_hole};
}
int main()
{
    cin >> n >> m;
    string s;
    cur icur;
    for (int i=1; i<=n; i++) {
        cin >> s;
        for (int j=1; j<=m; j++) {
            board[i][j] = s[j-1];
            if (s[j-1] == 'R') {
                icur.rx = i; icur.ry = j;
                board[i][j] = '.';
            }
            if (s[j-1] == 'B') {
                icur.bx = i; icur.by = j;
                board[i][j] = '.';
            }
            if (s[j-1] == 'O') {
                hx = i;
                hy = j;
            }
        }
    }
    icur.cnt = 0;
    visit[icur.rx][icur.ry][icur.bx][icur.by] = 1;
    queue <cur> q;
    q.push(icur);
    while (!q.empty()) {
        cur now = q.front();
        q.pop();
        if (now.cnt >= 10) continue;
        for (int i=0; i<4; i++) {
            pair <int, bool> red = move(now.rx, now.ry, i);
            pair <int, bool> blue = move(now.bx, now.by, i);
            if (red.first == 0 && blue.first == 0) continue;
            if (blue.second) continue;
            if (red.second) {
                cout << now.cnt + 1; 
                return 0;
            }
            int next_rx = now.rx + (dx[i] * red.first);
            int next_ry = now.ry + (dy[i] * red.first);
            int next_bx = now.bx + (dx[i] * blue.first);
            int next_by = now.by + (dy[i] * blue.first);
            if (next_rx == next_bx && next_ry == next_by) {
                if (i == 0) {
                    if (red.first > blue.first) {
                        next_rx++;    
                    } else {
                        next_bx++;
                    }
                } else if (i == 1) {
                    if (red.first > blue.first) {
                        next_ry--;
                    }
                    else {
                        next_by--;
                    }
                } else if (i == 2) {
                    if (red.first > blue.first) {
                        next_rx--;
                    }
                    else {
                        next_bx--;
                    }
                } else {
                    if (red.first > blue.first) {
                        next_ry++;
                    }
                    else {
                        next_by++;
                    }
                }
            }
            if (visit[next_rx][next_ry][next_bx][next_by] == 0) {
                cur next;
                next.rx = next_rx;
                next.ry = next_ry;
                next.bx = next_bx;
                next.by = next_by;
                next.cnt = now.cnt + 1;
                q.push(next);
                visit[next_rx][next_ry][next_bx][next_by] = 1;
            }
        }
    }
    cout << -1;
}
