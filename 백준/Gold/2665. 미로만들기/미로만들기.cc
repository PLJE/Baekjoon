#include <iostream>
#include <algorithm>
#include <string>
#include <climits>
#include <vector>
#include <queue>

using namespace std;

int N;
char room[51][51];
int visit[51][51][4];
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

bool range(int x, int y, int d) {
    if (x>=0 && y>=0 && x<N && y<N && visit[x][y][d] == 0) return true;
    return false;
}
int main() {
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    string s;
    for (int i=0; i<N; i++) {
        cin >> s;
        for (int j=0; j<N; j++) {
            room[i][j] = s[j];
        }
    }
    priority_queue <pair<int,pair<int,int>>> pq;
    pq.push({0,{0,0}});
    for (int i=0; i<4; i++) {
        visit[0][0][i] = 1;
    }
    while (!pq.empty()) {
        int now_x = pq.top().second.first;
        int now_y = pq.top().second.second;
        int now_block = -pq.top().first;
        pq.pop();

        if (now_x == N-1 && now_y == N-1) {
            cout << now_block;
            break;
        }
        
        for (int d=0; d<4; d++) {
            int nx = now_x + dx[d];
            int ny = now_y + dy[d];
            if (!range(nx, ny, d)) continue;
            visit[nx][ny][d] = 1;
            if (room[nx][ny] == '0') pq.push({-(now_block+1),{nx, ny}});
            else pq.push({-now_block,{nx, ny}});
        }
    }
    return 0;
}