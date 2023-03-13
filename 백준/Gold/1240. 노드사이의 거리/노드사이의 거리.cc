#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

vector <pair<int, int>> edge[1001];
int visit[1001];

int main() {
    int N, M;
    cin >> N >> M;
    int a, b, c;
    for (int i = 1; i <= N - 1; i++) {
        cin >> a >> b >> c;
        edge[a].push_back({ b,c });
        edge[b].push_back({ a,c });
    }
    for (int i = 1; i <= M; i++) {
        cin >> a >> b;
        queue <pair<int, int>> q;
        memset(visit, 0, sizeof(visit));
        q.push({ a,0 });
        visit[a] = 1;

        while (!q.empty()) {
            int now = q.front().first;
            int cost = q.front().second;
            q.pop();
            if (now == b) {
                cout << cost << "\n";
                break;
            }
            for (int j = 0; j < edge[now].size(); j++) {
                int next = edge[now][j].first;
                if (visit[next] == 0) {
                    int next_cost = edge[now][j].second;
                    q.push({ next, cost + next_cost });
                    visit[next] = 1;
                }
            }
        }
    }
}