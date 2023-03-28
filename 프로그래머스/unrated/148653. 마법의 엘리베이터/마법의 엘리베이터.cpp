#include <string>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;


int solution(int num) {
    int answer = 0;
    while(num) {
        int one = num % 10;
        int ten = (num / 10) % 10;
        
        if (one < 5) {
            answer += one;
        } else if (one == 5) {
            if (ten < 5) {
                answer += 5;
            } else if (ten >= 5) {
                answer += 5;
                num += 10;
            }
        } else if (one > 5) {
            answer += (10 - one);
            num += 10;
        }
        num /= 10;
    }
    return answer;
}