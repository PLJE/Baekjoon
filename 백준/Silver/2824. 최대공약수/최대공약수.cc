#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int N,M;
int x;
vector <int> A;
vector <int> B;

long long gcd(long long a, long long b) {
    if (b==0) return a;
    if (a<b) return gcd(b,a);
    else return gcd(b, a%b);
}

int main() {
    cin >> N;
    for (int n=1; n<=N; n++) {
        cin >> x;
        A.push_back(x);
    }
    cin >> M;
    for (int m=1; m<=M; m++) {
        cin >> x;
        B.push_back(x);
    }
    long long ans = 1;
    bool is_longer = false;
    for (int i=0; i<N; i++) {
        if (A[i]==1) continue;
        for (int j=0; j<M; j++) {
            if (B[j]==1) continue;
            long long gcd_num = gcd(A[i],B[j]);
            A[i] /= gcd_num;
            B[j] /= gcd_num;
            ans *= gcd_num;
            if (ans >= 1000000000) {
                ans %= 1000000000;
                is_longer = true;
            }
        }
    }
    if (!is_longer) cout << ans;
    else {
        int zero_cnt = 9 - to_string(ans).length();
        for (int i=0; i<zero_cnt; i++) cout << 0;
        cout << ans;
    }
}