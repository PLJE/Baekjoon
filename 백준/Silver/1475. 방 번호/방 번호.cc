#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

int N;
map <int,int> chk;
int ans;

int main()
{
	cin >> N;
	string num_to_string = to_string(N);
	for (int i=0; i<num_to_string.length(); i++) {
		int num = num_to_string[i] - '0';
		chk[num]++;
	}
	for (auto a : chk) {
		if (a.first == 6 || a.first == 9) continue;
		ans = max(ans, a.second);	
	}
	int nine_six = chk[6] + chk[9];
	int cnt = nine_six % 2 == 0 ? nine_six/2 : nine_six/2+1;
	ans = max(ans, cnt);
	cout << ans;
}
