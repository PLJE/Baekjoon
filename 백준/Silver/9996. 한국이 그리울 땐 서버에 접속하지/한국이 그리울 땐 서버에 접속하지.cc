#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <climits>

using namespace std;
int N;
string pat;
string ls, rs;

int main() {
    cin >> N;
    cin >> pat;
    for (int i=0; i<pat.length(); i++) {
        if (pat[i] == '*') {
            ls = pat.substr(0, i);
            rs = pat.substr(i+1, pat.length());
            break;
        }
    }
    string s;
    for (int n=1; n<=N; n++) {
        cin >> s;
        if (s.length() < ls.length() + rs.length()) {
            cout << "NE\n";
            continue;
        }
        string left = s.substr(0, ls.length());
        string right = string(s.rbegin(), s.rend()).substr(0, rs.length());
        right = string(right.rbegin(), right.rend());
        if (left == ls && right == rs) {
            cout << "DA\n";
        } else {
            cout << "NE\n";
        }
    }
}