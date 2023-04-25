#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>

using namespace std;

int N;
vector <pair<int,int>> mat;
int dp[501][501];

int topdown(int i, int j) {
    if (dp[i][j] != INT_MAX) return dp[i][j];

    if (j-i == 1) {
        dp[i][j] = mat[i].first * mat[i].second * mat[j].second;
        return dp[i][j];
    }
    if (i==j) return 0;

    for (int k=i; k<j; k++) {
        dp[i][j] = min(dp[i][j], 
        mat[i].first * mat[k+1].first * mat[j].second
        + topdown(i,k) + topdown(k+1,j));
    }

    return dp[i][j];
}

int main() {
    cin >> N;
    int a,b;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            dp[i][j] = INT_MAX;
        }
    }
    for (int i=1; i<=N; i++) {
        cin >> a >> b;
        mat.push_back({a, b});
    }
    cout << topdown(0, N-1);
}