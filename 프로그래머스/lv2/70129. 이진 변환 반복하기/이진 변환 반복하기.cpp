#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int removed_zero_count;

string get_binary(int n) {
    string binary = "";
    int r; int c;
    while (1) {
        c = n / 2;
        if (c == 0) {
            binary = "1" + binary;
            break;
        }
        r = n % 2;
        binary = to_string(r) + binary;
        n /= 2;
    }
    return binary;
}
vector<int> solution(string s) {
    int cnt = 0;
    while (s != "1") {
        cnt++;
        int origin_len = s.length();
        int zero_cnt = 0;
        for (int i=0; i<origin_len; i++) {
            if (s[i] == '0') {
                zero_cnt++;
            }
        }
        removed_zero_count += zero_cnt;
        int n = origin_len - zero_cnt;
        s = get_binary(n); 
    }
    vector<int> answer = {cnt, removed_zero_count};
    return answer;
}