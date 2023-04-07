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

long long dp[101][10001];
long long N, M;
vector <long long> capacity;
vector <long long> fee;

int main() {
    cin >> N >> M;
    long long x;
    for (int i=0; i<N; i++) {
        cin >> x;
        capacity.push_back(x);
    }
    long long total_cost = 0;
    for (int i=0; i<N; i++) {
        cin >> x;
        total_cost += x;
        fee.push_back(x);
    }
    for (int i=1; i<=N; i++) {
        long long cap = capacity[i-1];
        long long cost = fee[i-1];
        for (long long j=0; j<=total_cost; j++) {
            if (cost > j) dp[i][j] = dp[i-1][j];
            else {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-cost] + cap);
            }
        }
    }
    long long ans = total_cost;
    for (int i=1; i<=N; i++) {
        for (long long j=0; j<=total_cost; j++) {
            if (dp[i][j] >= M) {
                ans = min(ans, j);
            }
        }
    }
    cout << ans;
}