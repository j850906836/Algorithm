#include<bits/stdc++.h>
using namespace std;


struct inter{
	int left,right,w;
};
bool cmp(inter a,inter b){
	return a.right < b.right;
}
inter a[100100];
int n;
int dp[100100];
int binary(int x){
	int ll=0,lr=x,mid;
	while(lr-ll>1){
		mid=(lr+ll)/2;
		if(a[mid].right>a[x].left) lr=mid;
		else ll=mid;
	}
	if(a[lr].right>a[x].left) return dp[ll];
	return dp[lr];
}
void solve(){
	sort(a+1,a+n+1,cmp);
	dp[0]=0;
	for(int i=1;i<=n;i++){
		dp[i]=max(dp[i-1],a[i].w+binary(i));
	}
	printf("%d\n",dp[n]);
}
void init(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i].left,&a[i].right,&a[i].w);
	}
	return ;
}
int main(){
	int ncase;
	scanf("%d",&ncase);
	while(ncase--){
		init();
		solve();
	}
}
