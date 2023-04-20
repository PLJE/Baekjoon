#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int N;
long long dp[2][1001]; // O와 A로만 만들 수 있는 것의 개수 0th row : O로끝나는것 1th row : A로 끝나는 것
long long ans = 0;
long long DIVIDE_NUM = 1000000;

int main()
{
	cin >> N;
	if (N == 0) {
		cout << 1;
		return 0;
	}
	if (N == 1) {
		cout << 3;
		return 0;
	}
	dp[0][0] = 1;
	dp[1][0] = 0;
	dp[0][1] = 1;
	dp[1][1] = 1;
	for (int i=2; i<=N; i++) {
		dp[0][i] = (dp[0][i-1] + dp[1][i-1])%DIVIDE_NUM;
		dp[1][i] = (dp[0][i-1] + dp[0][i-2])%DIVIDE_NUM;
	}
	ans = ans + (dp[0][N] + dp[1][N]) % DIVIDE_NUM;

	int middle = N/2;
	if (N%2 == 1) middle++;
	for (int i=1; i<=middle; i++) { // L을 i에 두고 양쪽 개수
		int left = i - 1;
		int right = N - i;
		long long left_cnt = (dp[0][left] + dp[1][left]) % DIVIDE_NUM;
		long long right_cnt = (dp[0][right] + dp[1][right]) % DIVIDE_NUM;
		long long cases = (left_cnt * right_cnt) % DIVIDE_NUM;
		ans += cases;
		ans %= DIVIDE_NUM;
		if (N%2 == 1 && i == middle) break; // 홀수인 경우 L이 중간에 있을 때는 한번만 더해줌
		ans += cases;
		ans %= DIVIDE_NUM;
	}
	cout << ans;
}
