#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int k,N,M;
vector <pair<int,int>> store;
int visit[105][105];
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};

bool is_edge(int x, int y) {
    if (x<0 || y<0 || x>N || y>M) return false; // out of range
    if (x>=1 && x<=N-1 && y>=1 && y<=M-1) return false; // inner
    return true; 
}
pair<int,int> to_xy(int dir, int dist) {
    if (dir == 1) dir = 0;
    else if (dir == 2) dir = N;
    else if (dir == 3) {
        dir = dist;
        dist = 0;
    }
    else if (dir == 4) {
        dir = dist;
        dist = M;
    }
    return {dir, dist};
}
int main() {
    cin >> M >> N;
    cin >> k;
    int dir, dist;
    for (int i=0; i<k; i++) {
        cin >> dir >> dist;
        store.push_back(to_xy(dir, dist));
    }

    int sx, sy;
    cin >> sx >> sy;
    pair<int,int> xy = to_xy(sx, sy);
    sx = xy.first;
    sy = xy.second;

    int ans = 0;
    for (int i=0; i<k; i++) {
        memset(visit,0,sizeof(visit));
        int x = store[i].first;
        int y = store[i].second;
        queue <vector<int>> q;
        q.push({sx,sy,0});

        while (!q.empty()) {
            int cx = q.front()[0];
            int cy = q.front()[1];
            int cd = q.front()[2];
            q.pop();
            visit[cx][cy] = 1;
            if (cx == x && cy == y) {
                ans += cd;
                break;
            }

            for (int d=0;d<4;d++) {
                int nx = cx +dx[d];
                int ny = cy +dy[d];
                if (is_edge(nx,ny) && visit[nx][ny]==0) {
                    q.push({nx,ny,cd+1});
                }
            }
        }
    }
    cout<<ans;
}
