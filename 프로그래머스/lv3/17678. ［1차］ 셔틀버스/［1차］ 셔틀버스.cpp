#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

string str_time (int n) {
    string hour = to_string(n / 60);
    string min = to_string(n % 60);
    if (hour.length() == 1) hour = "0" + hour;
    if (min.length() == 1) min = "0" + min;
    return hour + ":" + min;
}
string solution(int n, int t, int m, vector<string> ttable) {
    vector <int> num;
    for (int i=0; i<ttable.size(); i++) {
        int hour = stoi(ttable[i].substr(0, 2));
        int mins = stoi(ttable[i].substr(3, 2));
        num.push_back(60*hour + mins);
    }
    sort(num.begin(), num.end());
    
    vector <int> bus_times;
    for (int i=0; i<n; i++) {
        bus_times.push_back(540 + (i*t));
    }
    int max_time = bus_times[bus_times.size()-1];
    int gone[2001];
    int ans = 0;
    for (int arrive=max_time; arrive>=0; arrive--) {
        int before_corn_idx = upper_bound(num.begin(), num.end(), arrive) - num.begin() - 1;
        if (before_corn_idx == -1) {
            return str_time(arrive);
        }
        memset(gone, 0, sizeof(gone));
        
        for (int bt=0; bt<bus_times.size(); bt++) {
            int bus_time = bus_times[bt];
            int seat = m;
            int upper_idx = upper_bound(num.begin(), num.end(), bus_time) - num.begin();
            for (int i=0; i<upper_idx; i++) {
                if (gone[i]) continue;
                if (seat == 0) break;
                gone[i] = 1;
                seat -= 1;
                if (before_corn_idx == i) { // corn 앞 사람
                    if (seat > 0) {
                        return str_time(arrive);
                    }
                    else {
                        if (bt + 1 < bus_times.size()) {
                            return str_time(arrive);
                        }
                    }
                }
            }
        }
    }
}