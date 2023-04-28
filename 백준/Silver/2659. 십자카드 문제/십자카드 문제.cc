#include <iostream>
#include <string>
#include <queue>

using namespace std;

int get_clocknum (int num) {
    int min_val = num;
    for (int i=0; i<4; i++) {
        num = num % 1000 * 10 + num / 1000;
        if (min_val > num) min_val = num;
    }
    return min_val;
}

int main(){
	int a, b, c, d;
    cin >> a >> b >> c >> d;
    int ans = 0;
    int target = get_clocknum(1000*a + 100*b + 10*c + d);
    for (int i=1111; i<=target; i++) {
        int cnum = get_clocknum(i);
        if (cnum == i) {
            ans++;
        }
        if (cnum == target) break;
    }
    cout << ans;
}