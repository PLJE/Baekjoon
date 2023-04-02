#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> idx_edges[300000];
int visit[300000];
vector <long long> A;
long long answer;

long long dfs(int now) {
    visit[now] = 1;
    for (int i=0; i<idx_edges[now].size(); i++) {
        int next = idx_edges[now][i];
        if (visit[next] == 0) {
            A[now] += dfs(next);
        }
    }
    answer += abs(A[now]);
    return A[now];
}

long long solution(vector<int> a, vector<vector<int>> edges) {
    int len = a.size();
    for (int i=0; i<len; i++) {
        A.push_back(a[i]);
    }
    for (int i=0; i<len-1; i++) {
        idx_edges[edges[i][0]].push_back(edges[i][1]);
        idx_edges[edges[i][1]].push_back(edges[i][0]);
    }
    visit[0] = 1;
    dfs(0);
    if (A[0] != 0) return -1;
    return answer;
}