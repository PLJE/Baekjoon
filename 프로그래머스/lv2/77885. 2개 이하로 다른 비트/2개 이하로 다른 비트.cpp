#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;
string binary(long long n) {
    string bin = "";
    if (n == 0) return "0";
    if (n == 1) return "1";
    while (1) {
        int r = n % 2;
        bin = to_string(r) + bin;
        int c = n / 2;
        if (c == 1) {
            bin = "1" + bin;
            break;
        }
        n /= 2;
    }
    return bin;
}
string get_max(string s) {
    int len = s.length();
    for (int i=len-1; i>=0 ;i--) {
        if (s[i] == '0') {
            s[i] = '1';
            if (i+1 < len && s[i+1] == '1') s[i+1] = '0';
            return s;
        }
    }
    s[0] = '0';
    s = "1" + s;
    return s;
}
long long get_long(string s) {
    long long tmp = 1;
    long long ret = 0;
    int len = s.length();
    for (int i=len-1; i>=0; i--) {
        ret += ((s[i]-'0') * tmp);
        tmp *= 2;
    }
    return ret;
}
vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    int len = numbers.size();
    for (int i=0; i<len; i++) {
        string converted = get_max(binary(numbers[i]));
        answer.push_back(get_long(converted));
    }
    return answer;
}