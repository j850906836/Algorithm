#include<bits/stdc++.h>
using namespace std;


int l,n;
int dp[2000][2000];
int a[2000];
int cut(int x,int y){
	int cost=0x3f3f3f3f;
	if(dp[x][y]) return dp[x][y];
	if(y-x==2) return dp[x][y]=a[y]-a[x];
	if(y-x<2) return 0;
	for(int i=x+1;i<y;i++){
		cost=min(cost,a[y]-a[x]+cut(x,i)+cut(i,y));
	}
	return dp[x][y]=cost;
}
void solve(){
	if(l==0) return ;
	printf("The minimum cutting is %d.\n",cut(0,n+1));
}
void init(){
	scanf("%d",&l);
	if(l==0) return ;
	scanf("%d",&n);
	memset(dp,0,sizeof(dp));
	a[0]=0;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	a[n+1]=l;
	return ;
}
int main(){
	while(1){
		init();
		if(l==0) return 0;
		solve();
	}
	return 0;
}
