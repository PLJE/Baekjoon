#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int T, N;
int arr[10005][10005];

bool range(int x, int y) {
    if (x>=0 && y>=0 && x<=10000 && y<=10000) return true;
    return false;
}
int increment(int x, int y) {
    int ans = 0;
    for (int i=0; i<=10; i++) {
        for (int j=0; j<=10; j++) {
            int nx = x + i;
            int ny = y + j;
            if (range(nx, ny)) {
                arr[nx][ny]++;
                ans = max(ans, arr[nx][ny]);
            }
        }
    }
    return ans;
}
void print() {
    for (int i=0;i<=60;i++) {
        for (int j=0;j<=60;j++) cout << arr[i][j];
        cout << "\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;   
    while (T--) {
        memset(arr, 0, sizeof(arr));
        cin >> N;
        int x, y;
        int ans = 0;
        for (int i=0; i<N; i++) {
            cin >> x >> y;
            ans = max(ans,increment(x-10,y-10));
        }
        cout << ans << "\n";
    }
}   