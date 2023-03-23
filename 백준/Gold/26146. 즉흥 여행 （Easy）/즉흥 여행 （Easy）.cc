#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <stdlib.h>
#include <map>
#include <set>
#include <stack>

using namespace std;

int N, M, scc;
int cnt = 1;
vector<int> edge[200001];
vector<int> edge_reversed[200001];
int visit[200001];
stack <pair<int,int>> st;

void dfs(int now) {
    visit[now] = 1;
    int len = edge[now].size();
    
    for (int i=0; i<len; i++) {
        int next = edge[now][i];
        if (visit[next] == 0) {
            dfs(next);
            st.push({next, cnt++});
        }
    }
}
void dfs2(int now) {
    visit[now] = 1;
    int len = edge_reversed[now].size();
    scc++;

    for (int i = 0; i < len; i++) {
        int next = edge_reversed[now][i];
        if (visit[next] == 0) {
            dfs2(next);
        }
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge_reversed[b].push_back(a);
    }
    // first dfs
    for (int i=1; i<=N; i++) {
        if (visit[i] == 0) {
            dfs(i);
            st.push({i, cnt++});
        }
    }
    memset(visit, 0, sizeof(visit));
    // second dfs
    dfs2(st.top().first);

    if (scc != N) cout << "No";
    else cout << "Yes";

    return 0;
}
