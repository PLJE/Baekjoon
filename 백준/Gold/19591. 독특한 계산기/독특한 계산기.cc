#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string s;
deque <long long> num;
deque <char> cal;

bool is_cal(char c) {
    if (c=='*' || c=='/' || c=='-' || c=='+') return true;
    return false;
}
int priority(char c) {
    if (c=='*' || c=='/') return 1;
    else return 2;
}
long long calculate (char c, long long n1, long long n2) {
    if (c=='+') return n1 + n2;
    if (c=='-') return n1 - n2;
    if (c=='/') return n1 / n2;
    else return n1 * n2;
}
int main() {
    cin >> s;

    int start_idx = 0;
    if (s[0] == '-') start_idx = 1;

    string tmp = "";
    for (int i=start_idx; i<s.length(); i++) {
        if (is_cal(s[i])) {
            cal.push_back(s[i]);
            if (tmp.length() != 0) {
                long long to_num = stoll(tmp);
                num.push_back(to_num);
            }
            tmp = "";
        } else {
            tmp.push_back(s[i]);
        }
    }
    num.push_back(stoll(tmp));
    if (s[0] == '-') {
        long long first_num = num.front();
        num.pop_front();
        num.push_front(-1 * first_num);
    }

    if (num.size() == 1) {
        cout << num.front();
        return 0;
    }

    while (!num.empty()) {
        int num_size = num.size();
        if (num_size == 2) {
            cout << calculate(cal.front(), num.front(), num.back());
            break;
        }
        long long a = num.front();
        long long d = num.back();
        num.pop_front();
        num.pop_back();
        long long b, c;
        if (num_size == 3) {
            b = num.front();
            c = num.front();

            num.pop_front();
        } else {
            b = num.front();
            c = num.back();

            num.pop_front();
            num.pop_back();
        }

        int front_cal_prio = priority(cal.front());
        int back_cal_prio = priority(cal.back());

        long long front_res = calculate(cal.front(), a, b);
        long long back_res = calculate(cal.back(), c, d);

        bool cal_front = false;
        if (front_cal_prio < back_cal_prio) cal_front = true;
        if (front_cal_prio == back_cal_prio) {
            if (front_res >= back_res) cal_front= true;
        }
        if (cal_front) { // 앞에거 계산
            if (num_size != 3) num.push_back(c);
            num.push_back(d);
            num.push_front(front_res);
            cal.pop_front();
        } else {
            if (num_size != 3) num.push_front(b);
            num.push_front(a);
            num.push_back(back_res);
            cal.pop_back();
        }
    }
}