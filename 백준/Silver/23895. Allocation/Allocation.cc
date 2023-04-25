#include <iostream>
#include <climits>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

int T, N, B;

int main() { 
    cin >> T;
    for (int t=1; t<=T; t++) {
        cin >> N >> B;
        vector <int> price;
        for (int i=0; i<N; i++) {
            int x; 
            cin >> x;
            price.push_back(x);
        }
        sort(price.begin(), price.end());
        int ans = 0;
        for (int i=0; i<N; i++) {
            if (B < price[i]) break;
            ans++;
            B -= price[i];
        }
        cout << "Case #" <<t << ": " << ans << "\n"; 
    }
}
