#include <iostream>
#include <map>
#include <sstream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int T, x;

int main() {
    cin >> T;
    for (int t=0; t<T; t++) {
        cin >> x;
        int bot = 1;
        int turn = 2;
        int last_idx = 0;
        while (last_idx + 2 < x) {
            if (turn == 2) { // john
                if (last_idx + 3 < x) {
                    last_idx += 3;
                } else if (last_idx + 2 < x) {
                    last_idx += 2;
                }
                turn = 1;
            } else if (turn == 1) { // bot
                if (last_idx + 2 < x) {
                    last_idx += 2;
                    bot += 1;
                }
                turn = 2;
            }  
        }
        cout << "Case #" << t+1 << ": " << bot << "\n";
    }
}