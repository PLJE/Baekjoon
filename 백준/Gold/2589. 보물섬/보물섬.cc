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

int N,M,ans;
char board[51][51];
int visit[51][51];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

bool range(int x, int y) {
    if (x>=1 && y>=1 && x<=N && y<=M && !visit[x][y] 
    && board[x][y]=='L') return true;
    return false;
}
int min_dist(pair<int,int> a) {
    queue <vector<int>> q;
    q.push({a.first,a.second,0});
    visit[a.first][a.second] = 1;
    vector <pair<int,int>> pr;
    
    int ret = 0;
    while(!q.empty()) {
        int x = q.front()[0];
        int y = q.front()[1];
        int c = q.front()[2];
        ret = max(ret, c);
        q.pop();
        
        for (int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (range(nx, ny)) {
                q.push({nx, ny, c+1});
                pr.push_back({nx, ny});
                visit[nx][ny] = 1;
            }
        }
    }

    visit[a.first][a.second] = 0;
    for (auto p : pr) {
        visit[p.first][p.second] = 0;
    }
    return ret;
}
int main() {
    cin >> N >> M;
    vector <pair<int,int>> land;
    for (int i=1; i<=N; i++) {
        string s;
        cin >> s;
        for (int j=1;j<=M;j++) {
            board[i][j] = s[j-1];
            if (s[j-1] == 'L') land.push_back({i, j});
        }
    }
    int len = land.size();
    for (int i=0; i<len; i++) {
        int mdist = min_dist(land[i]);
        ans = max(ans, mdist);
    }
    cout << ans;
}