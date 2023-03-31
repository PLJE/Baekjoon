#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers) {
    set <int> hab;
    vector<int> answer;
    int len = numbers.size();
    for (int i=0; i<len; i++) {
        for (int j=i+1; j<len; j++) {
            hab.insert(numbers[i] + numbers[j]);
        }
    }
    for (auto p : hab) {
        answer.push_back(p);
    }
    return answer;
}