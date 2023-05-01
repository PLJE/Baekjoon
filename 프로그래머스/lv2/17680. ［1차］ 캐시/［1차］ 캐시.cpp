#include <string>
#include <climits>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

string to_lower (string city) {
    string l = "";
    for (int i=0; i<city.length(); i++) l.push_back(tolower(city[i]));
    return l;
}
map <string, int> is_in;
int solution(int csize, vector<string> cities) {
    int answer = 0;
    int city_size = cities.size();
    int h = 1;
    if (csize == 0) {
        return 5 * city_size;
    }
    for (int i=0; i<city_size; i++) {
        cities[i] = to_lower(cities[i]);
        if (is_in.find(cities[i]) != is_in.end()) {
            answer += 1;
            is_in[cities[i]] = h;
        } else {
            if (is_in.size() < csize) {
                is_in[cities[i]] = h;
            } else {
                int min_time = INT_MAX;
                string change_city = "";
                for (auto a : is_in) {
                    string city = a.first;
                    int used_time = a.second;
                    if (min_time > used_time) {
                        min_time = used_time;
                        change_city = city;
                    }
                }
                is_in.erase(change_city);
                is_in[cities[i]] = h;   
            }
            answer += 5;
        }
        h++;
    }
    return answer;
}