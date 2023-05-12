#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

map <string, int> sell;
int N;

bool custom_sort(pair<int,string> a, pair<int,string> b) {
  if (a.first == b.first) {
    return a.second < b.second;
  }
  return a.first > b.first;
}
int main() {
  cin >> N;
  string s;
  for (int i=0; i<N; i++) {
    cin >> s;
    sell[s]++;
  }
  vector <pair<int, string>> best_seller;
  for (auto s : sell) {
    best_seller.push_back({s.second, s.first});
  }
  sort(best_seller.begin(), best_seller.end(), custom_sort);
  cout << best_seller[0].second;
  return 0;
}