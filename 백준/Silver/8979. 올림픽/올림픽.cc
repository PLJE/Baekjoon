#include <iostream>
#include <cstring>
#include <set>
#include <algorithm>
#include <string>
#include <climits>
#include <vector>
#include <queue>

using namespace std;

vector <vector<int>> medals;
int N, M;

bool comp_medals(vector<int> a, vector<int> b) {
    if (a[0] == b[0]) {
        if (a[1] == b[1]) {
            return a[2] > b[2];
        } 
        return a[1] > b[1];
    } return a[0] > b[0];
}
int main() {
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    int num, g, s, b;
    for (int i=1; i<=N; i++) {
        cin >> num >> g >> s >> b;
        medals.push_back({g, s, b, num}); // 금, 은, 동, 나라번호
    }
    sort(medals.begin(), medals.end(), comp_medals);
    if (medals[0][3] == M) {
        cout << 1;
        return 0;
    }
    int rank = 1;
    g = medals[0][0];
    s = medals[0][1];
    b = medals[0][2];
    for (int i=1; i<N; i++) {
        if (g == medals[i][0] && s == medals[i][1] && b == medals[i][2]) {
            rank = rank;
        } else {
            g = medals[i][0];
            s = medals[i][1];
            b = medals[i][2];
            rank++;
        }
        if (medals[i][3] == M) {
            cout << rank;
            break;
        }
    }
    return 0;
}