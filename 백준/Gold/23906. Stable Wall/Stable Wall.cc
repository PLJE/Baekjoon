#include <iostream>
#include <cstring>
#include <queue>
#include <set>
#include <climits>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

int T, cnt;
int R, C, last;
int arr[31][31];
int indegree[27];

int range(int x, int y) {
    if (x>=0 && y>=0 && x<R && y<C) return 1;
    return 0;
}
int main() { 
    cin >> T;
    for (int t=1; t<=T; t++) {
        cin >> R >> C;
        int node = 1;
        map <char, int> idx;
        map <int, char> ch;

        for (int i=0; i<R; i++) {
            string s;
            cin >> s;
            for (int j=0; j<C; j++) {
                if (idx.find(s[j]) == idx.end()) {
                    ch[node] = s[j];
                    idx[s[j]] = node++;
                }
                arr[i][j] = idx[s[j]];
            }
        }
        node--;
        vector <int> edges[27];
        for (int i=1; i<=node; i++) {
            for (int k=0; k<R; k++) {
                for (int j=0; j<C; j++) { // k,j
                    if (arr[k][j] != i) continue;
                    if (k < R-1 && arr[k+1][j] != i) {
                        edges[arr[k+1][j]].push_back(i);
                    }
                }
            }
        }
        for (int i=1; i<=node; i++) {
            edges[i].erase(unique(edges[i].begin(), edges[i].end()), edges[i].end());
        }
        memset(indegree, 0, sizeof(indegree));
        for (int i=1; i<=node; i++) {
            for (int j=0; j<edges[i].size(); j++) {
                indegree[edges[i][j]]++;
            }
        }
        queue <int> q;
        for (int i=1; i<=node; i++) {
            if (indegree[i] == 0) q.push(i);
        }
        bool unstable = false;
        if (q.size() == 0) {
            unstable = true;
        }
        vector <int> order;
        while (!q.empty()) {
            int now = q.front();
            order.push_back(now);
            q.pop();

            for (int i=0; i<edges[now].size(); i++) {
                int next = edges[now][i];
                indegree[next]--;
                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }
        for (int i=1; i<=node; i++) {
            if (indegree[i] != 0) {
                unstable = true;
                break;
            }
        }
        if (unstable) {
            cout << "Case #" << t << ": " << -1 << "\n";
        } else {
            cout << "Case #" << t << ": ";
            for (int i=0; i<order.size(); i++) {
                cout << ch[order[i]];
            }
            cout << "\n";
        }
    }
}
