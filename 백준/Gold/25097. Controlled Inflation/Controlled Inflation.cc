#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int T, N, P;
long long dp[1001][101];

int main() {
    cin >> T;
    for (int t=1; t<=T; t++) {
        cin >> N >> P;
        memset(dp, 0, sizeof(dp));
        vector <vector<int>> arr;
        int x;
        for (int i=1; i<=N; i++) {
            vector <int> v;
            for (int j=1; j<=P; j++) {
                cin >> x;
                v.push_back(x);
            }
            sort(v.begin(), v.end());
            arr.push_back(v);
        }
        long long ans = 0;
        for (int i=0; i<N; i++) {
            for (int j=1; j<P; j++) {
                ans += abs(arr[i][j] - arr[i][j-1]);
            }
        }
        dp[0][0] = arr[0][0];
        dp[0][1] = arr[0][P-1];
        for (int i=1; i<N; i++) {
            int before_min = arr[i-1][0];
            int before_max = arr[i-1][P-1];
            int min_val = arr[i][0];
            int max_val = arr[i][P-1];
            dp[i][0] = min(dp[i-1][0] + abs(min_val-before_max), 
            dp[i-1][1] + abs(min_val-before_min));
            dp[i][1] = min(dp[i-1][0] + abs(max_val-before_max),
            dp[i-1][1] + abs(max_val-before_min));
        }
        ans += min(dp[N-1][0], dp[N-1][1]);
        cout << "Case #" << t <<": " << ans <<"\n";
    }
    return 0;
}