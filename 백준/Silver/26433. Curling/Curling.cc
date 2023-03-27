#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int T, Rs, Rh, N, M, x, y;

double distance(int x, int y) {
    return sqrt(x*x + y*y);
}

int main() {
    cin >> T;
    for (int t=1; t<=T; t++) {
        cin >> Rs >> Rh;
        cin >> N;
        vector <pair<double,int>> dist;
        for (int n=1; n<=N; n++) {
            cin >> x >> y;
            double dis = distance(x,y);
            if (dis <= double(Rs) + Rh)
                dist.push_back({dis, 0});
        }
        cin >> M;
        for (int m=1; m<=M; m++) {
            cin >> x >> y;
            double dis = distance(x,y);
            if (dis <= double(Rs) + Rh)
                dist.push_back({dis, 1});
        }
        sort(dist.begin(), dist.end());
        int len = dist.size();
        int sc_r = 0; int sc_y = 0;
        if (len > 0) {
            if (dist[0].second == 0) sc_r++;
            else sc_y++;
        }
        for (int i=1; i<len; i++) {
            bool get_sc = true;
            int opp_col = 1 - dist[i].second;
            for (int j=0; j<i; j++) {
                if (dist[j].second == opp_col) {
                    get_sc = false;
                    break;
                }
            }
            if (get_sc) {
                if (dist[i].second == 0) sc_r++;
                else sc_y++;
            }
        }
        cout << "Case #" << t << ": " << sc_r << " " << sc_y << "\n";
    }
    return 0;
}