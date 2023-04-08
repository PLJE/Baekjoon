#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int T;

int main() {
    cin >> T;
    for (int t=1; t<=T; t++) {
        vector <int> first;
        vector <int> second;
        vector <int> third;
        int x;
        for (int i=0; i<4; i++) {
            cin >> x;
            first.push_back(x);
        }
        for (int i=0; i<4; i++) {
            cin >> x;
            second.push_back(x);
        }
        for (int i=0; i<4; i++) {
            cin >> x;
            third.push_back(x);
        }
        vector <int> min_val;
        int total = 0;
        for (int i=0; i<4; i++) {
            int m = min({first[i], second[i], third[i]});
            total += m;
            min_val.push_back(m);
        }
        if (total < 1000000) {
            cout << "Case #" << t << ": IMPOSSIBLE\n";
        } else if (total == 1000000) {
            cout << "Case #" << t << ": ";
            for (int i=0; i<4; i++) cout << min_val[i] << " ";
            cout << "\n";
        } else {
            int diff = total - 1000000;
            for (int i=0; i<4; i++) {
                if (min_val[i] >= diff) {
                    min_val[i] -= diff;
                    break;
                } else {
                    diff -= min_val[i];
                    min_val[i] = 0;
                }
            }
            cout << "Case #" << t << ": ";
            for (int i=0; i<4; i++) {
                cout << min_val[i] << " ";
            }
            cout << "\n";
        }
    }
} 