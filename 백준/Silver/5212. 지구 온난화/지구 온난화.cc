#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
char arr[11][11];
int r, c;
vector <pair<int,int>> ground;

bool range(int x, int y) {
  if (x>=0 && y>=0 && x<r && y<c) return true;
  return false;
}
int around_water(int x, int y) {
  int cnt = 0;
  for (int d=0; d<4; d++) {
    int nx = x + dx[d];
    int ny = y + dy[d];
    if (range(nx, ny) && arr[nx][ny] == 'X') cnt++;
  }
  return 4-cnt;
}
int main() {
  cin >> r >> c;
  string s;
  for (int i=0; i<r; i++) {
    cin >> s;
    for (int j=0; j<c; j++) {
      arr[i][j] = s[j];
      if (s[j] == 'X') ground.push_back({i, j});
    }
  }
  vector <pair<int,int>> melt;
  int sx = INT_MAX;
  int ex = 0;
  int sy = INT_MAX;
  int ey = 0;

  for (int i=0; i<ground.size(); i++) {
    int x = ground[i].first;
    int y = ground[i].second;
    int water_cnt = around_water(x, y);
    if (water_cnt >= 3) {
      melt.push_back({x, y});
    } else {
      sx = min(sx, x);
      ex = max(ex, x);
      sy = min(sy, y);
      ey = max(ey, y);
    }
  }
  for (int i=0; i<melt.size(); i++) {
    arr[melt[i].first][melt[i].second] = '.';
  }
  for (int i=sx; i<=ex; i++) {
    for (int j=sy; j<=ey; j++) cout << arr[i][j];
    cout << "\n";
  }
}