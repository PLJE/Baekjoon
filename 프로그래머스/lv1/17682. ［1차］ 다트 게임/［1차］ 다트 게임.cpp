#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool is_num (char c) {
    int to_int = c-'0';
    if (to_int >=0 && to_int<=9) return true;
    return false;
}
bool is_effect (char c) {
    if (c == '*' || c=='#') return true;
    return false;
}
int solution(string dart) {
    int answer = 0;
    vector <int> nums;
    map <int, char> effect;
    
    int slen = dart.length();
    int cnt_num = 0;
    for (int i=0; i<slen; i++) {
        if (is_num(dart[i])) {
            int num = 0;
            num = dart[i] - '0';
            if (is_num(dart[i+1])) { // 10 인 경우
                num = 10;
                i++;
            }
            if (dart[i+1] == 'D') num = num * num;
            else if (dart[i+1] == 'T') num = num * num * num;
            nums.push_back(num);
            cnt_num++;
        } else if (is_effect(dart[i])) {
            effect[cnt_num] = dart[i];
        }
    }
    for (auto a : effect) {
        int idx = a.first-1;
        char e = a.second;
        if (e == '#') {
            nums[idx] *= -1;
        } 
        if (e == '*') {
            if (idx-1 >= 0) nums[idx-1] *= 2;
            nums[idx] *= 2;
        }
    }
    for (int i=0; i<nums.size(); i++) answer += nums[i];
    return answer;
}