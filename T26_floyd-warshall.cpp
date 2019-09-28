#include<bits/stdc++.h>
using namespace std;


int n,m;
int adj[1004][1004];
void init(){
	scanf("%d%d",&n,&m);
	memset(adj,0x3f3f3f3f,sizeof(adj));
	for(int i=0;i<m;i++){
		int a,b,w;
		scanf("%d%d%d",&a,&b,&w);
		adj[a][b]=w;
	}
	for(int i=0;i<n;i++){
		adj[i][i]=0;
	}
}
void floyd_warshall(){
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(adj[i][j]>adj[i][k]+adj[k][j]){
					adj[i][j]=adj[i][k]+adj[k][j];
				}
			}
		}
	}
}
int center_point(){
	int mini=0x3f3f3f3f;
	int ans;
	for(int i=0;i<n;i++){
		int sum=0;
		int j;
		for(j=0;j<n;j++){
			if(adj[i][j]==0x3f3f3f3f) break;
			sum+=adj[i][j];
		}
		if(j==n && sum<mini){
			mini=sum;
			ans=i;
		}
	}
	return ans;
}
void solve(){
	floyd_warshall();
	printf("%d\n",center_point());
}
int main(){
	int ncase;
	scanf("%d",&ncase);
	while(ncase--){
		init();
		solve();
	}

