#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <set>
#include<stack>

using namespace std;

long long N;
int T;

bool is_pal(string s) {
    string reversed = string(s.rbegin(), s.rend());
    if (s == reversed) return true;
    return false;
}

int main() {
    cin >> T;
    for (int t=1; t<=T; t++) {
        cin >> N;
        int cnt = 0;
        for (long long i=1; i*i <= N; i++) {
            if (N % i == 0) {
                if (is_pal(to_string(i))) cnt++;
                if (i != N / i && is_pal(to_string(N / i))) cnt++;
            }
        }
        cout << "Case #" << t << ": " << cnt << "\n";
    }
    return 0;
}