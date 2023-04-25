#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <climits>

using namespace std;

const int MAX_COST = INT_MAX;
int color_cost[4][1001];
int total_cost[4][1001];
int first_color[2][4];
int N;
int ans = MAX_COST;

void init(int N) {
    for (int i = 0; i <= 1; i++) {
        for (int j = 1; j <= 3; j++) {
            first_color[i][j] = j;
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= 3; j++) {
            total_cost[j][i] = MAX_COST;
        }
    }
}

int main() {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= 3; j++) {
            cin >> color_cost[j][i];
        }
    }

    init(N);
    total_cost[1][1] = color_cost[1][1];
    total_cost[2][1] = color_cost[2][1];
    total_cost[3][1] = color_cost[3][1];
    for (int i = 2; i <= N; i++) {
        for (int j = 1; j <= 3; j++) {
            for (int k = 1; k <= 3; k++) {
                if (j == k) continue;

                if (total_cost[j][i] > color_cost[j][i] + total_cost[k][i - 1]) {
                    total_cost[j][i] = color_cost[j][i] + total_cost[k][i - 1];
                    first_color[i % 2][j] = first_color[1 - i % 2][k];
                }
            }
        }
    }
    for (int i = 1; i <= 3; i++) {
        if (first_color[N % 2][i] != i) {
            ans = min(ans, total_cost[i][N]);
        }
    }
    
    init(N);
    total_cost[1][N] = color_cost[1][N];
    total_cost[2][N] = color_cost[2][N];
    total_cost[3][N] = color_cost[3][N];
    for (int i = N - 1; i >= 1; i--) {
        for (int j = 1; j <= 3; j++) {
            for (int k = 1; k <= 3; k++) {
                if (j == k) continue;

                if (total_cost[j][i] > color_cost[j][i] + total_cost[k][i + 1]) {
                    total_cost[j][i] = color_cost[j][i] + total_cost[k][i + 1];
                    first_color[i % 2][j] = first_color[1 - i % 2][k];
                }
            }
        }
    }
    for (int i = 1; i <= 3; i++) {
        if (first_color[1 % 2][i] != i) {
            ans = min(ans, total_cost[i][1]);
        }
    }
    cout << ans;


    return 0;
}