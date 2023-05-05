#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int arr[6];
int num[6];
vector <vector<int>> v;

void comb(int idx, int x) {
    if (idx == 3) {
        vector <int> tmp;
        for (int i=0; i<3; i++) {
            tmp.push_back(arr[i]);
        }
        v.push_back(tmp);
        return;
    }
    for (int i=x; i<5; i++) {
        arr[idx] = i;
        comb(idx+1, i+1);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    int ans = 0;
    int max_val = 0;
    comb(0,0);
    for (int i=0; i<N; i++) {
        for (int j=0; j<5; j++) {
            cin >> num[j];
        }
        for (int j=0; j<v.size(); j++) {
            int sum = 0;
            for (int k=0; k<3; k++) {
                sum += num[v[j][k]];
            }
            if (max_val <= sum % 10) {
                max_val = sum % 10;
                ans = i + 1;
            }
        }
    }
    cout << ans;
}