#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

double score(string sc) {
    double ret = 0.;
    if (sc[0] == 'A') {
        ret = 4.;
        if (sc[1] == '+') ret += 0.5;
    } 
    else if (sc[0] == 'B') {
        ret = 3.;
        if (sc[1] == '+') ret += 0.5;
    }
    else if (sc[0] == 'C') {
        ret = 2.;
        if (sc[1] == '+') ret += 0.5;
    }
    else if (sc[0] == 'D') {
        ret = 1.;
        if (sc[1] == '+') ret += 0.5;
    } 
    return ret;
}

int main() {
    string tmp , sc;
    double get_sc;

    double divide_sc = 0;
    double total_sc = 0;
    for (int i=0; i<20; i++) {
        cin >> tmp >> get_sc >> sc;
        if (sc == "P") continue;
        divide_sc += get_sc;
        total_sc += (get_sc * score(sc));
    }
    cout << total_sc / divide_sc;
}
