#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

int N, ans;
vector <vector<int>> dice;

int get_round(int num, int x) {
	if (x==0 || x==5) return max({dice[num][1], dice[num][2], dice[num][3], dice[num][4]});
	if (x==2 || x==4) return max({dice[num][0], dice[num][1], dice[num][3], dice[num][5]});
	if (x==1 || x==3) return max({dice[num][0], dice[num][2], dice[num][4], dice[num][5]});
}
int get_opposite(int x) {
	if (x==0) return 5;
	if (x==5) return 0;
	if (x==2) return 4;
	if (x==4) return 2;
	if (x==1) return 3;
	if (x==3) return 1;
}
void find_max(int pre_num, int cnt, int hab) {
	if (cnt == N-1) {
		ans = max(ans, hab);
		return;
	}
	int next_num = dice[cnt][get_opposite(pre_num)];
	for (int i=0; i<6; i++) {
		if (dice[cnt+1][i] == next_num) {
			next_num = i;
			break;
		}
	}
	find_max(next_num, cnt+1, hab + get_round(cnt+1, next_num));
}
int main()
{
	cin >> N;
	int x;
	for (int i=1; i<=N; i++) {
		vector <int> v;
		for (int j=1; j<=6; j++) {
			cin >> x;
			v.push_back(x);
		}
		dice.push_back(v);
	}
	for (int first_num=0; first_num<6; first_num++) {
		find_max(first_num, 0, get_round(0, first_num));
	}
	cout << ans;
}
