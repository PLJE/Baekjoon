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

int N, K, L, ans;
int board[101][101];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
map <int, char> change;

bool chk_range(int x, int y) {
    if (x>=1 && y>=1 && x<=N && y<=N && board[x][y] != 2) return true;
    return false;
}
bool is_apple(int x, int y) {
    if (board[x][y] == 1) return true;
    return false;
}
int get_dir(int dir, char c) {
    if (dir == 0) {
        if (c == 'L') return 3;
        return 1;
    } else if (dir == 1) {
        if (c == 'L') return 0;
        return 2;
    } else if (dir == 2) {
        if (c == 'L') return 1;
        return 3;
    } else {
        if (c == 'L') return 2;
        return 0;
    }
}
int main()
{
    cin >> N >> K;
    int x, y;
    for (int i=1; i<=K; i++) {
        cin >> x >> y;
        board[x][y] = 1; // apple location
    }
    cin >> L;
    int sec; char dir;
    for (int i=1; i<=L; i++) {
        cin >> sec >> dir;
        change[sec] = dir;
    }
    board[1][1] = 2; // snake
    int cur_direction = 1; // toward east
    deque <pair<int,int>> dq;
    dq.push_front({1,1});
    while (true) {
        int head_x = dq.front().first;
        int head_y = dq.front().second;
        int nx = head_x + dx[cur_direction];
        int ny = head_y + dy[cur_direction];

        if (!chk_range(nx, ny)) break;
        if (is_apple(nx, ny)) {
            board[nx][ny] = 2; 
            dq.push_front({nx,ny});
        } else {
            board[nx][ny] = 2; 
            dq.push_front({nx,ny});
            int tail_x = dq.back().first;
            int tail_y = dq.back().second;
            board[tail_x][tail_y] = 0;
            dq.pop_back();
        }
        ans++;
        if (change.find(ans) != change.end()) { // change direction
            cur_direction = get_dir(cur_direction, change[ans]);
        }
    }
    cout << ans + 1;
}
