#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector <pair<int,int>> sorted;
long long total;

void set_sorted(int len, vector<int> food_times) {
    for (int i=0; i<len; i++) {
        total += food_times[i];
        sorted.push_back({food_times[i], i+1});
    }
    sort(sorted.begin(), sorted.end());
}

int solution(vector<int> food_times, long long k) {
    long long len = food_times.size();
    set_sorted(len, food_times);
    k += 1;
    if (k > total) return -1;
    
    long long val = sorted[0].first * len;
    if (k>=1 && k<=val) {
        int ret = k % len;
        return ret == 0 ? len : ret;
    }
    
    int row = sorted[0].first + 1;
    long long idx = 0;
    while (1) {
        while (sorted[idx].first < row) {
            idx++;
        }
        long long diff = len - idx;
        long long left = val + 1;
        long long right = val + diff;
        if (k <= right && k >= left) {
            vector <int> v;
            for (int i=idx; i<len; i++) {
                v.push_back(sorted[i].second);
            }
            sort(v.begin(), v.end());
            return v[k - left];
        }
        row++;
        val = val + diff;
    }
    return 0;
}