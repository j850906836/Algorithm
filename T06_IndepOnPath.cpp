#include<bits/stdc++.h>
using namespace std;


int n,a[200200],dp1[200200],dp0[200200];
void solve(){
	for(int i=1;i<=n;i++){
		dp0[i]=max(dp0[i-1],dp1[i-1]);
		dp1[i]=dp0[i-1]+a[i];
	}
	printf("%d\n",max(dp0[n],dp1[n]));
}
void init(){
	scanf("%d",&n);
	if(n==0) return ;
	memset(dp1,0,sizeof(dp1));
	memset(dp0,0,sizeof(dp0));
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	dp1[0]=0;
	dp0[0]=0;
	return ;
}
int main(){
	while(1){
		init();
		if(n==0) return 0;
		solve();
	}
}
