#include <iostream>
#include <map>
#include <sstream>
#include <cstring>
#include <string>
#include <climits>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M, cnt;
vector <vector<int>> cctv;
int arr[9][9];
int tmp[9][9];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

void copy() {
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            tmp[i][j] = arr[i][j];
        }
    }
}
vector<int> get_dirs(int ctype, int num) {
    vector <int> tmp;
    if (ctype == 1) {
        tmp.push_back(num);
    } else if (ctype == 2) {
        if (num == 1) tmp = {1,3};
        else tmp = {0,2};
    } else if (ctype == 3) {
        tmp = {num, (num + 1) % 4};
    } else if (ctype == 4) {
        tmp = {num, (num+1) % 4, (num+2) % 4};
    } else if (ctype == 5) {
        tmp = {0,1,2,3};
    }
    return tmp;
}
bool range(int x, int y) {
    if (x>=1 && x<=N && y>=1 && y<=M) return true;
    return false;
}
void color(int x, int y, int c, int d) {
    vector<int> dirs = get_dirs(c, d);
    int dlen = dirs.size();
    for (int i=0; i<dlen; i++) {
        int d = dirs[i];
        int nx = x + dx[d];
        int ny = y + dy[d];
        while (range(nx, ny)) {
            if (tmp[nx][ny] == 6) break;
            if (tmp[nx][ny] == -1 || tmp[nx][ny] == 0) tmp[nx][ny] = -1;
            nx += dx[d];
            ny += dy[d];
        }
    }
} 
int count() {
    int t = 0;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            if (tmp[i][j] == 0) t++;
        }
    }
    return t;
}
void cal(vector <int> dir) {
    int clen = cctv.size();
    copy();
    for (int i=0; i<clen; i++) {
        int d = dir[i];
        int c = cctv[i][2];
        int x = cctv[i][0];
        int y = cctv[i][1];
        color(x,y,c,d);
    }
}
void dfs(int idx, vector <int> dir) {
    if (idx == cctv.size()) {
        cal(dir);
        cnt = min(cnt, count());
        return;
    }
    if (cctv[idx][2] == 2) {
        for (int i=1; i<=2; i++) {
            dir.push_back(i);
            dfs(idx+1, dir);
            dir.pop_back();
        }
    } else if (cctv[idx][2] == 5) {
        dir.push_back(-1);
        dfs(idx+1, dir);
        dir.pop_back();
    } else {
        for (int i=0; i<=3; i++) {
            dir.push_back(i);
            dfs(idx+1, dir);
            dir.pop_back();
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 0) cnt++;
            if (arr[i][j] >=1 && arr[i][j] <= 5) cctv.push_back({i,j,arr[i][j]});
        }
    }
    vector <int> dir;
    dfs(0, dir);
    cout << cnt;
}