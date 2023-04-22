#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() { 
    int T;
    cin >> T;

    while (T--) {
        string s;
        cin >> s;
        vector <char> str;
        for (int i=0; i<s.length(); i++) {
            str.push_back(s[i]);
        }
        if (next_permutation(str.begin(), str.end())) {
            for (int i=0; i<s.length(); i++) {
                cout<<str[i];
            }
        } else {
            cout << s;
        }
        cout<<"\n";
    }
}
