#include <iostream>
#include <climits>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int N;
int arr[401][401];
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
set<int> like[401];

bool range(int x, int y) { // range check
    if (x>=1 && y>=1 && x<=N && y<=N) return true;
    return false;
}
bool comp(vector<int> a, vector<int> b) { // custom sort
    if (a[0] == b[0]) {
        if (a[1] == b[1]) {
            if (a[2] == b[2]) {
                return a[3] < b[3];
            }
            return a[2] < b[2];
        }
        return a[1] > b[1];
    }
    return a[0] > b[0];
}
vector<vector<int>> chk_board(int cur) {
    set <int> friends = like[cur];
    vector <vector<int>> res;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            int like_cnt = 0;
            int empty_cnt = 0;
            for (int k=0; k<4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (range(nx, ny)) {
                    if (friends.find(arr[nx][ny]) != friends.end()) {
                        like_cnt++;
                    }
                    if (arr[nx][ny] == 0) {
                        empty_cnt++;
                    }
                }
            }
            if (arr[i][j] == 0)
                res.push_back({like_cnt, empty_cnt, i, j});
        }
    }
    sort(res.begin(), res.end(), comp);
    return res;
}
int get_score(int i, int j) {
    set <int> friends = like[arr[i][j]];
    int cnt = 0;
    for (int k=0; k<4; k++) {
        int nx = i + dx[k];
        int ny = j + dy[k];
        if (range(nx, ny)) {
            if (friends.find(arr[nx][ny]) != friends.end()) {
                cnt++;
            }
        }
    }
    if (cnt == 0) return 0;
    else if (cnt == 1) return 1;
    else if (cnt == 2) return 10;
    else if (cnt == 3) return 100;
    return 1000;
}
int main() {
    cin >> N;
    int len = N*N;
    int a, b, c, d, e;
    vector <int> order;
    for (int i=1; i<=len; i++) {
        cin >> a >> b >> c >> d >> e;
        order.push_back(a);
        like[a] = {b,c,d,e};
    }
    for (int i=0; i<len; i++) {
        int cur_student = order[i];
        vector<vector<int>> res = chk_board(cur_student);
        arr[res[0][2]][res[0][3]] = cur_student;
    }
    int ans = 0;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            ans += get_score(i, j);
        }
    }
    cout << ans;  
} 