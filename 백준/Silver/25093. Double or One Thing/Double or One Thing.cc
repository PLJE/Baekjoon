#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int T;

int main() {
    cin >> T;
    string s;
    for (int t=1; t<=T; t++) {
        cin >> s;
        vector <pair<char, int>> cnt;
        int len = s.length();
        int cur = 0;
        while (cur < len) {
            int next = cur + 1;
            while (next < len && s[cur] == s[next]) {
                next++;
            }
            cnt.push_back({s[cur], next - cur});
            cur = next;
        }
        len = cnt.size();
        string nstr = "";
        for (int i=0; i<len-1; i++) {
            int cnum = cnt[i].second;
            if (cnt[i].first < cnt[i+1].first) {
                cnum *= 2;
            }
            for (int j=0; j<cnum; j++) nstr.push_back(cnt[i].first);
        }
        for (int i=0; i<cnt[len-1].second; i++) {
            nstr.push_back(cnt[len-1].first);
        }
        cout << "Case #" << t << ": " << nstr <<"\n";
    }
} 