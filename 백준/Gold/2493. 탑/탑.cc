#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include<set>
#include<cstring>
#include<map>
#include <queue>
#include<climits>
#include<stack>
using namespace std;

int N;
int arr[500001];
int dab[500001];
stack <pair<int ,int> > st;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;
    for(int i=1;i<=N;i++)
        cin>>arr[i];

    for(int i=N; i>=1 ;i--){
        if(st.empty()) st.push({arr[i] , i});
        else{
            if(st.top().first >= arr[i]){
                st.push({arr[i] , i});
            }
            else {
                while(!st.empty() && st.top().first < arr[i]){
                    dab[st.top().second] = i;
                    st.pop();
                }
                st.push({arr[i] , i});
            }
        }
    }
    for(int i=1;i<=N;i++)
        cout<<dab[i]<<" ";
    return 0;
}