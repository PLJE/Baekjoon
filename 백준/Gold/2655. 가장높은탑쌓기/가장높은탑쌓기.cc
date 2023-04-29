#include <iostream>
#include <cstring>
#include <set>
#include <algorithm>
#include <string>
#include <climits>
#include <vector>
#include <queue>

using namespace std;

int N;
int height[101];
int dp[101][101];
int track[101];
vector <vector<int>> area_weight;
vector <int> tower;

bool comp_weight(vector<int> a, vector<int> b) {
    return a[2] < b[2];
}
void back_tracking (int x) { 
    tower.clear();
    tower.push_back(area_weight[x][0]);
    int k = track[x];
    while (1) {
        if (k == -1) break;
        tower.push_back(area_weight[k][0]);
        k = track[k];
    }
}
int main() {
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    int a, h, w;
    track[0] = -1;
    for (int i=1; i<=N; i++) {
        cin >> a >> h >> w;
        height[i] = h;
        track[i] = -1;
        area_weight.push_back({i, a, w}); // {idx , area, weight}
    }
    // weight 기준 정렬
    sort(area_weight.begin(), area_weight.end(), comp_weight);
    for (int i=0; i<N; i++) {
        dp[0][i] = height[area_weight[0][0]];
    }
    int weight_ans = dp[0][0];
    int track_start_idx = 0;
    for (int i=1; i<N; i++) {
        int cur_area = area_weight[i][1];
        int pre_max_height = -1;
        int k;
        for (int j=i-1; j>=0; j--) {
            if (area_weight[j][1] < cur_area) {
                if (pre_max_height < dp[j][i]) {
                    pre_max_height = dp[j][i];
                    k = j;
                }
            }
        }
        if (pre_max_height == -1) k = -1;
        dp[i][i] += height[area_weight[i][0]];
        if (k >= 0) {
            dp[i][i] += dp[k][i];
            track[i] = k;
        }
        if (weight_ans < dp[i][i]) {
            weight_ans = dp[i][i];
            track_start_idx = i;
        }
        for (int j = i+1; j<N; j++) dp[i][j] = dp[i][i];
    }
    back_tracking(track_start_idx);

    int block_cnt = tower.size();
    cout << block_cnt << "\n";
    for (int i=block_cnt-1; i>=0; i--) cout << tower[i] << "\n";

    return 0;
}