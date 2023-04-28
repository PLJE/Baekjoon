#include <iostream>
#include <string>
#include <queue>

using namespace std;

int num_chk[10001];
int target, order;

int get_clocknum(string s) {
    string tmp = s.substr(0,4);
    for (int i=1; i<=4; i++) {
        string next_tmp = s.substr(i, 4);
        if (tmp > next_tmp) {
            tmp = next_tmp;
        }
    }
    int to_num = stoi(tmp);
    return to_num;
}
void get_num (string tmp) {
    if (tmp.length() == 4) {
        int clocknum = get_clocknum(tmp+tmp);
        if (num_chk[clocknum] == 0) {
            num_chk[clocknum] = 1;
            order++;
            if (clocknum == target) {
                cout << order;
                return;
            }
        }
        return;
    }

    for (int i=1; i<=9; i++) {
        tmp.push_back(i+'0');
        get_num(tmp);
        tmp.pop_back();
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x;
    string num;
    for (int i=0; i<4; i++) {
        cin >> x;
        num.push_back(x+'0');
    }
    target = get_clocknum(num+num);
    get_num("");
    return 0;
}