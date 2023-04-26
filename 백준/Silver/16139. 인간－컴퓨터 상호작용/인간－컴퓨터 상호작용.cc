#include <iostream>
#include <deque>
#include <string>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#include <climits>
#include <set>
#include <vector>

using namespace std;

string str;
int N;
int dp[27][200005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> str;
    int slen = str.length();
    cin >> N;
    for (int i=0; i<slen; i++) {
        int num = int(str[i]) - 97;
        dp[num][i]++;
        for (int j=0; j<26; j++) {
            dp[j][i] += dp[j][i-1];
        }
    }
    char c;
    int from, to;
    for (int i=0; i<N; i++) {
        cin >> c >> from >> to;
        int num = int(c) - 97;
        cout << dp[num][to] - dp[num][from-1] << "\n";
    }
}
