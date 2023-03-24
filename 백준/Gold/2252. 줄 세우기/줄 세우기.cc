#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<string>
#include<stack>
#include<queue>
using namespace std;

int V, E, st;
bool visited[33000];
vector <int> edge[33000];
stack <int> result;

void dfs(int now) {
	visited[now] = 1;
	for (int i = 0; i < edge[now].size(); i++) {
		if (edge[now][i] && !visited[edge[now][i]])
			dfs(edge[now][i]);
	}
	result.push(now);
}

int main() {
	cin >> V >> E;
	int a, b;
	for (int i = 1; i <= E; i++) {
		cin >> a >> b;
		edge[a].push_back(b);
	}
	for (int i = 1; i <= V; i++) {
		if (!visited[i]) dfs(i);
	}
	while (!result.empty()) {
		cout << result.top() << " ";
		result.pop();
	}
}