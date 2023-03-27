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
int cnt;
vector <int> ot = {1,2,3,4,5,6,7,8,9,11,22,33,44,55,66,77,88,99};

void get_pal(int inner, int outer, vector<int> v) {
    if (v.size() == inner) {
        // first type
        string s1 = to_string(outer);
        for (int i=0; i<v.size()-1; i++) {
            s1 += to_string(v[i]);
        }
        s1 += to_string(v[v.size()-1]);
        for (int i=v.size()-2; i>=0; i--) {
            s1 += to_string(v[i]);
        }
        s1 += to_string(outer);

        string s2 = to_string(outer);
        for (int i=0; i<v.size(); i++) {
            s2 += to_string(v[i]);
        }
        for (int i = v.size()-1; i>=0; i--) {
            s2 += to_string(v[i]);
        }
        s2 += to_string(outer);
        if (N % stoll(s1) == 0) cnt++;
        if (N % stoll(s2) == 0) cnt++;
        return;
    }
    for (int i=0; i<=9; i++) {
        v.push_back(i);
        get_pal(inner, outer, v);
        v.pop_back();
    }
    return;
}

int main() {
    cin >> T;
    for (int t=1; t<=T; t++) {
        cin >> N;
        int num = to_string(N).length();
        cnt = 0;
        for (int i=0; i<ot.size(); i++) {
            if (ot[i] > N) break;
            if (N % ot[i] == 0) cnt++;
        }
        if (num <= 2) {
            cout << "Case #" << t << ": " << cnt << "\n";
            continue;
        }
        for (int i = 1; i <= 4; i++) {
            if (num < i * 2 + 1) break;
            for (int o = 1; o <= 9; o++) {
                vector <int> v;
                get_pal(i, o, v);
            }
        }
        cout << "Case #" << t << ": " << cnt << "\n";
    }
    return 0;
}