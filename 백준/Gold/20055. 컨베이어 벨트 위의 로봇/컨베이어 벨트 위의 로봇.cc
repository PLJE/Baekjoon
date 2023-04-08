#include <iostream>
#include <climits>
#include <string>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

vector <pair<int,int>> belt;
int N, K, zero_cnt;

vector<pair<int,int>> rotate() {
    vector <pair<int,int>> v;
    v.push_back(belt[2*N-1]);
    for (int i=0; i<2*N-1; i++) {
        v.push_back(belt[i]);
    }
    return v;
}
void move_robot() {
    for (int i=N-2; i>=0; i--) {
        if (belt[i].second == 1) {
            if (belt[i+1].first >= 1 && belt[i+1].second == -1) {
                belt[i+1].second = 1;
                belt[i+1].first--;
                if (belt[i+1].first == 0) zero_cnt++;
                belt[i].second = -1;
            }
        }
    }
}
int main() {
    cin >> N >> K;
    int x;
    for (int i=0; i<2*N; i++) {
        cin >> x;
        belt.push_back({x, -1}); // -1 : 로봇 없음, 1 : 있음
    }
    int phase = 1;
    while (1) {
        // 벨트 회전
        belt = rotate();
        // N번째에 로봇이 있다면 내려
        if (belt[N-1].second != -1) {
            belt[N-1].second = -1;
        }
        // 이동 가능한 로봇 있으면 이동함
        move_robot();
        if (belt[N-1].second != -1) {
            belt[N-1].second = -1;
        }
        // 0번째 내구도 1이상이면 로봇 올림
        if (belt[0].first >= 1 && belt[0].second == -1) {
            belt[0].second = 1;
            belt[0].first--;
            if (belt[0].first == 0) zero_cnt++;
        }
        // 0인거 k개 이상이면 과정 종료
        if (zero_cnt >= K) break;
        phase++;
    }
    cout << phase;
}