#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

int N;
vector <pair<int,int>> queries;
map <int,int> lens;
map <int,int> area_dir;

pair<int,int> left_right(int idx) {
	int left = idx - 1;
	int right = idx + 1;
	if (left < 0) left = 5;
	if (right > 5) right = 0;
	return {left, right};
}
int main()
{
	cin >> N;
	int dir, len;
	for (int i=1; i<=6; i++) {
		cin >> dir >> len;
		queries.push_back({dir, len});
		if (lens.find(dir) != lens.end()) {
			area_dir[dir] = 1;
		}
		lens[dir] = len;
	}
	int total = 1;
	for (auto a : lens) {
		if (area_dir[a.first] == 0){
			total *= a.second;
		}
	}
	int area = 1;
	for (int i=0; i<6; i++) {
		pair<int,int> lr = left_right(i);
		int left = lr.first;
		int right = lr.second;
		if (area_dir[queries[left].first] != 0) {
			if (area_dir[queries[right].first] != 0) {
				area *= queries[i].second;
			}
		} 
	}
	cout << (total - area) * N;
	return 0;
}
