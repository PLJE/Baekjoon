#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

vector <int> temperature;
int N, K;

int main() {
    cin >> N >> K;
    int x;
    for (int i = 0; i < N; i++) {
        cin >> x;
        temperature.push_back(x);
    }
    int left = 0;
    int right = K - 1;
    int cur_sum = 0;

    for (int i = 0; i < K; i++) {
        cur_sum += temperature[i];
    }

    int ans = cur_sum;
    
    while (1) {
        if (right == N-1) break;

        cur_sum -= temperature[left];
        cur_sum += temperature[right + 1];
        left++;
        right++;

        ans = max(ans, cur_sum);
    }
    
    cout << ans;
}
