#include <string>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

char arr[31][31];
int bomb[31][31];

void parse(int m, int n, vector <string> board) {
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            arr[i][j] = board[i][j];   
        }
    }
}
int bomb_block(int m, int n) {
    int bomb_cnt = 0;
    for (int i=0; i<=m-2; i++) {
        for (int j=0; j<=n-2; j++) {
            char a = arr[i][j];
            if (a == 'b') continue;
            char b = arr[i+1][j];
            char c = arr[i][j+1];
            char d = arr[i+1][j+1];
            if (a == b && b == c && a == d && b == c && b == d && c == d) {
                if (bomb[i][j] == 0) {
                    bomb_cnt++;
                    bomb[i][j] = 1;
                }
                if (bomb[i+1][j] == 0) {
                    bomb_cnt++;
                    bomb[i+1][j] = 1;
                }
                if (bomb[i][j+1] == 0) {
                    bomb_cnt++;
                    bomb[i][j+1] = 1;
                }
                if (bomb[i+1][j+1] == 0) {
                    bomb_cnt++;
                    bomb[i+1][j+1] = 1;
                }
            }
        }
    }
    return bomb_cnt;
}
void make_empty(int m, int n) {
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            if (bomb[i][j] == 1) arr[i][j] = 'b';   
        }
    }
}
void gravity(int m, int n) {
    for (int j=0; j<n; j++) {
        for (int i=m-1; i>=0; i--) {
            if (arr[i][j] == 'b') {
                int k = i-1;
                while (k >= 0) {
                    if (arr[k][j] != 'b') {
                        arr[i][j] = arr[k][j];
                        arr[k][j] = 'b';
                        break;
                    }
                    k--;
                }
            }
        }
    }
}
int solution(int m, int n, vector<string> board) {
    int answer = 0;
    parse(m, n, board);
    while(1) {
        memset(bomb, 0, sizeof(bomb));
        int bomb_cnt = bomb_block(m,n);
        answer += bomb_cnt;
        make_empty(m,n);
        gravity(m, n);
        if (bomb_cnt == 0) break;
    }
    return answer;
}