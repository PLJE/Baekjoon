#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
int ix, iy, idir;
int arr[51][51];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int cleaned;

int get_opposite_dir (int dir) {
    if (dir == 0) return 2;
    if (dir == 1) return 3;
    if (dir == 2) return 0;
    if (dir == 3) return 1;
}
int rotate(int dir) {
    if (dir == 0) return 3;
    if (dir == 1) return 0;
    if (dir == 2) return 1;
    if (dir == 3) return 2;
}
bool is_in(int x, int y) {
    if (x>=0 && y>=0 && x<n && y<m) return true;
    return false;
}
bool dirty_exist(int x, int y) {
    for (int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (is_in(nx, ny) && arr[nx][ny] == 0) 
            return true;
    }
    return false;
}
bool move_back_possible(int x, int y, int dir) {
    int opposite_dir = get_opposite_dir(dir);
    int back_x = x + dx[opposite_dir];
    int back_y = y + dy[opposite_dir];
    if (is_in(back_x, back_y) && arr[back_x][back_y] != 1) return true;
    return false;
}

int main()
{
    cin >> n >> m;
    cin >> ix >> iy >> idir;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> arr[i][j];
        }
    }
    while (true) {
        if (arr[ix][iy] == 0) {
            arr[ix][iy] = 2;
            cleaned++;
        }
        if (!dirty_exist(ix, iy)) {
            if (!move_back_possible(ix,iy,idir)) {
                break;
            } else {
                int opposite_dir = get_opposite_dir(idir);
                ix += dx[opposite_dir];
                iy += dy[opposite_dir];
                continue;
            }
        } else {
            idir = rotate(idir);
            int front_x = ix + dx[idir];
            int front_y = iy + dy[idir];
            if (is_in(front_x, front_y) && arr[front_x][front_y] == 0) {
                ix = front_x;
                iy = front_y;
            }
        }
    }
    cout << cleaned;
}
