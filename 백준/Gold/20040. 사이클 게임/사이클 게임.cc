#include <iostream>
#include <deque>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>

using namespace std;

int N, M;
int parent[500001];

int find_parent(int a) {
    if (parent[a] == a) return a;
    return parent[a] = find_parent(parent[a]);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i=0; i<N; i++) {
        parent[i] = i;
    }
    int x, y;
    for (int i=0; i<M; i++) {
        cin >> x >> y;
        int px = find_parent(x);
        int py = find_parent(y);
        if (px == py) {
            cout << i+1;
            return 0;
        }
        parent[px] = py;
    }
    cout << 0;
    return 0;
}
