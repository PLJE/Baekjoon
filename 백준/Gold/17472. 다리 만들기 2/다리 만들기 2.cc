#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
int arr[11][11];
int visit[11][11];
int parent[7];
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
priority_queue <pair<int,pair<int,int>>> pq;

bool range(int x, int y) {
    if(x>=0 && y>=0 && x<N && y<M && visit[x][y] ==0) return true;
    return false;
}
int bfs() {
    int cnt = 1;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (visit[i][j] == 0 && arr[i][j] == 1) {
                visit[i][j] = 1;
                queue <pair<int,int>> q;
                q.push({i, j});

                while (!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    arr[x][y] = cnt;

                    for (int d=0; d<4; d++) {
                        int nx = x + dx[d];
                        int ny = y + dy[d];
                        if (range(nx, ny) && arr[nx][ny] == 1) {
                            visit[nx][ny] = 1;
                            q.push({nx, ny});
                        }
                    }
                }
                cnt++;
            }
        }
    }
    return cnt;
}
int find_parent(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find_parent(parent[x]);
}
void get_bridge() {
    for (int i=0; i<N; i++) {
        int pre = -1;
        int bridge = 0;
        for (int j=0; j<M; j++) {
            if (arr[i][j] == 0) {
                bridge++;
            } else {
                if (pre == -1 || bridge < 2 || pre == arr[i][j]) {
                    bridge = 0;
                    pre = arr[i][j];
                    continue;
                }
                pq.push({-bridge, {pre, arr[i][j]}});
                pre = arr[i][j];
                bridge = 0;
            }
        }
    }
    for (int i=0; i<M; i++) {
        int pre = -1;
        int bridge = 0;
        for (int j=0; j<N; j++) {
            if (arr[j][i] == 0) {
                bridge++;
            } else {
                if (pre == -1 || bridge <2 || pre == arr[j][i]) {
                    bridge = 0;
                    pre = arr[j][i];
                    continue;
                }
                pq.push({-bridge, {pre, arr[j][i]}});
                pre = arr[j][i];
                bridge = 0;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) cin >> arr[i][j];
    }
    for(int i=0; i<=6; i++) parent[i] = i;
    int cnt = bfs() - 1;
    get_bridge();
    int combine = 0;
    int ans = 0;
    while(!pq.empty()) {
        int cost = -pq.top().first;
        int a = pq.top().second.first;
        int b = pq.top().second.second;
        pq.pop();

        int pa = find_parent(a);
        int pb = find_parent(b);
        if (pa == pb) continue;
        parent[pa] = pb;
        ans += cost;
        combine++;
    }
    if (combine == cnt - 1) {
        cout << ans;
    } else {
        cout << -1;
    }
}