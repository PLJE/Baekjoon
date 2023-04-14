#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int visit[20001];
int dist[20001];
int edges[20001][20001];

int solution(int n, vector<vector<int>> edge) {
    for (int i=0; i<edge.size(); i++) {
        int a = edge[i][0];
        int b = edge[i][1];
        edges[a][b] = 1;
        edges[b][a] = 1;
    }
    visit[1] = 1;
    queue <pair<int,int>> q;
    q.push({1, 0});
    int max_distance = 0;
    while (!q.empty()) {
        int now = q.front().first;
        int distance = q.front().second;
        max_distance = max(max_distance, distance);
        dist[now] = distance;
        q.pop();
        
        for (int i=1; i<=n; i++) {
            if (edges[now][i] && !visit[i]) {
                visit[i] = 1;
                q.push({i, distance + 1});
            }
        }
    }
    int ans = 0;
    for (int i=1; i<=n; i++) if(dist[i] == max_distance) ans++;
    return ans;
}