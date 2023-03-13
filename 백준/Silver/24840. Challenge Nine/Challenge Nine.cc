#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    string n;
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> n;
        int total = 0;
        for (int s=0; s<n.length(); s++) {
            total += (n[s] - '0');
        }
        if (total % 9 == 0) {
            cout << "Case #" << i + 1 << ": " << n[0] << "0";
            for (int j=1; j<n.length(); j++) {
                cout << n[j];
            }
            cout << "\n";
            continue;
        }
        int next_nine = total;
        while (next_nine % 9 != 0) {
            next_nine++;
        }
        int diff = next_nine - total;
        if (diff < n[0] - '0') {
            cout << "Case #" << i + 1 << ": " << diff << n << "\n";
            continue;
        } else {
            int idx = 0;
            while (idx < n.length()) {
                if (n[idx] - '0' > diff) {
                    cout << "Case #" << i + 1 << ": " << n.insert(idx, to_string(diff)) << "\n";
                    break;
                }
                idx++;
            }
            if (idx == n.length()) {
                cout << "Case #" << i + 1 << ": " << n << diff << "\n";
            }
        }
    }
}
