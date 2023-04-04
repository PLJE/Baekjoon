#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct fish {
    void init(int ix, int iy, int inum, int idir, bool idied) {
        x = ix;
        y = iy;
        num = inum;
        dir = idir;
        died = idied;
    }
    int x;
    int y;
    int num;
    int dir;
    bool died;
};
int ans;
fish fs[17];
int sea[5][5]; // 물고기 번호(1~16) , 빈칸(0) , 상어(-1)
int dx[9] = { 0,-1,-1,0,1,1,1,0,-1 }; // 1 ~ 8 사용
int dy[9] = { 0,0,-1,-1,-1,0,1,1,1 };

int rotate(int dir) {
    if (dir == 8) return 1;
    else return dir + 1;
}
bool range(int x, int y) {
    if (x >= 1 && y >= 1 && x <= 4 && y <= 4) return true;
    return false;
}
void change_fish(int a, int b) {
    sea[fs[a].x][fs[a].y] = fs[b].num;
    sea[fs[b].x][fs[b].y] = fs[a].num;
    fish tmp;
    tmp.init(fs[a].x, fs[a].y, fs[a].num, fs[a].dir, fs[a].died);
    fs[a].x = fs[b].x;
    fs[a].y = fs[b].y;

    fs[b].x = tmp.x;
    fs[b].y = tmp.y;
}
void move_fish() {
    for (int f = 1; f <= 16; f++) {
        if (fs[f].died) continue;
        int rot = 0;
        while (1) {
            if (rot >= 8) break; // 이동할 곳 X
            int nx = fs[f].x + dx[fs[f].dir];
            int ny = fs[f].y + dy[fs[f].dir];
            if (sea[nx][ny] == -1 || !range(nx, ny)) {
                fs[f].dir = rotate(fs[f].dir);
                rot++;
            }
            else {
                if (sea[nx][ny] == 0) { // 빈곳 
                    sea[fs[f].x][fs[f].y] = 0;
                    sea[nx][ny] = f;
                    fs[f].x = nx;
                    fs[f].y = ny;
                }
                else change_fish(f, sea[nx][ny]);
                break;
            }
        }
    }
}
void save_state(int save_sea[][5], int sea[][5], fish save_fish[], fish fs[]) {
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++)
            save_sea[i][j] = sea[i][j];
    }
    
    for (int i = 1; i <= 16; i++) {
        save_fish[i].x = fs[i].x;
        save_fish[i].y = fs[i].y;
        save_fish[i].num = fs[i].num;
        save_fish[i].dir = fs[i].dir;
        save_fish[i].died = fs[i].died;
    }
}
void dfs(int x, int y, int dir, int eat) {
    ans = max(ans, eat);
    fish save_fish[17];  
    int save_sea[5][5];

    move_fish();
    save_state(save_sea, sea, save_fish, fs);

    vector <pair<int, int>> move; // 상어가 갈 수 있는 칸들
    for (int i = 1; i <= 3; i++) {
        int nx = x + (i * dx[dir]);
        int ny = y + (i * dy[dir]);
        if (range(nx, ny) && sea[nx][ny] >= 1 && sea[nx][ny] <= 16) {
            move.push_back({ nx, ny });
        }
    }
    if (move.size() == 0) return;
    for (int i = 0; i < move.size(); i++) {
        int nx = move[i].first;
        int ny = move[i].second;
        sea[x][y] = 0;
        int fnum = sea[nx][ny];
        fs[fnum].died = true;
        sea[nx][ny] = -1;

        dfs(nx, ny, fs[fnum].dir, eat + fnum);
        save_state(sea, save_sea, fs, save_fish);
    }
}
int main() {
    int x, d;
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            cin >> x >> d;
            fs[x].dir = d; fs[x].x = i; fs[x].y = j; fs[x].num = x; bool died = false;
            sea[i][j] = x;
        }
    }
    fs[sea[1][1]].died = true;
    int shark_dir = fs[sea[1][1]].dir;
    int shark_eat = fs[sea[1][1]].num;
    sea[1][1] = -1;

    dfs(1, 1, shark_dir, shark_eat);

    cout << ans;
}