#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <climits>

using namespace std;

int T, N, M, k;
long long x;
long long A[6001][6001];
long long B[6001][6001];
long long AM[6001];
long long BM[6001];

int main() {
    cin >> T;
    for (int t=1; t<=T; t++) {
        cin >> N;
        long long min_val = LLONG_MAX;
        long long total_a = 0;
        for (int n=1; n<=N; n++) {
            cin >> x;
            min_val = min(min_val, x);
            A[1][n] = x;
            total_a += x;
        }
        AM[N] = total_a;
        AM[N - 1] = total_a - min_val; 
        
        min_val = LLONG_MAX;
        long long total_b = 0;
        cin >> M;
        for (int m=1; m<=M; m++) {
            cin >> x;
            min_val = min(min_val, x);
            B[1][m] = x;
            total_b += x;
        }
        BM[M] = total_b;
        BM[M - 1] = total_b - min_val;
        
        cin >> k;
        for (int i=2; i<=N; i++) {
            min_val = LLONG_MAX;
            for (int j=i; j<=N; j++) {
                A[i][j] = A[i-1][j-1] + A[1][j];
                min_val = min(min_val, A[i][j]);
            }
            AM[N - i] = total_a - min_val;
        }
        for (int i=2; i<=M; i++) {
            min_val = LLONG_MAX;
            for (int j=i; j<=M; j++) {
                B[i][j] = B[i-1][j-1] + B[1][j];
                min_val = min(min_val, B[i][j]);
            }
            BM[M - i] = total_b - min_val;
        }
        long long ans = 0;
        for (int i=0; i<=k/2; i++) {
            if (i<=N && k-i<=M) ans = max(ans, AM[i] + BM[k-i]);
            if (k-i<=N && i<=M) ans = max(ans, AM[k-i] + BM[i]);
        }
        cout << "Case #" << t << ": " << ans << "\n";
    }
    return 0;
}