#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int r,c;
int arr[751][751];
int dp[751][751][2]; // 0 : upper 1 : lower

int range_chk(int x, int y) {
    if (x>=0 && y>=0 && x<r && y<c) return 1;
    return 0;
}
int main() {
    cin >> r >> c;
    string s;
    int ans = 0;
    for (int i=0; i<r; i++) {
        cin >> s;
        for (int j=0; j<c; j++) {
            int num = s[j]-'0';
            ans = max(ans, num);
            arr[i][j] = num; 
            dp[i][j][0] = num;
            dp[i][j][1] = num;
        }
    }
    // positive 
    for (int i=1; i<r; i++) {
        for (int j=0; j<c-1; j++) {
            if (arr[i][j] == 0) continue;
            dp[i][j][0] = dp[i-1][j+1][0] + 1;
        }
    }
    // negative
    for (int i=r-2; i>=0; i--) {
        for (int j=c-2; j>=0; j--) {
            if (arr[i][j] == 0) continue;
            dp[i][j][1] = dp[i+1][j+1][1] + 1;
        }
    }
    for (int k=2; k<=375; k++) {
        for (int i=0; i<r; i++) {
            for (int j=0; j<c;j++) {
                if (dp[i][j][0] < k) continue;
                int len = k - 1;
                if (range_chk(i+len,j+len) && dp[i+len][j+len][0] >= k) {
                    if (dp[i][j][1] >= k) {
                        if (range_chk(i-len,j+len) && dp[i-len][j+len][1]>=k) {
                            ans = max(ans, k);
                        }
                    }
                }
            }
        }
    }
    cout << ans;
}