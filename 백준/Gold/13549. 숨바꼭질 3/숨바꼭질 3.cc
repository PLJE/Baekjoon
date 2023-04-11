#include<iostream>
#include<vector>
#include<cmath>
#include<string>
#include<queue>
#include<cstring>
#include<bitset>
#include<algorithm>
#include<map>
#include<climits>
#include<set>
using namespace std;

int N,K;
int visit[100001][4];
int range(int x ,int k){
	if(x>=0 && x<=100000 && !visit[x][k]) return 1;
	return 0;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>N>>K;
	priority_queue <pair<int,int>> q;
	q.push({-0 ,N});
	visit[N][1] = 1;
	visit[N][2] = 1;
	visit[N][3] = 1;

	while(!q.empty()){
		int cnt = -q.top().first;
		int cur = q.top().second;
		q.pop();

		if(cur == K){
			cout<<cnt;
			return 0;
		}

		if (range(cur * 2 , 1)) {
			visit[cur * 2][1] = 1;
			q.push({ -cnt , cur * 2 });
		}
		if(range(cur+1 ,2)){
			visit[cur+1][2]=1;
			q.push({ -(cnt+1), cur+1 });
		}
		if (range(cur - 1 ,3 )) {
			visit[cur - 1][3] = 1;
			q.push({ -(cnt + 1), cur-1 });
		}
	}
}
