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
        vector <string> v;
        for (int j=0; j<=n.length(); j++) {
            string tmp = n;
            v.push_back(tmp.insert(j, to_string(diff)));
        }
        sort(v.begin(), v.end());
        cout << "Case #" << i+1 << ": " << v[0] << "\n";
    }
}