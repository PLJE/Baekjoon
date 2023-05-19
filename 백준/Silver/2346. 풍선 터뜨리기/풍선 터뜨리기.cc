#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

vector <pair<int,int>> balloons;
int bomb[1001];
int N;

int left (int x) {
    if (x == 0) return N-1;
    else return x-1;
}
int move(int start, int offset) {
    if (offset >= 0) { // right
        for (int cnt = 0; cnt != offset; ++start) {
            if (bomb[start % N] == 0) {
                cnt++;
            }
        }
        return (start - 1) % N;
    } else { // left
        for (int cnt = 0;
            cnt != -offset; 
            start = left(start)) 
        {
            if (bomb[start] == 0) {
                cnt++;
            }
        }
        return (start + 1) % N;
    }
}
int main() {
    cin >> N;
    int x;
    for (int i=0; i<N; i++) {
        cin >> x;
        balloons.push_back({i, x}); // ballon_num , offset
    }
    int bomb_cnt = 1;

    int cur = 0;
    int offset = balloons[0].second;
    bomb[0] = 1;
    cout << 1 << " ";

    while (1) {
        if (bomb_cnt == N) break;

        int next_idx = move(cur, offset);

        bomb[next_idx] = 1;

        cur = next_idx;
        offset = balloons[next_idx].second;

        cout << balloons[next_idx].first + 1 << " ";

        bomb_cnt++;
    }
    return 0;
}
