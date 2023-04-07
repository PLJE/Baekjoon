#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int T, N;
int dp[100001];

int main() {
    cin >> T;
    string s;
    for (int t=1; t<=T; t++) {
        cin >> N;
        memset(dp, 0, sizeof(dp));
        vector <int> num = {-1};
        int x;
        for (int i=0; i<N; i++) {
            cin >> x;
            num.push_back(x);
        }
        sort(num.begin(), num.end());
        dp[1] = 1;
        for (int i=2; i<=N; i++) {
            if (num[i] >= dp[i-1] + 1) {
                dp[i] = dp[i-1] + 1;
            } else {
                dp[i] = dp[i-1];
            }
        }
        cout << "Case #" << t << ": " << dp[N] << "\n";
    }
} 