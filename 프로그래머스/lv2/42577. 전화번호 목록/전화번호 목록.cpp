#include <string>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <climits>
#include <vector>
#include <map>

using namespace std;

map <string , int> phash;

bool solution(vector<string> pb) {
    bool answer = true;
    
    for(int i=0;i<pb.size();i++){
        phash[pb[i]] = 1;
    }
    for(int i=0;i<pb.size();i++){
        string s= "";
        for(int j=0;j<pb[i].length();j++){
            s += pb[i][j];
            if(phash[s] == 1 && s != pb[i]){
                return false;
            }
        }
    }
    
    return answer;
}