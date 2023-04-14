#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    for (long long i = left; i <= right; i++) {
        long long r = i / n;
        long long c = i % n;
        if (c <= r) answer.push_back(r+1);
        else answer.push_back(c+1);
    }
    return answer;
}