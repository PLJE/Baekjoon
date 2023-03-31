#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int zero_one[2];
int board[1025][1025];

pair<int, int> chk_possible(int sx, int sy, int ex, int ey) {
    int first = board[sx][sy];
    for (int i=sx; i<=ex; i++) {
        for (int j=sy; j<=ey; j++) {
            if (board[i][j] != first) return {0, -1};
        }
    }
    return {1, first};
}

void call_lower(int sx, int sy, int ex, int ey) {
    if (sx == ex) {
        if (board[sx][sy] == 0) zero_one[0]++;
        else zero_one[1]++;
        return;
    }
    pair <int, int> chk = chk_possible(sx, sy, ex, ey);
    if (chk.first) {
        zero_one[chk.second]++;
        return;
    } else {
        int hlen = (ex - sx + 1) / 2;
        call_lower(sx, sy, sx + hlen - 1, sy + hlen -1);
        call_lower(sx, sy + hlen, sx + hlen - 1, ey);
        call_lower(sx + hlen, sy, ex, sy + hlen - 1);
        call_lower(sx + hlen, sy + hlen, ex, ey);
    }
    return;
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    int len = arr.size();
    for (int i=0; i<len; i++) {
        for (int j=-0; j<len; j++) {
            board[i][j] = arr[i][j];
        }
    }
    call_lower(0 ,0, len-1, len-1);
    answer.push_back(zero_one[0]);
    answer.push_back(zero_one[1]);
    return answer;
}