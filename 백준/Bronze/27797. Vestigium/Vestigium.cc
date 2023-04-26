#include <iostream>
#include <deque>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#include <climits>
#include <set>
#include <vector>

using namespace std;

int T, N;
int arr[105][105];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for (int t=0; t<T; t++) {
        cin >> N;
        int trace = 0;
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                cin >> arr[i][j];
                if (i==j) trace += arr[i][j];
            }
        }
        int row = 0;
        int col = 0;
        for (int i=0; i<N; i++) {
            set <int> r;
            set <int> c;
            for (int j=0; j<N; j++) {
                r.insert(arr[i][j]);
                c.insert(arr[j][i]);
            }
            if (r.size() < N) row++;
            if (c.size() < N) col++;
        }
        cout << "Case #" << t+1 << ": " << trace << " " << row << " " << col << "\n";
    }
}
