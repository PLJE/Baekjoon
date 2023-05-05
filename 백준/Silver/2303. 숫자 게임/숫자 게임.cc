#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int num[6];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector <vector<int>> v;
    vector <int> per;
    for (int i=0; i<3; i++) per.push_back(1);
    for (int i=0; i<2; i++) per.push_back(0);
    sort(per.begin(), per.end());

    do {
        v.push_back(per);
    } while (next_permutation(per.begin(), per.end()));

    cin >> N;
    int ans_val = 0;
    int ans = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<5; j++) {
            cin >> num[j];
        }
        int max_val = 0;
        for (int j=0; j<v.size(); j++) {
            int tmp = 0;
            for (int k=0; k<5; k++) {
                if (v[j][k] == 1) {
                    tmp += num[k];
                }
            }
            max_val = max(max_val, tmp % 10);
        }
        if (ans_val <= max_val) {
            ans_val = max_val;
            ans = i+1;
        }
    }
    cout << ans;
}