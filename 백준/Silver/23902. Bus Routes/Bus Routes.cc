#include <iostream>
#include <climits>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

int T, N, day;

int main() { 
    cin >> T;
    for (int t=1; t<=T; t++) {
        cin >> N >> day;
        vector <int> bus;
        for (int i=0; i<N; i++) {
            int x;
            cin >> x;
            bus.push_back(x);
        }
        for (int i=N-1; i>=0; i--) {
            int r = day % bus[i];
            day -= r;
        }
        cout << "Case #" <<t << ": " << day << "\n"; 
    }
}
