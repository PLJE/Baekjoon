#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

int N;
vector <long long> num;

int main() { 
    cin >> N;
    int x; 
    for (int i=0; i<N; i++) {
        cin >> x;
        num.push_back(x);
    }
    sort(num.begin(), num.end());
    int ans = 0;
    for (int i=0; i<N; i++) {
        int left = 0;
        int right = N-1;
        while (left < right) {
            if (left == i) {
                left++;
                continue;
            }
            if (right == i) {
                right--;
                continue;
            }
            if (num[left] + num[right] == num[i]) {
                ans++;
                break;
            }
            if (num[left] + num[right] < num[i]) {
                left++;
            }
            else right--;
        }
    }
    cout << ans;
}
