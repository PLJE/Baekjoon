#include <iostream>
#include <cstring>
#include <set>
#include <algorithm>
#include <string>
#include <climits>
#include <vector>
#include <queue>

using namespace std;

int N;
int visit[1001][1001];

int main() {
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    int x;
    int odd_cnt = 0;
    int even_cnt = 0;
    for (int i=0; i<N; i++) {
        cin >> x;
        if (x % 2 == 0) {
            even_cnt++;
        } else {
            odd_cnt++;
        }
    }
    if (even_cnt == odd_cnt || even_cnt == odd_cnt + 1) {
        cout << N;
        return 0;
    }
    if (even_cnt > odd_cnt) {
        cout << 2 * odd_cnt + 1;
    } else {
        while (odd_cnt > even_cnt) {
            odd_cnt -= 2;
            even_cnt += 1;
        }
        if (odd_cnt == even_cnt) {
            cout << odd_cnt + even_cnt;
        } else {
            cout << 2 * odd_cnt + 1;
        }
    }
    return 0;
}