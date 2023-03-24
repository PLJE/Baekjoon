#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map <int,int> cnt;
vector <pair<double,int>> fail;

bool comp(pair<double,int> a, pair<double,int> b) {
    if (a.first == b.first) {
        return a.second > b.second;
    } 
    return a.first < b.first;
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    int len = stages.size();
    for (int i =0; i<len; i++) {
        cnt[stages[i]]++;
    }
    sort(stages.begin(), stages.end());
    for (int i=1; i<=N; i++) {
        int idx = lower_bound(stages.begin(), stages.end(), i) - stages.begin();
        if (len - idx == 0) fail.push_back({0, i});
        else fail.push_back({((double)(cnt[i])/(double)(len-idx)), i});
    }
    sort(fail.begin(), fail.end(), comp);
    for (int i= N-1; i>=0; i--) {
        answer.push_back(fail[i].second);
    }
    return answer;
}