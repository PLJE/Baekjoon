#include <iostream>
#include <climits>
#include <string>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int N, K;
int visit[100001];

int main() {
    cin >> N >> K;

    if (N > K) {
        cout << N - K << "\n";
        for (int i=N; i>=K; i--) cout << i << " ";
        return 0;
    }
    
    queue <pair<int, vector<int>>> q;
    q.push({0, {N}});

    while (!q.empty()) {
        vector <int> path = q.front().second;
        int now = path.back();
        int sec = q.front().first;
        q.pop();
        visit[now] = 1;

        if (now == K) {
            cout << sec << "\n";
            for (int i=0; i<path.size(); i++) cout << path[i] << " ";
            break;
        }

        if (now+1 <= 100000 && !visit[now+1]) {
            path.push_back(now+1);
            q.push({sec+1, path});
            path.pop_back();
        }
        if (now-1>=0 && !visit[now-1]) {
            path.push_back(now-1);
            q.push({sec+1, path});
            path.pop_back();
        }
        if (2*now <=100000 && !visit[2*now]) {
            path.push_back(now*2);
            q.push({sec+1, path});
            path.pop_back();
        }
    }
    return 0;
}