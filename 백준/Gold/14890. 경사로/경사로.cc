#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <stdlib.h>
using namespace std;

int N, L, ans;
int arr[101][101];
int slide[101][101];

bool chk(int x, int y, int height) {
    if (x>=1 && y>=1 && x<=N && y<=N && arr[x][y] == height
        && slide[x][y] ==0) return true;
    return false;
}
bool chkLine(int sx, int sy, bool is_row) {
    if (is_row) {
        for (int col=sy+1; col<=N; col++) {
            if (abs(arr[sx][col-1]-arr[sx][col]) >= 2) return false;
            if (arr[sx][col-1] + 1 == arr[sx][col]) {
                for (int j=col-1; j>col-1-L; j--) {
                    if (!chk(sx, j, arr[sx][col-1])) return false;
                    slide[sx][j] = 1;
                }
            } else if (arr[sx][col-1] - 1 == arr[sx][col]) {
                for (int j=col; j<col+L; j++) {
                    if (!chk(sx, j, arr[sx][col])) return false;
                    slide[sx][j] = 1;
                }
            }
        }
    } else {
        for (int row=sx+1; row<=N; row++) {
            if (abs(arr[row-1][sy]-arr[row][sy]) >= 2) return false;
            if (arr[row-1][sy] + 1 == arr[row][sy]) {
                for (int i=row-1; i>row-1-L; i--) {
                    if (!chk(i, sy, arr[row-1][sy])) return false;
                    slide[i][sy] = 1;
                }
            } else if (arr[row-1][sy] - 1 == arr[row][sy]) {
                for (int i=row; i<row+L; i++) {
                    if (!chk(i, sy, arr[row][sy])) return false;
                    slide[i][sy] = 1; 
                }
            }
        }
    }
    return true;
}
int main()
{
    cin >> N >> L;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i=1; i<=N; i++) {
        if (chkLine(i, 1, true)) ans++;
    }
    memset(slide, 0, sizeof(slide)); // 행과 열은 따로더라..
    for (int i = 1; i <= N; i++) {
        if (chkLine(1, i, false)) ans++;
    }
    cout << ans;
}
