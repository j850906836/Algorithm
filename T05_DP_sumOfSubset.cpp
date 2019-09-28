#include<bits/stdc++.h>
using namespace std;


int a[200200],b[200200];
int n,m;
void solve(){
	int total=0;
	a[0]=1;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		for(int j=total;j>=0;j--){
			if(a[j]) a[j+x]=1;
		}
		total+=x;
	}
	int ans=0;
	for(int i=0;i<m;i++){
		int y;
		scanf("%d",&y);
		if(a[y]) ans++;
	}
	printf("%d\n",ans);
}
void init(){
	int ncase;
	scanf("%d",&ncase);
	while(ncase--){
		scanf("%d%d",&n,&m);
		memset(a,0,sizeof(a));
		solve();
	}
}
int main(){
	init();
}
