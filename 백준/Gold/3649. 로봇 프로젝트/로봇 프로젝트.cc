#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    while (1) {
        int x, n;
        if (cin >> x) {
            cin >> n;
            vector <int> lego;
            for (int i = 0; i < n; i++) {
                int len;
                cin >> len;
                lego.push_back(len);
            }
            sort(lego.begin(), lego.end());

            int left = 0;
            int right = n - 1;
            int hole_nano = x * 10000000;

            while (left < right) {
                int plus = lego[left] + lego[right];
                if (plus > hole_nano) {
                    right--;
                }
                else if (plus < hole_nano) {
                    left++;
                }
                else {
                    cout << "yes " << lego[left] << " " << lego[right]<<"\n";
                    break;
                }
            }
            if (left >= right) {
               cout << "danger\n";
            }
        } else {
            break;
        }
    }
    return 0;
}