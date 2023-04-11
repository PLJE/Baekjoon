#include <iostream>
#include <climits>
#include <string>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int N, K;
int visit[100001];

int main() {
    cin >> N >> K;
    for (int i=0; i<=100000; i++) visit[i] = INT_MAX;
    priority_queue <pair<int,int>> q;
    q.push({0, N});
    
    while (!q.empty()) {
        int now = q.top().second;
        int sec = -q.top().first;
        q.pop();
        if (visit[now] > sec) {
            visit[now] = sec;
        }
        if (now+1 <= 100000 && visit[now+1] > sec + 1) {
            q.push({-(sec+1), now+1});
        }
        if (now-1>=0 && visit[now-1] > sec + 1) {
            q.push({-(sec+1), now-1});
        }
        if (2*now <=100000 && visit[2*now] > sec) {
            q.push({-sec, 2*now});
        }
    }
    cout << visit[K];
    return 0;
}