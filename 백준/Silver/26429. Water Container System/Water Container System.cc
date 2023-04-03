#include <iostream>
#include <map>
#include <sstream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int T,N,Q;
int level[65600];
int visit[65600];
vector<int> edges[65600];

void dfs(int now, int lev) {
    visit[now] = 1;
    for (int i=0; i<edges[now].size(); i++) {
        int child = edges[now][i];
        if (visit[child] == 0) {
            level[lev]++;
            dfs(child, lev+1);
        }
    }
}
void init(int n){
    for (int i=0; i<=n; i++) {
        level[i] = 0;
        visit[i] = 0;
        edges[i].clear();
    }
}
int main() {
    cin >> T;
    for (int t=1; t<=T; t++) {
        cin >> N >> Q;
        init(N);
        int a, b;
        for (int i=1; i<=N-1; i++) {
            cin >> a >> b;
            edges[a].push_back(b);
            edges[b].push_back(a);
        }
        level[0]++;
        dfs(1, 1);
        for (int i=1; i<=Q; i++) {
            cin >> a;
        }
        int ans = 0;
        if (Q >= N) ans = N;
        else {
            for (int i=0; level[i]!=0; i++) {
                int cnt = level[i];
                if (cnt > Q) break;
                ans += cnt;
                Q -= cnt;
            }
        }
        cout << "Case #" << t << ": " << ans << "\n";
    }
}