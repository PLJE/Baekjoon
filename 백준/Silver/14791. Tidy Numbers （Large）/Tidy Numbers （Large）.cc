#include <iostream>
#include <deque>
#include <string>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#include <climits>
#include <set>
#include <vector>

using namespace std;

int T;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    long long x;
    for (int t=1; t<=T; t++) {
        cin >> x;
        string str = to_string(x);
        int len = str.length();
        for (int i=len-1; i>0; i--) {
            int left = str[i-1]-'0';
            int right = str[i]-'0';
            if (left <= right) continue;
            str[i-1] = (left-1) + '0';
            for (int k=i; k<len; k++) {
                str[k] = '9';
            }
        }
        cout << "Case #" << t << ": " << stoull(str) << "\n";
    }
}
