#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string get_binary (int num, int len) {
    string binary_str = "";
    if (num == 0 || num == 1) binary_str = to_string(num);
    else {
        int c = num;
        int r;
        while (c != 1) {
            r = c % 2;
            c = c / 2;
            binary_str =  to_string(r)+binary_str;
        }
        binary_str = "1" + binary_str;
    }
    if (binary_str.length() < len) {
        int zero_cnt = len - binary_str.length();
        string zero_padding = "";
        for (int i=0; i<zero_cnt; i++) {
            zero_padding.push_back('0');
        }
        binary_str = zero_padding + binary_str;
    }
    return binary_str;
}
vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for (int i=0; i<n; i++) {
        string s12 = "";
        string s1 = get_binary(arr1[i], n);
        string s2 = get_binary(arr2[i], n);
        for (int j=0; j<n; j++) {
            if (s1[j] == '1' || s2[j] == '1') s12.push_back('#');
            else s12.push_back(' ');
        }
        answer.push_back(s12);
    }
    return answer;
}