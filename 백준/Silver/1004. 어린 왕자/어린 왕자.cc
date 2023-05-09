#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int T, N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for (int t=0; t<T; t++) {
        int sx, sy, ex, ey;
        int x, y, r;
        cin >> sx >> sy >> ex >> ey;
        cin >> N;
        int ans = 0;
        for (int n=0; n<N; n++) {
            cin >> x >> y >> r;
            int dist1 = sqrt((x-sx)*(x-sx) + (y-sy)*(y-sy));
            int dist2 = sqrt((x-ex)*(x-ex) + (y-ey)*(y-ey));
            int cnt = 0;
            if (dist1 < r) cnt++;
            if (dist2 < r) cnt++;
            if (cnt == 1) ans++;
        }
        cout << ans << "\n";
    }
}