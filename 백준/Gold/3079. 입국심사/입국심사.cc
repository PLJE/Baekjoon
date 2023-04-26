#include <iostream>
#include <deque>
#include <string>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#include <climits>
#include <set>
#include <vector>

using namespace std;

int N,M;
vector <int> desk;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    long long x;
    for (int i=0; i<N; i++) {
        cin >> x;
        desk.push_back(x);
    }
    long long left = 0;
    long long right = 1000000000000000000;
    long long ans = right;
    while (left <= right) {
        long long mid = (left+right)/2;

        long long possible_cnt = 0;
        for (int i=0; i<N; i++) {
            if (possible_cnt >= M) break;
            possible_cnt += (mid / desk[i]);
        }
        if (possible_cnt < M) {
            left = mid + 1;
        } else {
            ans = min(ans, mid);
            right = mid - 1;
        }
    }
    cout << ans;
}
