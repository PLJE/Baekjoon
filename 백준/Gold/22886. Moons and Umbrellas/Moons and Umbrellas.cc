#include <iostream>
#include <climits>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

int T, ans, X,Y;
char str[1001];
char chars[2] = {'C','J'};

int get_cost(string str){
    int len = str.length();
    int co = 0;
    for (int i=0; i<len-1; i++) {
        if (str[i] == 'C' && str[i+1]=='J') co += X;
        else if (str[i] == 'J' && str[i+1]=='C') co += Y;
    }
    return co;
}
void dfs(int idx, int len, string mu) {
    if (idx == len) {
        int cur  = 0;
        string nstr = "";
        for (int i=0; i<mu.length(); i++) {
            if (mu[i] == '?') {
                nstr.push_back(str[cur++]);
            } else {
                nstr.push_back(mu[i]);
            }
        }
        ans = min(ans, get_cost(nstr));
        return;
    }
    for (int i=0; i<2; i++) {
        str[idx] = chars[i];
        dfs(idx+1, len, mu);
    }
}
int main() {
    cin >> T;
    for (int t=1; t<=T; t++) {
        string mu;
        cin >> X >> Y >> mu;
        int cnt = 0;
        for (int i=0; i<mu.length(); i++) {
            if (mu[i] == '?') {
                cnt++;
            }
        }
        ans = INT_MAX;
        dfs(0, cnt, mu);
        cout << "Case #" << t << ": " << ans << "\n";
    }
} 