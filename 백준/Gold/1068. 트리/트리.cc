#include <iostream>
#include <map>
#include <sstream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int N, rm, ans;
int visit[50];
vector<int> edge[50];

void dfs(int n) {
    visit[n] = 1;
    int tmp = 0;
    for (int i=0; i<edge[n].size(); i++) {
        int next = edge[n][i];
        if (visit[next] == 0 && next != rm) {
            tmp++;
            dfs(next);
        }
    }
    if (tmp == 0) {
        ans++;
    }
}

int main() {
    cin >> N;
    int x, root;
    for (int n=0; n<N; n++) {
        cin >> x;
        if (x == -1) {
            root = n;
        } else {
            edge[n].push_back(x);
            edge[x].push_back(n);
        }
    }
    cin >> rm;
    if (rm == root) {
        cout << 0;
        return 0;
    }
    dfs(root);
    cout << ans;
}