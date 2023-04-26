#include <iostream>
#include <deque>
#include <string>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>

using namespace std;

int N, d, k, c;
vector <int> sushi;
int cnt[3005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> d >> k >> c;
    int x;
    for (int i=0; i<N; i++) {
        cin >> x;
        sushi.push_back(x);
    }

    int kinds = 0;
    for (int i=0; i<k; i++) {
        cnt[sushi[i]]++;
        if (cnt[sushi[i]] == 1) kinds++;
    }
    cnt[c]++;
    if (cnt[c] == 1) kinds++;

    int ans = 0;
    ans = max(ans, kinds);

    for (int i=1; i<N; i++) {
        int left = i-1;
        int right = i + k - 1;
        if (right >= N) right %= N;

        cnt[sushi[right]]++;
        if (cnt[sushi[right]] == 1) kinds++;

        cnt[sushi[left]]--;
        if (cnt[sushi[left]] == 0) kinds--;

        ans = max(ans, kinds);
    }
    cout << ans;
    return 0;
}
