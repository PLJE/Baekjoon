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
    queue <pair<int,int>> q;
    q.push({N, 0});

    while (!q.empty()) {
        int now = q.front().first;
        int sec = q.front().second;
        if (now == K) {
            cout << sec;
            break;
        }
        q.pop();
        visit[now] = 1;

        if (now+1 <= 100000 && visit[now+1] == 0) {
            q.push({now+1, sec+1});
        }
        if (now-1>=0 && visit[now-1] == 0) {
            q.push({now-1, sec+1});
        }
        if (2*now <=100000 && visit[2*now] == 0) {
            q.push({2*now, sec+1});
        }
    }
    return 0;
}