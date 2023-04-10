#include <iostream>
#include <climits>
#include <string>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int V, E;
vector<vector<int>> edges;
int parent[100001];

bool comp(vector<int> a, vector<int> b) {
    return a[2] < b[2];
}
void union_node(int a, int b) {
    parent[a] = b;
}
int find_parent(int a) {
    if (parent[a] == a) return a;
    return parent[a] = find_parent(parent[a]);
}
int main() {
    cin >> V >> E;
    int a, b , c;
    for (int i=1; i<=V; i++) parent[i] = i;
    for (int i=0; i<E; i++) {
        cin >> a >> b >> c;
        edges.push_back({a,b,c});
    }
    sort(edges.begin(), edges.end(), comp);
    long long ans = 0;
    for (int i=0; i<E; i++) {
        a = edges[i][0];
        b = edges[i][1];
        c = edges[i][2];
        int pa = find_parent(a);
        int pb = find_parent(b);
        if (pa != pb) {
            union_node(pa, pb);
            ans += c;
        }
    }
    cout << ans;
}