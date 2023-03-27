#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct node {
    node(int cnum, int cx, int cy) {
        num = cnum;
        x = cx;
        y = cy;
    }
    int num;
    int x; int y;
    node * left;
    node * right;
};

node * root;

vector <vector<int>> info;
vector <int> preorder;
vector <int> postorder;

bool comp(vector<int> a, vector<int> b) {
    if (a[1] == b[1]) {
        return a[0] < b[0];
    }
    return a[1] > b[1];
}
vector<vector<int>> add_idx(vector<vector<int>> v) {
    for (int i=0; i<v.size(); i++) {
        v[i].push_back(i+1); // (x좌표, y좌표, node number)
    }
    return v;
}
void insert(int n, int x, int y) {
    node * ptr = root;  
    while (1) {
        if (ptr -> x > x) {
            if (ptr -> left == NULL) {
                ptr -> left = new node(n, x, y);
                ptr -> left -> left = NULL;
                ptr -> left -> right = NULL;
                break;
            } else {
                ptr = ptr -> left;
            }
        } else if (ptr -> x < x) {
            if (ptr -> right == NULL) {
                ptr -> right = new node(n, x, y);
                ptr -> right -> left = NULL;
                ptr -> right -> right = NULL;
                break;
            } else {
                ptr = ptr -> right;
            }
        }
    }
    return;
}
void pre_recursion(node * ptr) {
    if (ptr == NULL) return;
    preorder.push_back(ptr -> num);
    pre_recursion(ptr -> left);
    pre_recursion(ptr -> right);
}
void post_recursion(node * ptr) {
    if (ptr == NULL) return;
    post_recursion(ptr -> left);
    post_recursion(ptr -> right);
    postorder.push_back(ptr -> num);
}
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    info = add_idx(nodeinfo);
    sort(info.begin(), info.end(), comp);
    root = new node(info[0][2], info[0][0], info[0][1]);
    root -> left = NULL;
    root -> right = NULL;
    
    int len = info.size();
    for (int i=1; i<len; i++) {
        insert(info[i][2], info[i][0], info[i][1]);
    }
    // traversal
    pre_recursion(root);
    answer.push_back(preorder);
    post_recursion(root);
    answer.push_back(postorder);
    return answer;
}