#include <iostream>
#include <set>
#include <algorithm>
#include <string>
#include <climits>
#include <vector>
#include <queue>

using namespace std;

int N;
int like[101][101]; // 0: like , 1 : unlike
int parent[101];
int group_size[101];

int find_parent (int x) {
    if (parent[x] == x) return x;
    return parent[x] = find_parent(parent[x]);
}
int main() {
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            cin >> like[i][j];
        }
        parent[i] = i;
        group_size[i] = 1;
    }
    for (int i=1; i<=N; i++) {
        for (int j=i+1; j<=N; j++) {
            if (like[i][j] == 1) continue;
            int pi = find_parent(i);
            int pj = find_parent(j);
            if (pi == pj) continue;
            if (group_size[pi] <= group_size[pj]) {
                parent[pi] = pj;
                group_size[pj] += group_size[pi];
            } else {
                parent[pj] =  pi;
                group_size[pi] += group_size[pj];
            }
        }
    }
    vector<int> members[101];
    for (int i=1; i<=N; i++) {
        if (group_size[parent[i]] == 1) {
            cout << 0;
            return 0;
        }
        members[parent[i]].push_back(i);
    }
    vector <vector<int>> groups;
    for (int i=1; i<=N; i++) {
        if (members[i].size() == 0) continue;
        sort(members[i].begin(), members[i].end());
        groups.push_back(members[i]);
    }
    sort(groups.begin(), groups.end());
    int group_cnt = groups.size();
    cout << group_cnt << "\n";
    for (int i=0; i<group_cnt; i++) {
        for (int j=0; j<groups[i].size(); j++) {
            cout << groups[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}