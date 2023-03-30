#include <iostream>
#include <map>
#include <sstream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int N, x, cnt;
vector <int> in;
vector <int> post;

int get_idx(int s, int e, int val) {
    for (int i=s; i<=e; i++) {
        if (in[i] == val) return i;
    }
    return -1;
}
void print_pre(int i_start, int i_end, int p_start, int p_end) {
    
    cout << post[p_end] << " "; // root

    int root_idx = get_idx(i_start, i_end, post[p_end]);
    int left_node_cnt = root_idx - i_start;
    int right_node_cnt = i_end - root_idx;

    if (left_node_cnt > 0)
        print_pre(i_start, i_start + left_node_cnt - 1, p_start, p_start + left_node_cnt - 1);
    if (right_node_cnt > 0)
        print_pre(root_idx + 1, i_end, p_start + left_node_cnt, p_start + left_node_cnt + right_node_cnt - 1);
    return;
}

int main() {
    cin >> N;
    for (int i=1; i<=N; i++) {
        cin >> x;
        in.push_back(x);
    }
    for (int i=1; i<=N; i++) {
        cin >> x;
        post.push_back(x);
    }
    print_pre(0, N-1, 0, N-1);
    return 0;
}