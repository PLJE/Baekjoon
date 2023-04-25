#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>

using namespace std;

int N, M;
vector<int> edge[10001];
int visit[10001];
int cnt[10001];

bool comp (pair<int,int> a, pair<int,int> b) {
    if (a.first == b.first) {
        return a.second > b.second;
    }
    return a.first < b.first;
}

int main() {
    cin >> N >> M;
    int a, b;
    for (int i=0; i<M; i++) {
       cin >> a >> b;
       edge[a].push_back(b);
    }
    for (int i=1; i<=N; i++) {
        memset(visit, 0, sizeof(visit));

        int start = i;
        queue <int> q;
        q.push(start);
        while(!q.empty()) {
            int now = q.front();
            visit[now] = 1;
            q.pop();

            for (int j=0; j<edge[now].size(); j++) {
                int next = edge[now][j];
                if (visit[next] == 0) {
                    visit[next] = 1;
                    q.push(next);
                    cnt[next]++;
                }
            }
        }
    }
    vector <pair<int,int>> get_max;
    for (int i=1; i<=N; i++) {
        get_max.push_back({cnt[i], i});
    }
    sort(get_max.begin(), get_max.end(), comp);
    int max_val = get_max[N-1].first;
    for (int i=N-1; i>=0; i--) {
        if (max_val == get_max[i].first) {
            cout << get_max[i].second << " ";
        }
    }
} 