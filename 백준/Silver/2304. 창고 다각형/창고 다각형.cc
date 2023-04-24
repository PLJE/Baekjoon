#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

int N, ans;
vector <pair<int,int>> height;
int visit[1005];

int main() { 
    cin >> N;
    int x, h;
    int max_height = 0;
    for (int i=0; i<N; i++) {
        cin >> x >> h;
        height.push_back({x,h});
        max_height = max(max_height, h);
    }
    sort(height.begin(), height.end());
    int left_idx = height[0].first;
    int left_hei = height[0].second;
    int leftmost;
    for (int i=1; i<N; i++) {
        int idx = height[i].first;
        int hei = height[i].second;
        if (left_hei > hei) continue;
        ans += ((idx-left_idx)*left_hei);
        left_idx = idx;
        left_hei = hei;
        leftmost = i;
    }
    int right_idx = height[N-1].first;
    int right_hei = height[N-1].second;
    for (int i=N-2; i>=leftmost; i--) {
        int idx = height[i].first;
        int hei = height[i].second;
        if (right_hei > hei) continue;
        else {
            ans += ((right_idx-idx)*right_hei);
            right_idx = idx;
            right_hei = hei;
        }
    }
    ans += max_height;
    cout << ans;
}
