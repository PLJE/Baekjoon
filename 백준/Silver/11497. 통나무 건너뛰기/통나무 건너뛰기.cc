#include <iostream>
#include <cmath>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <deque>

using namespace std;

int T, N;

int main() {
    cin >> T;
    int x;
    for (int t=0; t<T; t++) {
        vector <int> height;
        cin >> N;
        for (int i=0; i<N; i++) {
            cin >> x;
            height.push_back(x);
        }
        sort(height.begin(), height.end());
        deque <int> dq = {height[N-3], height[N-1], height[N-2]};
        int ans = 0;
        ans = max(abs(height[N-1]-height[N-2]), abs(height[N-1]-height[N-3]));
        for (int i=N-4; i>=0; i--) {
            if (dq.back() >= dq.front()) {
                ans = max(ans, abs(height[i]-dq.back()));
                dq.push_back(height[i]);
            } else {
                ans = max(ans, abs(height[i]-dq.front()));
                dq.push_front(height[i]);
            }
        }
        ans = max(ans, abs(dq.front()-dq.back()));
        cout << ans << "\n";
    }
}