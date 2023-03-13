#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int num[101];
long long dp[101][21];

int main()
{
    cin >> N;
    for (int i=1; i<=N; i++) {
        cin >> num[i];
    }
    dp[1][num[1]] = 1;
    for (int i=2; i<=N-1; i++) {
        for (int j=0; j<=20; j++) {
            if (dp[i-1][j] != 0) {
                if (j - num[i] >=0 && j - num[i] <= 20) {
                    dp[i][j-num[i]] += dp[i-1][j];
                }
                if (j + num[i] >= 0 && j + num[i] <= 20) {
                    dp[i][j+num[i]] += dp[i-1][j];
                }
            }
        }
    }
    int target = num[N];
    cout << dp[N-1][target];
}