#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers) {
    int total = 45;
    for (int i=0; i<numbers.size(); i++) {
        total -= numbers[i];
    }
    return total;
}