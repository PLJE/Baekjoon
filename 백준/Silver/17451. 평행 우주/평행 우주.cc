#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

int N;
vector <long long> velocity;

int main()
{
	cin >> N;
	int x;
	for (int i=0; i<N; i++) {
		cin >> x;
		velocity.push_back(x);
	}
	long long last = velocity[N-1];
	int cnt = 1;
	for (int i=N-2; i>=0; i--) {
		if (last <= velocity[i]) {
			cnt++;
			last = velocity[i];
		} else break;
	}
	long long start = velocity[N-cnt];
	for (int i=N-cnt-1; i>=0; i--) {
		if (start % velocity[i] == 0) continue;
		long long rest = start % velocity[i];
		start = start + (velocity[i] - rest);
	}
	cout << start;
}
