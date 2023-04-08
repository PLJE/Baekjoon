#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

int T, N;

int main() {
    cin >> T;
    for (int t=1; t<=T; t++) {
        cin >> N;
        int x;
        deque <int> dq;
        for (int i=0; i<N; i++) {
            cin >> x;
            dq.push_back(x);
        }
        vector <int> cakes;
        while (!dq.empty()) {
            if (dq.size() == 1) {
                cakes.push_back(dq.front());
                break;
            }
            if (dq.front() <= dq.back()) {
                cakes.push_back(dq.front());
                dq.pop_front();
            } else {
                cakes.push_back(dq.back());
                dq.pop_back();
            }
        }
        int cnt = 1;
        int cur = cakes[0];
        for (int i=1; i<N; i++) {
            if (cur <= cakes[i]) {
                cnt++;
                cur = cakes[i];
            }
        }
        cout << "Case #" << t << ": " << cnt << "\n";
    }
} 