#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

int bingo[6][6];
int x;
map <int, pair<int,int>> xy;
vector <int> nums;

int chk_line() {
    int line = 0;
    int right_cnt = 0;
    int left_cnt = 0;
    for (int i=0; i<5; i++) {
        if (bingo[i][i] == 1) right_cnt++;
        if (bingo[i][4-i] == 1) left_cnt++;
        int row_cnt = 0;
        int col_cnt = 0;
        for (int j=0; j<5; j++) {
            if (bingo[i][j] == 1) row_cnt++;
            if (bingo[j][i] == 1) col_cnt++;
        }
        if (row_cnt == 5) line++;
        if (col_cnt == 5) line++;
    }
    if (left_cnt == 5) line++;
    if (right_cnt == 5) line++; 
    return line;
}
int main() { 
    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            cin >> x;
            xy[x] = {i,j};
        }
    }
    for (int i=1; i<=25; i++) {
        cin >> x;
        pair<int,int> ij = xy[x];
        bingo[ij.first][ij.second] = 1;
        int line = chk_line();
        if (line >= 3) {
            cout << i;
            break;
        }
    }
    return 0;
}
