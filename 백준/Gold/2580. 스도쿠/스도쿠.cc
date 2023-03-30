#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int arr[10][10];
int chk[10];
vector <pair<int,int>> zero;

int get_start(int x) {
    if (x>=1 && x<=3) return 1;
    else if(x>=4 && x<=6) return 4;
    else return 7;
}
vector<int> get_num(int x, int y) {
    memset(chk, 0, sizeof(chk));
    // row
    for (int i=1; i<=9; i++) {
        chk[arr[x][i]] = 1;
    }
    // col
    for (int i=1; i<=9; i++) {
        chk[arr[i][y]] = 1;
    }
    // square
    int sx = get_start(x);
    int sy = get_start(y);
    for (int i=sx; i<sx+3; i++) {
        for (int j=sy; j<sy+3; j++) {
            chk[arr[i][j]] = 1;
        }
    }
    vector <int> v;
    for (int i=1; i<=9; i++) {
        if (chk[i] == 0) v.push_back(i);
    }
    return v;
}
int chk_hab(int x, int y, int val) {
    // row
    int hab = val;
    for (int i=1; i<=9; i++) {
        hab += arr[x][i];
    }
    if (hab > 55) return 0;
    // col
    hab = val;
    for (int i=1; i<=9; i++) {
        hab += arr[i][y];
    }
    if (hab > 55) return 0;
    // square
    hab = val;
    int sx = get_start(x);
    int sy = get_start(y);
    for (int i=sx; i<sx+3; i++) {
        for (int j=sy; j<sy+3; j++) {
            hab += arr[i][j];
        }
    }
    if (hab > 55) return 0;
    return 1;
}
void setnum(int cnt) {
    if (cnt == zero.size()) {
            for (int i=1; i<=9; i++) {
                for (int j=1; j<=9; j++) {
                cout << arr[i][j] << " ";
            }
            cout << "\n";
        }
        exit(0);
    }
    int x = zero[cnt].first;
    int y = zero[cnt].second;
    vector <int> v = get_num(x, y);
    int len = v.size();
    for (int i=0; i<len; i++) {
        if (chk_hab(x, y, v[i])) {
            arr[x][y] = v[i];
            setnum(cnt+1);
            arr[x][y] = 0;
        }
    }
    return;
}

int main() {
    for (int i=1; i<=9; i++) {
        for (int j=1; j<=9; j++) {
            cin >> arr[i][j];
            if (!arr[i][j]) zero.push_back({i, j});
        }
    }
    int zero_cnt = zero.size();
    for (int i=0; i<zero_cnt; i++) {
        setnum(0);
    }
    return 0;
}