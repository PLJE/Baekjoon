#include <iostream>
#include <map>
#include <sstream>
#include <cstring>
#include <string>
#include <climits>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M, start, dest;
vector<pair<int,int>> fee[1001];
vector<int> cost(1001, INT_MAX);

void dijkstra(int start) {
    priority_queue <pair<int,int>> pq;
    cost[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int now = pq.top().second;
        int c = -pq.top().first;
        pq.pop();
        if (cost[now] < c) continue;

        for (int i=0; i<fee[now].size(); i++) {
            int next = fee[now][i].first;
            int ncost = fee[now][i].second;
            if (cost[next] > c + ncost) {
                cost[next] = c + ncost;
                pq.push({-cost[next], next});
            }
        }
    }
}
int main() {
    cin >> N >> M;
    int a, b, c;
    for (int m=1; m<=M; m++) {
        cin >> a >> b >> c;
        fee[a].push_back({b, c});
    }
    cin >> start >> dest;
    dijkstra(start);
    cout << cost[dest];
}