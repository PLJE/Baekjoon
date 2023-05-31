#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <algorithm>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

int N, K, R;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
bool visited[101][101];

vector <pair<int,int>> cows;
unordered_map <string, int> load_chk;
vector <pair<int,int>> for_memset;

bool range(int x, int y) {
    if (x >= 1 && y >= 1 && x <= N && y <= N && !visited[x][y]) {
        return true;
    } else {
        return false;
    }
}
void init_visited() {
    for (auto a : for_memset) {
        visited[a.first][a.second] = false;
    }
    for_memset.clear();
}
string get_key(int a, int b, int c, int d) {
    string res = "";
    res.push_back(a+'0');
    res.push_back(b+'0');
    res.push_back(c+'0');
    res.push_back(d+'0');
    return res;
}
int main() {
    int a, b, c, d;
    cin >> N >> K >> R;

    for (int i = 0; i < R; i++) {
        cin >> a >> b >> c >> d;
        load_chk[get_key(a,b,c,d)] = 1;
        load_chk[get_key(c,d,a,b)] = 1;
    }
    for (int i = 0; i < K; i++) {
        cin >> a >> b;
        cows.push_back({a, b});
    }

    int ans = 0;

    for (int c1 = 0; c1 < K; c1++) {
        for (int c2 = c1 + 1; c2 < K; c2++) {

            queue <pair<int,int>> q;

            int sx = cows[c1].first;
            int sy = cows[c1].second;
            q.push({sx, sy});

            visited[sx][sy] = true;
            for_memset.push_back({sx, sy});

            while (!q.empty()) {

                int cx = q.front().first;
                int cy = q.front().second;

                q.pop();
                
                if (cx == cows[c2].first && cy == cows[c2].second) {
                    ans++;
                    break;
                }

                for (int d = 0; d < 4; d++) {
                    int nx = cx + dx[d];
                    int ny = cy + dy[d];
                    if (range(nx, ny)) {
                        if (load_chk.find(get_key(cx, cy, nx, ny)) == load_chk.end()) {
                            visited[nx][ny] = true;
                            for_memset.push_back({nx, ny});
                            q.push({nx, ny});
                        }
                    }
                }
            }

            init_visited();
        }
    }

    cout << ((K*(K-1)) / 2) - ans;
}
