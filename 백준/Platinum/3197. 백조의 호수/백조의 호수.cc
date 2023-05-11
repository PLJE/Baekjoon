#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int R, C;
int sx, sy, ex, ey;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
char arr[1600][1600];
vector <vector<pair<int,int>>> parent;
queue <pair<int, int>> waters;

bool range(int x, int y) {
    if (x>=0 && y>=0 && x<R && y<C) return true;
    return false;
}
pair<int,int> find_parent(int x, int y) {
    if (parent[x][y].first == x && parent[x][y].second == y) {
        return parent[x][y];
    }
    return parent[x][y] = find_parent(parent[x][y].first, parent[x][y].second);
}
void get_input() {
    cin >> R >> C;

    int cnt = 0;
    string s;

    for (int i=0; i<R; i++) {
        cin >> s;
        
        vector <pair<int,int>> tmp;
       
        for (int j=0; j<C; j++) {
            arr[i][j] = s[j];
            
            tmp.push_back({i, j});
            
            if (s[j] == 'L') {
                if (cnt == 0) {
                    sx = i; sy = j;
                    cnt++;
                } else {
                    ex = i; ey = j;
                }
            }

            if (s[j] == '.' || s[j] == 'L') {
                waters.push({i, j});
            }
        }
        parent.push_back(tmp);
    }
}
void print_parent() {
    cout <<" ===========\n";
    for (int i=0;i<R;i++) {
        for (int j=0;j <C;j++) {
            pair<int,int> p = find_parent(i, j);
            cout << p.first << p.second << " ";
        }
        cout << "\n";

    }
    cout <<" =====\n";
    for (int i=0;i<R;i++) {
        for (int j=0;j <C;j++)cout << arr[i][j];
        cout << "\n";

    }
    cout <<" ===========\n";
}
bool swan_parent_same() {
    pair<int,int> p1 = find_parent(sx, sy);
    pair<int,int> p2 = find_parent(ex, ey);
    if (p1.first == p2.first && p1.second == p2.second) return true;
    return false;
}
bool is_water(int x, int y) {
    if (arr[x][y] == '.' || arr[x][y] =='L') return true;
    return false;
}
int melt() {
    int wsize = waters.size();
    int next_wsize = 0;
    int days = 0;

    while (!waters.empty()) {
        int x = waters.front().first;
        int y = waters.front().second;
        pair<int,int> p1 = find_parent(x, y);
        waters.pop();
        wsize--;

        if (swan_parent_same()){
            if (next_wsize)
                days++;
            return days;
        }

        for (int d=0; d<4; d++) {
            int nx = x+ dx[d];
            int ny = y+ dy[d];

            if (range(nx, ny)) {

                if (is_water(nx, ny)) {
                    pair<int,int> p2 = find_parent(nx, ny);
                    if (p1 != p2) {
                        parent[p2.first][p2.second].first = p1.first;
                        parent[p2.first][p2.second].second = p1.second;
                    }
                }

                if (arr[nx][ny] == 'X') {
                    parent[nx][ny].first = p1.first;
                    parent[nx][ny].second = p1.second;
                    arr[nx][ny] = '.';
                    waters.push({nx,ny});
                    next_wsize++;
                    for (int k=0; k<4; k++) {
                        int kx = nx + dx[k];
                        int ky = ny + dy[k];
                        if (range(kx, ky) && is_water(kx, ky)) {
                            pair <int,int> pk = find_parent(kx, ky);
                            parent[pk.first][pk.second].first = p1.first;
                            parent[pk.first][pk.second].second = p1.second;
                        }
                    }
                }
            }
        }

        if (wsize == 0) {
            wsize = next_wsize;
            next_wsize = 0;
            days++;
        }
    }
    return -1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    get_input();

    cout << melt() << "\n";
    return 0;
}
