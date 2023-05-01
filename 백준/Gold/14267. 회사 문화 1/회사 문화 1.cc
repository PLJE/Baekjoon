#include <iostream>
#include <cstring>
#include <set>
#include <algorithm>
#include <string>
#include <climits>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<int> supervisor[100005];
int score[100005];
int ans[100005];

int main() {
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    int x;
    for (int i=1; i<=N; i++) {
        cin >> x;
        if (x==-1) continue;
        supervisor[x].push_back(i);
    }
    int a,b;
    for (int i=0; i<M; i++) {
        cin >> a >> b;
        score[a] += b;
    }
    queue <pair<int,int>> q;
    q.push({1, score[1]});
    while (!q.empty()) {
        int now = q.front().first;
        int now_score = q.front().second;
        q.pop();

        ans[now] += now_score;

        for (int i=0; i<supervisor[now].size(); i++) {
            int next = supervisor[now][i];
            int next_score = score[next];
            q.push({next, now_score + next_score});
        }
    }
    for (int i=1; i<=N; i++) cout << ans[i] << " ";

    return 0;
}