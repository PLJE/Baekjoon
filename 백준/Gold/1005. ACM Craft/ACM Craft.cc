#include <string>
#include <vector>
#include <iostream>
#include<cstring>
#include <stack>
#include<iostream>
#include<climits>
#include<queue>
using namespace std;

int T, N, K,W;
int cost[1001];
int indeg[1001];
int dp[1001];

int main() {
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N >> K;
		queue <int> q;
		memset(cost, 0, sizeof(cost));
		memset(indeg, 0, sizeof(indeg));
		vector<int> edg[1001];
		for (int i = 1; i <= N; i++) {
			cin >> cost[i];
			dp[i] = cost[i];
		}
		int pre, nex;
		for (int i = 0; i < K; i++) {
			cin >> pre >> nex;
			indeg[nex]++;
			edg[pre].push_back(nex);
		}
		cin >> W;
		for (int i = 1; i <= N; i++) {
			if (indeg[i] == 0)
				q.push(i);
		}

		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			if (cur == W) break;

			for (int i = 0; i < edg[cur].size(); i++) {
				int n = edg[cur][i];
				if (indeg[n] > 0) {
					indeg[n]--;
					dp[n] = max(dp[n], dp[cur]+cost[n]);
					if (indeg[n] == 0) {
						q.push(n);
					}
				}
			}
		}
		/*for (int i = 1; i <= N; i++) {
			cout << dp[i] << "\n";
		}*/
		cout << dp[W] << "\n";
	}
}