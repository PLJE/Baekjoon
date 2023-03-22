#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <stdlib.h>
#include <map>

using namespace std;

int N;
string s;

int main()
{
    cin >> N >> s;
    int left = 0;
    int right = 0;

    map <char, int> m;
    m[s[0]] = 1;

    int ans = 1;
    while (1) {
        if (right + 1 == s.length()) break;
        if (m.find(s[right+1]) == m.end()) {
            m[s[right+1]] = 1;
        } else {
            m[s[right+1]]++;
        }

        right++;
        if (m.size() <= N) {
            ans = max(ans, right-left+1);
        } else {
            while (m.size() > N) {
                m[s[left]]--;
                if (m[s[left]] == 0) {
                    m.erase(s[left]);
                }
                left++;
            }
            ans = max(ans, right-left+1);
        }
    }
    cout << ans;
}
