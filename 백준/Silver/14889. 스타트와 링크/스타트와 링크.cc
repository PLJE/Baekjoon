#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

int n;
int s[21][21];
int comb[21];
int team[21];
int diff_min = INT_MAX;

void cal(int half) {
    int left = 0;
    memset(team, 0, sizeof(team));
    for (int i=1; i<=half; i++) {
        team[comb[i]] = 1;
        for (int j=1; j<=half; j++) {
            left += s[comb[i]][comb[j]];
        }
    }
    vector <int> left_team;
    for (int i=1; i<=n; i++) {
        if (team[i] == 1) continue;
        left_team.push_back(i);
    }
    int right = 0;
    for (int i=0; i<left_team.size(); i++) {
        for (int j = 0; j < left_team.size(); j++) {
            right +=  s[left_team[i]][left_team[j]];
        }
    }
    int diff = left <= right ? right - left : left - right;
    diff_min = min(diff_min, diff);
}
void combination(int idx, int num, int half) {
    if (idx == half + 1) {
        cal(half);
        return;
    }
    for (int i=num; i<=n; i++) {
        comb[idx] = i;
        combination(idx+1, i+1, half);
    }
    return;
}

int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> s[i][j];
        }
    }
    combination(1, 1, n/2);
    cout << diff_min;
}
