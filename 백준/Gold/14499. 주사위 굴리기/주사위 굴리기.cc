#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <stdlib.h>
#include <map>

using namespace std;

int N, M, x, y, K;
int arr[21][21];
int dice[7]; int tmp[7];
int dx[5] = {0, 0, 0, -1, 1};
int dy[5] = {0, 1, -1, 0, 0};
int mv[7][5] = {
    {0,0,0,0,0},
    {0,3,4,2,5},
    {0,2,2,6,1},
    {0,6,1,3,3},
    {0,1,6,4,4},
    {0,5,5,1,6},
    {0,4,3,5,2}
};

bool range_chk(int x, int y) {
    if (x>=1 && y>=1 && x<=N && y<=M) return true;
    return false;
}
int main()
{
    cin >> N >> M >> x >> y >> K;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            cin >> arr[i][j];
        }
    }
    int dir;
    int cur_x = x+1;
    int cur_y = y+1;
    for (int i=0; i<K; i++) {
        cin >> dir;
        if(!range_chk(cur_x+dx[dir], cur_y+dy[dir])) continue;
        cur_x = cur_x + dx[dir];
        cur_y = cur_y + dy[dir];

        for (int j=1; j<=6; j++) {
            tmp[mv[j][dir]] = dice[j];
        }
        for (int j = 1; j <= 6; j++) {
            dice[j] = tmp[j];
        }

        if (arr[cur_x][cur_y] == 0) {
            arr[cur_x][cur_y] = dice[6];
        } else {
            dice[6] = arr[cur_x][cur_y];
            arr[cur_x][cur_y] = 0;
        }
        cout << dice[1] << "\n";
    }
    return 0;
}
