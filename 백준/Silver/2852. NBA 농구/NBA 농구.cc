#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int goal[2900];
int N;

int minute(string s) {
    int hour = stoi(s.substr(0,2)) * 60;
    int minute = stoi(s.substr(3,2));
    return hour + minute;
}
string str_time(int n) {
    string hour = to_string(n/60);
    string minute = to_string(n%60);
    if (hour.length() == 1) hour = "0" + hour;
    if (minute.length() == 1) minute = "0" + minute;
    return hour + ":" + minute;
}
int main() {
    cin >> N;
    int team;
    string gtime;
    for (int i=0; i<N; i++) {
        cin >> team >> gtime;
        goal[minute(gtime)] = team;
    }

    int a_score = 0;
    int b_score = 0;
    int a_time = 0;
    int b_time = 0;
    for (int tick=0; tick<=2880; tick++) {
        if (a_score > b_score) {
            a_time++;
        } else if (b_score > a_score){
            b_time++;
        }
        if (goal[tick] != 0) {
            if (goal[tick] == 1) a_score++;
            else b_score++;
        }
    }
    cout << str_time(a_time) << "\n" << str_time(b_time);
}