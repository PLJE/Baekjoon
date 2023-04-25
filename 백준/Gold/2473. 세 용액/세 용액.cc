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

long long N, l,r;
vector <long long> v;
long long sec,thr,f,fir;
long long dab = LLONG_MAX;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>N;
    long long x;
    for(long long i=0;i<N;i++){
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());

    for(long long i=0;i<= N-3 ;i++){
        f = v[i]; //하나 고르고 

        l = i+1; //그 뒤 배열에서 두개 고름
        r = N-1;
        while(l<r){
            long long hab = f + v[l] + v[r];

            long long ab;
            if (hab < 0) ab = (long long)(-1 * hab);
            else ab = hab;

            if(hab == 0){
                cout<<f<<" "<<v[l]<<" "<<v[r];
                return 0;
            }

            else if(hab < 0){ //음수면 왼쪽++
                if(dab > ab){
                    dab = ab;
                    fir = f;
                    sec = v[l];
                    thr = v[r];
                }
                l++;
            }
            else if(hab > 0){ //양수면 오른쪽--
                if (dab > ab) {
                    dab = ab;
                    fir = f;
                    sec = v[l];
                    thr = v[r];
                }
                r--;
            }
        }
    }
    cout<<fir<<" "<<sec<<" "<<thr;
    return 0;
}
