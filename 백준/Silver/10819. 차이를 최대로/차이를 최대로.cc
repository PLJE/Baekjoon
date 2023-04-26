#include <iostream>
#include <deque>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>


using namespace std;

int N;
vector <int> num;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    int x;
    for (int i=0; i<N; i++) {
        cin >> x;
        num.push_back(x);
    }
    sort(num.begin(), num.end());
    int sum = 0;
    for (int i=1; i<N; i++) {
        sum += abs(num[i] - num[i-1]);
    }
    int ans = 0;
    ans = max(ans, sum);
    while (next_permutation(num.begin(), num.end())) {
        sum = 0;
        for (int i=1; i<N; i++) {
            sum += abs(num[i] - num[i-1]);
        }
        ans = max(ans, sum);
    }
    cout << ans;
} 