#include <iostream>
#include <stack>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector <int> num;
map <int, int> cnt;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    int x;
    for (int i=1; i<=N; i++) {
        cin >> x;
        num.push_back(x);
    }
    stack <pair<int,int>> st;
    st.push({num[N-1], N-1});

    for (int i=N-2; i>=0; i--) {
        int cur = num[i];
        if (st.empty()) st.push({cur, i});
        else {
            int top_val = st.top().first;
            int top_idx = st.top().second;
            if (cur <= top_val) st.push({cur, i});
            else {
                while (!st.empty()) {
                    int tmp_val = st.top().first;
                    int tmp_idx = st.top().second;
                    if (cur <= tmp_val) break;
                    st.pop();
                    cnt[i] += (cnt[tmp_idx] + 1);
                }
                st.push({cur, i});
            }
        }
    }
    long long ans = 0;
    for (int i=0; i<N; i++) {
        ans += cnt[i];
    }
    cout << ans;
}