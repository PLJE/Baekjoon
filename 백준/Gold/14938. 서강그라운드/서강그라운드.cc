#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
#include <climits>

using namespace std;

int node[101][101];
int item[101];
int n, m, r, t;

int dijk(int start) {
    priority_queue <pair<int, int>> pq;
    int distance[101];
    for (int i=1; i<=n; i++) {
        distance[i] = INT_MAX;
    }
    distance[start] = 0;

    pq.push({0, start});
    while(!pq.empty()) {
        int now = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();

        for (int i=1; i<=n; i++) {
            if (node[now][i]!= 0 && distance[i] > cost + node[now][i]) {
                distance[i] = cost + node[now][i];
                pq.push({-distance[i], i});
            }
        }
    }

    int items = 0;
    for (int i=1; i<=n; i++) {
        if (distance[i] <= m) {
            items += item[i];
        }
    }
    return items;
}

int main() {
    int dab = 0;
    cin >> n >> m >> r;
    for (int i=1; i<=n; i++) {
        cin >> item[i];
    }
    int a, b, c;
    for (int j=1; j<=r; j++) {
        cin >> a >> b >> c;
        node[a][b] = c;
        node[b][a] = c;
    }
    for (int i=1; i<=n; i++) {
        dab = max(dab, dijk(i));
    }
    cout << dab;
}