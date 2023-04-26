#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>

using namespace std;

int N, M;
vector <int> num;
int dp[2001][2001]; // a ~ b 가 팰린드롬이면 1, 아니면 0 , 초기값 INT_MAX

int sol(int a, int b) {
    if (dp[a][b] != INT_MAX) return dp[a][b];
    if (num[a] != num[b]) {
        dp[a][b] = 0;
        return dp[a][b];
    }

    if (a == b) {
        dp[a][b] = 1;
        return 1;
    }
    if (b-a == 1) {
        if (num[a] == num[b]) {
            dp[a][b] = 1;
        }
        return dp[a][b];
    }
    if (b-a == 2) {
        if (num[a] == num[b]) {
            dp[a][b] = 1;
        }
        return dp[a][b];
    }
    
    dp[a][b] = sol(a+1, b-1);

    return dp[a][b];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    int x, y;
    for (int i=0; i<N; i++) {
        cin >> x;
        num.push_back(x);
        for (int j=0;j<N;j++) dp[i][j] = INT_MAX;
    }
    cin >> M;
    for (int i=0; i<M; i++) {
        cin >> x >> y;
        int is_pal = sol(x-1, y-1);
        if (is_pal == 1) cout << 1 << "\n";
        else cout << 0 << "\n";
    }
} 