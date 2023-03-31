#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector <int> three;
    while (1) {
        int c = n / 3;
        if (c < 3) {
            three.push_back(n % 3);
            if (c!= 0)
                three.push_back(c);
            break;
        } 
        int r = n % 3;
        three.push_back(r);
        n /= 3;
    }
    int loc = 0;
    for (int i=three.size()-1; i>=0; i--) {
        answer += (pow(3,loc) * three[i]);
        loc++;
    }
    return answer;
}