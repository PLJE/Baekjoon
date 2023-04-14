#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int arr[101][101];

int solution(int n, vector<vector<int>> results) {
    for (int i=0; i<results.size(); i++) {
        arr[results[i][0]][results[i][1]] = 1;
    }
    for (int k=1; k<=n; k++) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                if (i==j) continue;
                if (arr[i][k] && arr[k][j]) arr[i][j] = 1;
            }
        }
    }
    int ans = 0;
    for (int i=1; i<=n; i++) {
        // col
        int before = 0; int after = 0;
        for (int j=1; j<=n; j++) {
            if (i==j) continue;
            if (arr[j][i]) before++;
            if (arr[i][j]) after++;
        }
        if (before + after == n-1) ans++;
    }
    return ans;
}