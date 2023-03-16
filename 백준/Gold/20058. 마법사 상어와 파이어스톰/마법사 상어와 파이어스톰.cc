#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

int n, q, cnt; 
int arr[65][65];
int tmp[65][65];
int for_melt[65][65];
int visit[65][65];
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0}; 
int get_len[7] = {1, 2, 4, 8, 16, 32, 64};
vector <int> level;

bool no_ice(int x, int y, int len) {
    if (x<1 || y<1 || x>len || y>len) return true;
    if (arr[x][y] <= 0) return true;
    return false;
}
void melt(int len) {
    memset(for_melt, 0, sizeof(for_melt));
    for (int i = 1; i <= len; i++) {
        for (int j = 1; j <= len; j++) {
            if (arr[i][j] == 0) continue;
            int cnt = 0;
            for (int k = 0; k < 4; k++) {
                if (no_ice(i + dx[k], j + dy[k], len)) cnt++;
            }
            if (cnt >= 2) {
                for_melt[i][j] = -1;
            }
        }
    }
    for (int i = 1; i <= len; i++) {
        for (int j = 1; j <= len; j++) {
            arr[i][j] += for_melt[i][j];
            if (arr[i][j] <= 0) arr[i][j] = 0;
        }
    }
}
void tmp_to_arr() {
    int len = get_len[n];
    for (int i = 1; i <= len; i++) {
        for (int j = 1; j <= len; j++) {
            arr[i][j] = tmp[i][j];
        }
    }
}
void rotate(int sx, int sy, int ex, int ey) {
    int len = get_len[n];
    for (int i = 1; i <= len; i++) {
        for (int j = 1; j <= len; j++) {
            tmp[i][j] = arr[i][j];
        }
    }
    int col = ey;
    for (int i=sx; i<=ex; i++) {
        int row = sx;
        for (int j=sy; j<=ey; j++) {
            tmp[row++][col] = arr[i][j];
        }
        col--;
    }
}
int ice(int len) {
    int num = 0;
    for (int i = 1; i <= len; i++) {
        for (int j = 1; j <= len; j++) {
            num += arr[i][j];
        }
    }
    return num;
}
bool chk(int x, int y) {
    int len = get_len[n];
    if (x>=1 && y>=1 && x<=len && y<=len) return true;
    return false;
}
void dfs(int x, int y) {
    visit[x][y] = 1;

    for (int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (chk(nx,ny) && arr[nx][ny] > 0 && visit[nx][ny] == 0) {
            visit[nx][ny] = 1;
            cnt++;
            dfs(nx, ny);
        }
    }
}
int get_block(int len) {
    int block = 0;
    for (int i = 1; i <= len; i++) {
        for (int j = 1; j <= len; j++) {
            if (arr[i][j] > 0 && visit[i][j] == 0) {
                cnt = 1;
                dfs(i, j);
                block = max(block, cnt);
            }
        }
    }
    return block;
}
int main()
{
    cin >> n >> q;
    int len = get_len[n];
    for (int i=1; i<=len; i++) {
        for (int j=1; j<=len; j++) {
            cin >> arr[i][j];
        }                                                                                                                                                                                                  
    }
    for (int i=0; i<q; i++) {
        int l;
        cin >> l;
        level.push_back(l);
    }
    for (int i=0; i<q; i++) {
        int divide_len = get_len[level[i]];
        if (level[i] != 0) {
            for (int row = 1; row <= len; row += divide_len) {
                for (int col = 1; col <= len; col += divide_len) {
                    rotate(row, col, row + divide_len - 1, col + divide_len - 1);
                    tmp_to_arr();
                }
            }
        }
        melt(len);
    }
    cout << ice(len) << "\n";
    cout << get_block(len);
}
