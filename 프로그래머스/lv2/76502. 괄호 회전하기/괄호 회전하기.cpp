#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;

int get_dir(char c) {
    if (c == '(' || c =='{' || c=='[') return 1;
    return 2;
}
bool push_possible(char top, char c) {
    if (top == '(' && c == ')') return true;
    if (top == '[' && c == ']') return true;
    if (top == '{' && c == '}') return true;
    return false;
}
bool chk_possible(string s) {
    stack <char> st;
    int cnt = 0; 
    int slen = s.length();
    if (slen == 1 || slen % 2 == 1) return false;
    
    while (cnt != slen) {
        char cur = s[cnt];
        int dir = get_dir(cur);
        
        if (st.empty()) {
            if (dir == 1) {
                st.push(cur); 
                cnt++;
                continue;
            } else {
                return false;
            }
        }
        char top = st.top();
        if (dir == 1) {
            st.push(cur);
            cnt++;
            continue;
        } else if(dir == 2) {
            if (push_possible(top, cur)) {
                st.pop(); 
                cnt++;
            }
            else return false;
        }
    }
    return true;
}
string rotate(string s) {
    string tmp = s.substr(1, s.length());
    tmp.push_back(s[0]);
    return tmp;
}
int solution(string s) {
    int answer = 0;
    int slen = s.length();
    if (chk_possible(s)) answer++;
    for (int i=1; i<slen; i++) {
        string tmp = rotate(s);
        if (chk_possible(tmp)) answer++;
        s = tmp;
    }
    
    return answer;
}