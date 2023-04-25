#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<string.h>
#include<queue>
#include<tuple>
#include<stack>
#include <climits>
using namespace std;

int N, S;
vector <int> v;
int max_length = 100001;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> S;
	int x;
	for (int i = 0; i < N; i++) {
		cin >> x;
		v.push_back(x);
	}
	int left = 0;
	int right = 0;
	int dab = max_length;
	int sum = v[0];
	while (left <= right  && right < N) {
		if (sum < S) {
			right++;
			if (right == N)break;
			sum += v[right];
		}
		else if (sum >= S) {
			dab = min(dab, right - left + 1);
			sum -= v[left];
			left++;
		}
	}
	if (dab == max_length) cout << 0;
	else cout << dab;
}