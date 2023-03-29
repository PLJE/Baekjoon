#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<string.h>
#include<queue>

using namespace std;

int N, K;
vector <int> v;
vector <int> plug;

int isexist(int num, int idx) {
	for (int i = idx; i < K; i++) {
		if (num == v[i]) return 1;
	}
	return 0;
}

int getidx(int num, int idx) {
	for (int i = idx; i < K; i++) {
		if (v[i] == num) return i;
	}
	return -1;
}
void print() {
	cout << "plug ";
	for (int i = 0; i < plug.size(); i++) {
		cout << plug[i] << " ";
	}
	cout << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;
	int x;
	for (int i = 0; i < K; i++) {
		cin >> x;
		v.push_back(x);
	}

	for (int i = 0; i < N; i++) {
		plug.push_back(v[i]);
		plug.erase(unique(plug.begin() , plug.end()), plug.end());
	}
	int total = 0;

	for (int i = N; i < K; i++) {
		int now = v[i];

		bool samechk = false;
		for (int j = 0; j < plug.size(); j++) {
			if (plug[j] == now) {
				samechk = true;
				break;
			}
		}
		if (samechk) continue;

		if (plug.size() < N) {
			plug.push_back(now);
			continue;
		}

		bool exist = false;
		for (int j = 0; j < plug.size(); j++) {
			if (isexist(plug[j], i + 1) == 0) {
				plug[j] = now;
				total++;
				exist = true;
				break;
			}
		}
		if (exist) continue;
		
		int change = 0;
		int idx = 0;
		for (int j = 0; j < plug.size(); j++) {
			if (change < getidx(plug[j], i + 1)) {
				change = getidx(plug[j], i + 1);
				idx = j;
			}
		}
		plug[idx] = now;
		total++;
	}
	cout << total;
}