#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int r, c, k;
int seat[1001][1001];
int visit[1001][1001];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int turn_right (int dir) {
  return (dir + 1) % 4;
}
bool is_range(int x, int y) {
  if (x>=1 && y>=1 && x<=r && y<=c && !visit[x][y]) return true;
  return false;
}
void print_ans(int x, int y) {
  int ny = r-(x-1);
  int nx = y;
  cout << nx << " " << ny;
}
int main() {
  cin >> c >> r;
  cin >> k;
  if (k > r*c) {
    cout << 0;
    return 0;
  }
  int total_seat = r * c;
  int seat_num = 1;
  int dir = 0;
  int x=r;
  int y=1;
  while (1) {
    seat[x][y] = seat_num;
    if (seat_num == k) {
      print_ans(x, y);
      break;
    }
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    visit[x][y] = 1;
    seat_num++;

    if (seat_num > total_seat) break;

    if (!is_range(nx, ny)) {
      dir = turn_right(dir);
      x = x + dx[dir];
      y = y + dy[dir];
    } else {
      x = nx; 
      y = ny;
    }
  }
  return 0;
}