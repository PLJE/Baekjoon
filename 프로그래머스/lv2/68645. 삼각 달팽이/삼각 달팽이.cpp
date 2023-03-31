#include <string>
#include <vector>
#include <iostream>

using namespace std;

int arr[1001][1001];
int visit[1001][1001];

int range_chk(int x, int y, int n) {
    if (x>=1 && y>=1 && x<=n && y<=n && !visit[x][y]) return 1;
    return 0;
}
vector<int> solution(int n) {
    vector<int> answer;
    int max_val = (n * (n+1)) / 2;
    int cnt = 1;
    int sx = 1; int sy = 1;
    while (cnt <= max_val) {
        while (range_chk(sx,sy,n)) {
            arr[sx][sy] = cnt++;
            visit[sx][sy] = 1;
            sx++;
        }
        sx--; sy++;
        while (range_chk(sx, sy, n)) {
            arr[sx][sy] = cnt++;
            visit[sx][sy] = 1;
            sy++;
        }
        sy -= 2; sx--;
        while (range_chk(sx, sy, n)) {
            arr[sx][sy] = cnt++;
            visit[sx][sy] = 1;
            sx--; sy--;
        }
        sx += 2; sy++;
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=i; j++) {
            answer.push_back(arr[i][j]);
        }
    }
    return answer;
}