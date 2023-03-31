#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> a) {
    int answer = 0;
    int min_val = 1000000000;
    int len = a.size();
    int min_idx = 0;
    for (int i=0; i<len; i++) {
        if (min_val > a[i]) {
            min_val = a[i];
            min_idx = i;
        }
    }
    min_val = a[0];
    for (int i=1; i<min_idx; i++) {
        if (min_val > a[i]) {
            min_val = a[i];
            answer++;
        }
    }
    min_val = a[len-1];
    for (int i=len-2; i>min_idx; i--) {
        if (min_val > a[i]) {
            min_val = a[i];
            answer++;
        }
    }
    if (min_idx == 0 || min_idx == len - 1) return answer + 2; 
    return answer + 3;
}