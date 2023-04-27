#include <iostream>
#include <deque>
#include <string>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>

using namespace std;

int N;

bool comp (pair<int, string> a, pair<int, string> b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first < b.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    string s;
    vector <pair<int, string>> strs;
    for (int i=0; i<N; i++) {
        cin >> s;
        strs.push_back({s.length(), s});
    }
    sort(strs.begin(), strs.end(), comp);
    strs.erase(unique(strs.begin(), strs.end()), strs.end());
    for (int i=0; i<strs.size(); i++) {
        cout << strs[i].second << "\n";
    }
}
