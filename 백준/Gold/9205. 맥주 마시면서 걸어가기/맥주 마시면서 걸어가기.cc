#include <iostream>
#include <deque>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>

using namespace std;

int T, N;
int visit[105];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for (int t=0; t<T; t++) {
        memset(visit, 0, sizeof(visit));
        cin >> N;
        N += 2;
        int x, y;
        vector <pair<int,int>> xy;
        for (int i=0; i<N; i++) {
            cin >> x >> y;
            xy.push_back({x, y});
        }
        // 노드 0 ~ N-1 , 0시작 N-1 도착, 나머지 편의점
        vector<pair<int,int>> edge[105];
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                if (i==j) continue;
                int distance = abs(xy[i].first-xy[j].first) + abs(xy[i].second-xy[j].second);
                edge[i].push_back({j, distance});
                edge[j].push_back({i, distance});
            }
        }
        bool happy = false;
        queue <pair<int,int>> q;
        q.push({0, 20}); // idx , beer
        visit[0] = 1;

        while(!q.empty()) {
            int now = q.front().first;
            int beer = q.front().second;
            if (now == N-1) {
                happy = true;
                break;
            }
            if (now >=1 && now<=N-2) beer = 20;
            q.pop();

            for (int i=0; i<edge[now].size(); i++){
                int next = edge[now][i].first;
                int next_cost = edge[now][i].second;
                if (visit[next] || next_cost > beer * 50) continue;
                visit[next] = 1;
                int drink = next_cost / 50;
                if (next_cost % 50 != 0) drink++;
                q.push({next, beer - drink});
            }
        }
        if (happy) cout << "happy\n";
        else cout << "sad\n"; 
    }
}
