#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    int x;
    int sum = 0;
    vector <int> tree;
    for (int i=0; i<N; i++) {
        cin >> x;
        tree.push_back(x);
        sum += x;
    }
    if (sum % 3 != 0) {
        cout << "NO";        
    } else {
        int cnt = 0;
        for (int i=0; i<N; i++) {
            cnt += (tree[i] / 2);
        }
        if (cnt >= sum / 3) cout << "YES";
        else cout << "NO";
    }
}
