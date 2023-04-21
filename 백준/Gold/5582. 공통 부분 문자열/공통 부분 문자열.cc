#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

string a,b;
int dp[4002][4002];

int main()
{
	cin >> a >> b;
	int ans = 0;
	int r = a.length();
	int c = b.length();
	for (int i=1; i<=r; i++) {
		for (int j=1; j<=c; j++) {
			if (a[i-1] == b[j-1]) {
				dp[i][j] = dp[i-1][j-1] + 1;
				ans = max(ans, dp[i][j]);
			}
		}
	}
	cout << ans;
}
