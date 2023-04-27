#include <iostream>
#include <deque>
#include <string>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>

using namespace std;

int N, M, total_ice;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int sea[301][301];
int visit[301][301];
vector <pair<int,int>> ice;

bool range(int x, int y) {
    if (x>=0 && y>=0 && x<N && y<M) return true;
    return false;
}
int around_water(int x, int y) {
    int water = 0;
    for (int d=0; d<4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (range(nx, ny) && sea[nx][ny] == 0) water++;
    }
    return water;
}
void reset_visit() {
    int nice = ice.size();
    for (int i=0; i<nice; i++) {
        int x = ice[i].first;
        int y = ice[i].second;
        visit[x][y] = 0;
    }
}
int number_ice() {
    reset_visit();
    int nice = ice.size();
    int partition = 0;

    for (int i=0; i<nice; i++) {
        int x = ice[i].first;
        int y = ice[i].second;
        if (sea[x][y] == 0 || visit[x][y]) continue;
        partition++;
        if (partition >= 2) break;

        visit[x][y] = 1;
        queue <pair<int,int>> q;
        q.push({x,y});
        while(!q.empty()) {
            int cx = q.front().first;
            int cy = q.front().second;
            q.pop();

            for (int d=0; d<4; d++) {
                int nx = cx + dx[d];
                int ny = cy + dy[d];
                if (range(nx, ny)) {
                    if (sea[nx][ny] > 0 && visit[nx][ny]==0) {
                        visit[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
    }
    return partition;
}
void melt() {
    int nice = ice.size();
    vector <vector<int>> melt_ice;
    for (int i=0; i<nice; i++) {
        int x = ice[i].first;
        int y = ice[i].second;
        if (sea[x][y] == 0) continue;
        int water = around_water(x, y);
        if (water > 0) {
            melt_ice.push_back({x, y, water});
        }
    }
    int nmelt = melt_ice.size();
    for (int i=0; i<nmelt; i++) {
        int x = melt_ice[i][0];
        int y = melt_ice[i][1];
        int melt = melt_ice[i][2];
        sea[x][y] -= melt;
        if (sea[x][y] <= 0) {
            sea[x][y] = 0;
            total_ice--;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> sea[i][j];
            if (sea[i][j] > 0) {
                ice.push_back({i, j});
                total_ice++;
            }
        }
    }
    int year = 0;
    while(1) {
        int partition = number_ice();
        if (total_ice == 0) {
            cout << 0;
            return 0;
        }
        if (partition >= 2) {
            cout << year;
            return 0;
        }
        melt();
        year++;
    }
}
