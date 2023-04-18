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
int main() {
    cin >> M >> N;
    cin >> k;
    int dir, dist;
    for (int i=0; i<k; i++) {
        cin >> dir >> dist;
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
        store.push_back({dir, dist});
    }

    int sdir, sdist;
    cin >> sdir >> sdist;
    if (sdir == 1) sdir = 0;
    else if (sdir == 2) sdir = N;
    else if (sdir == 3) {
        sdir = sdist;
        sdist = 0;
    }
    else if (sdir == 4) {
        sdir = sdist;
        sdist = M;
    }

    int ans = 0;
    for (int i=0; i<k; i++) {
        memset(visit,0,sizeof(visit));
        dir = store[i].first;
        dist = store[i].second;
        queue <vector<int>> q;
        q.push({sdir,sdist,0});

        while (!q.empty()) {
            int cx = q.front()[0];
            int cy = q.front()[1];
            int cd = q.front()[2];
            q.pop();
            visit[cx][cy] = 1;
            if (cx == dir && cy == dist) {
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
