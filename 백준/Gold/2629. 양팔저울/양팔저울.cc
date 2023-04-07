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

int dp[31][31][15001];
int N, M;
vector <int> weight;

void recur(int i, int j, int k) {
    if (dp[i][j][k] == 1) return;
    dp[i][j][k] = 1;
    if (j == N) return;

    recur(i, j+1, k);
    recur(i, j+1, weight[j+1]);
    recur(i, j+1, k + weight[j+1]);
    recur(i, j+1, abs(k-weight[j+1]));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    int x;
    weight.push_back(-1);
    for (int i=0; i<N; i++) {
        cin >> x;
        weight.push_back(x);
    }
    recur(1, 1, weight[1]);
    cin >> M;
    for (int i=0; i<M; i++) {
        cin >> x;
        if (dp[1][N][x] == 1) cout << "Y ";
        else cout << "N ";
    }
} 