#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int N;
int visit[9];
int arr[9];

void permutation(int idx) {
    if (idx == N) {
        for (int i=0; i<N; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i=1; i<=N; i++) {
        if (visit[i] == 0) {
            visit[i] = 1;
            arr[idx] = i;
            permutation(idx+1);
            visit[i] = 0;
        }
    }
}
int main() { 
    cin >> N;
    permutation(0);
}
