#include<bits/stdc++.h>
using namespace std;

pair<int,int> a[200200];
int dp[504][100004];
int n,w;
int kna(int x,int sum){
	if(sum<0) return -1e9;
	if(x==0) return 0;
	if(dp[x][sum]) return dp[x][sum];
	return dp[x][sum]=max(kna(x-1,sum-a[x].first)+a[x].second,kna(x-1,sum));
}
void solve(){
	printf("%d\n",kna(n,w));
}
void init(){
	scanf("%d",&n);
	if(n==0) return ;
	scanf("%d",&w);
	for(int i=1;i<=n;i++) scanf("%d%d",&a[i].first,&a[i].second);
	memset(dp,0,sizeof(dp));
}
int main(){
	while(1){
		init();
		if(n==0) return 0;
		solve();
	}
}
