#include<iostream>
#include<vector>
#include<cmath>
#include<string>
#include<queue>
#include<cstring>
#include<algorithm>
#include<climits>
#include<set>
using namespace std;

long long N,x;
vector <long long> one;
vector <long long> two;
vector <long long> thr;
vector <long long> fur;
vector <long long> hab;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>N;
    for(long long i=1;i<=N;i++){
        cin>>x;
        one.push_back(x);
        cin>>x;
        two.push_back(x);
        cin>>x;
        thr.push_back(x);
        cin>>x;
        fur.push_back(x);
    }
    sort(one.begin(),one.end());
    sort(two.begin(), two.end());
    sort(thr.begin(), thr.end());
    sort(fur.begin(), fur.end());
    //one.erase(unique(one.begin(),one.end()),one.end());
    //two.erase(unique(two.begin(), two.end()), two.end());
    //thr.erase(unique(thr.begin(), thr.end()), thr.end());
    //fur.erase(unique(fur.begin(), fur.end()), fur.end()); //중복 제거 
    long long t = thr.size();
    long long k = fur.size();
    for(long long i=0;i<t;i++){
        for(long long j=0;j<k;j++)
            hab.push_back(thr[i]+fur[j]);
    }
    sort(hab.begin(),hab.end());
    t = one.size();
    k = two.size();
    long long cnt = 0;
    for(long long i=0;i<t;i++){
        for(long long j=0;j<k;j++){
            long long fd = 0 - (one[i]+two[j]);
            cnt += (upper_bound(hab.begin(),hab.end(),fd)-lower_bound(hab.begin(), hab.end(), fd));
        }
    }
    cout<<cnt;
}
