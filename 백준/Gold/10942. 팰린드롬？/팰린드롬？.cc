#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<deque>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<functional>
#include<climits>
using namespace std;

int N,M;
int arr[2000];
int dp[2000][2000];

int topdown(int l, int r){
	if(l >= r){
		if(l==r) dp[l][r] =1;
		return 1;
	}
	if(dp[l][r]!= -1) return dp[l][r];

	dp[l][r]=0;
	if(arr[l] == arr[r]) dp[l][r] = topdown(l+1,r-1);
	return dp[l][r];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>N;
	for(int i=0;i<N;i++){
		cin>>arr[i];
	}
	cin>>M;
	memset(dp,-1,sizeof(dp));
	int a,b;
	for(int i=0;i<M;i++){
		cin>>a>>b;
		if(dp[a-1][b-1]!= -1)cout<<dp[a-1][b-1]<<"\n";
		else cout<<topdown(a-1,b-1)<<"\n";
	}
	/*for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<"\n";
	}*/
}