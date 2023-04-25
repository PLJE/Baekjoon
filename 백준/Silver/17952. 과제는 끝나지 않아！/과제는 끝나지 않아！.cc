#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int N;
int ans;
vector<int> work[1000001];
int work_exist[1000001];

int main() {
    cin >> N;
    int exist, score, t;
    for (int i=1; i<=N; i++) {
        cin >> exist;
        if (exist == 0) continue;
        cin >> score >> t;
        work_exist[i] = 1;
        work[i] = {t, score};
    }
    int current_work_time = -1;
    int current_work_score = -1;
    stack <pair<int,int>> st;

    for (int t=1; t<=N; t++) {
        if (work_exist[t]) { // 현재 시간에 과제가 주어짐
            if (current_work_time == -1) { // 하던 과제 없음
                current_work_time = work[t][0];
                current_work_score = work[t][1];
                current_work_time--;
                if (current_work_time == 0) {
                    ans += current_work_score;
                    current_work_time = -1;
                }
            } else { // 하던 과제 있음
                st.push({current_work_time, current_work_score});
                current_work_time = work[t][0];
                current_work_score = work[t][1];
                current_work_time--;
                if (current_work_time == 0) {
                    ans += current_work_score;
                    current_work_time = -1;
                }
            }
        } else {
            if (current_work_time != -1) { // 현재 추가 과제 없고, 하던거있음
                current_work_time--;
                if (current_work_time == 0) {
                    ans += current_work_score;
                    current_work_time = -1;
                }
            } else { // 추가 과제 없고, 하던것도 없음
                if (st.size() > 0) {
                    current_work_time = st.top().first;
                    current_work_score = st.top().second;
                    current_work_time--;
                    if (current_work_time == 0) {
                        ans += current_work_score;
                        current_work_time = -1;
                        st.pop();
                    }
                }
            }
        }
    }
    cout << ans;
}