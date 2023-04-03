#include <iostream>
#include <map>
#include <sstream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int V, mval, midx;
vector<pair<int,int>> edges[100001];
int visit[100001];

void get_input() {
    int a;
    for (int v=1; v<=V; v++) {
        cin >> a;
        int b = 0; int c = 0;
        while (1) {
            cin >> b;
            if (b == -1) break;
            cin >> c;
            edges[a].push_back({b,c});
        }
    }
}
void dfs(int now, int cost) {
    visit[now]=1;
    if (mval < cost) {
        mval = cost;
        midx = now;
    }
    for (int i=0; i<edges[now].size(); i++) {
        int next = edges[now][i].first;
        int ncost = edges[now][i].second;
        if (visit[next] == 0) {
            dfs(next, cost + ncost);
        }
    }
}
int main() {
    cin >> V;
    get_input();
    dfs(2, 0);
    memset(visit, 0, sizeof(visit));
    int point = midx;
    mval = 0;
    dfs(point, 0);
    cout << mval;
}