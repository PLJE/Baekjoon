#include <iostream>
#include <algorithm>
#include <string>
#include <climits>

using namespace std;

int N;
int relation[51][51];

int main(){
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    int a, b;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            if (i==j) continue;
            relation[i][j] = INT_MAX;
        }
    }
    while (1) {
        cin >> a >> b;
        if (a==-1) break;
        relation[a][b] = 1;
        relation[b][a] = 1;
    }
    for (int k=1; k<=N; k++) {
        for (int i=1; i<=N; i++) {
            for (int j=1; j<=N; j++) {
                if (i==j) continue;
                if (relation[i][k] != INT_MAX && relation[k][j] != INT_MAX) {
                    relation[i][j] = min(relation[i][j], relation[i][k] + relation[k][j]);
                }
            }
        }
    }
    vector <pair<int,int>> score_idx;
    for (int i=1; i<=N; i++) {
        int score = 0;
        for (int j=1; j<=N; j++) {
            score = max(score, relation[i][j]);
        }
        score_idx.push_back({score, i});
    }

    sort(score_idx.begin(), score_idx.end());
    int min_score = score_idx[0].first;
    vector <int> candidates;
    for (int i=0; i<N; i++) {
        if (score_idx[i].first != min_score) break;
        candidates.push_back(score_idx[i].second);
    }
    cout << min_score << " " << candidates.size() << "\n";
    for (int i=0; i<candidates.size(); i++) {
        cout << candidates[i] << " ";
    }
}