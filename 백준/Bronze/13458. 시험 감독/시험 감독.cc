#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
vector <int> a;
int b, c;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    cin >> b >> c;
    long long dab = 0;

    for (int i = 0; i < n; i++) {
        int ai = a[i];
        if (ai <= b) {
            dab++;
            continue;
        }
        dab++;
        ai -= b;
        if (ai <= c) {
            dab++;
            continue;
        }
        dab += (ai / c);
        if (ai % c != 0) dab++;
    }
    cout << dab;
}
