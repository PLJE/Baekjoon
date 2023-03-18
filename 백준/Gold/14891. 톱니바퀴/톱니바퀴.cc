#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

int tob[5][9];
int tmp[9];
int k;
const int TOB_CNT = 4;
const int TOB_DETAIL = 8;

int getEquality(int a, int b) { // a < b
    return tob[a][3] == tob[b][7];
}
void rotate(int idx, int dir) {
    if (dir == 1) { // clock
        for (int i=1; i<=TOB_DETAIL-1; i++) {
            tmp[i+1] = tob[idx][i];
        }
        tmp[1] = tob[idx][8];
    } else if (dir == -1) { // counter clock
        for (int i=2; i<=TOB_DETAIL; i++) {
            tmp[i-1] = tob[idx][i];
        }
        tmp[8] = tob[idx][1];
    }
    for (int i=1; i<=TOB_DETAIL; i++) {
        tob[idx][i] = tmp[i];
    }
}
int getScore() {
    int score = 0;
    for (int i=1; i<=TOB_CNT; i++) {
        if (tob[i][1] == 0) continue;
        if (i==1) score += 1;
        else if (i==2) score += 2;
        else if (i==3) score += 4;
        else score += 8;
    }
    return score;
}
int main()
{
    for (int i=0; i<TOB_CNT; i++) {
        string s;
        cin >> s;
        for (int j=0; j<TOB_DETAIL; j++) {
            tob[i+1][j+1] = s[j] - '0';
        }
    }
    cin >> k;
    for (int i=0; i<k; i++) {
        int idx, dir;
        cin >> idx >> dir;
        vector <pair<int,int>> move;
        move.push_back({idx, dir});
        int ndir = dir;
        for (int j=idx-1; j>=1; j--) {
            if (getEquality(j, j+1)) break;
            ndir = -ndir;
            move.push_back({j, ndir});
        }
        ndir = dir;
        for (int j=idx+1; j<=TOB_CNT; j++) {
            if (getEquality(j - 1, j)) break;
            ndir = -ndir;
            move.push_back({j, ndir});
        }
        for (int j=0; j<move.size(); j++) {
            rotate(move[j].first, move[j].second);
        }
    }
    cout << getScore();
}
