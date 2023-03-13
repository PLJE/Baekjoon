//전체적인 풀이는 간단한데, 세부적 구현에서 틀리기 쉽게 해놓은 문제라서 레벨3
//원 단위 절사, 즉 0.1 0.9 곱하는 과정에서 수 달라지는거 처리
//중복된 셀러의 판매를 모두 합해서 하는 것과 매번 판매 할 때마다 상위로 올려주는 게 결과가 다르게 나온다 
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
#include<cmath>

using namespace std;
map <string,int> getnum;
map <int,string> getname;
int parent[10001];
int dab[10001];
map <int,int> money;

void savename(vector <string> s){
    for(int i=0;i<s.size();i++){
        getnum[s[i]] = i;
        getname[i] = s[i];
    }
}
void save_rel(vector <string> ref){
    for(int i=0;i<ref.size();i++){
        if(ref[i]=="-") parent[i] = -1;
        else parent[i] = getnum[ref[i]];
    }
}
void share(int idx , int m){
    while(1){
        if(m*(0.1) < 1){
            dab[idx] += m;
            break;
        }
        int k = m*0.1;
        dab[idx] += (m - k);
        m = k;
        idx = parent[idx];
        if(idx == -1) break;
    }
    return;
}
vector<int> solution(vector<string> enr, vector<string> ref, vector<string> sell, vector<int> am) {
    savename(enr);
    save_rel(ref);
    
    for(int i =0;i<sell.size();i++){
        share(getnum[sell[i]] , am[i]*100);
    }
    vector<int> ans;
    for(int i=0;i<enr.size();i++){
        ans.push_back(dab[i]);
    }
    return ans;
}