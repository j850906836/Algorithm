#include <bits/stdc++.h>
using namespace std;

int adj[1004][1004];
int n,m;

void init() {
	memset(adj,0x3f3f3f3f,sizeof(adj));
	scanf("%d%d",&n,&m);
	for(int i=0; i<m; i++) {
		int a,b,w;
		scanf("%d%d%d",&a,&b,&w);
		adj[a][b]=w;
	}
	for(int i=0; i<n; i++) {
		adj[i][i]=0;
	}
}
void floyd() {
	for(int k=0; k<n; k++) {
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				if(adj[i][j]>adj[i][k]+adj[k][j]) {
					adj[i][j]=adj[i][k]+adj[k][j];
				}
			}
		}
	}
}
int center() {
	int mini=0x3f3f3f3f;
	int ans;
	for(int i=0; i<n; i++) {
		int sum=0,j;
		for(int j=0; j<n; j++) {
			if(adj[i][j]==0x3f3f3f3f) break;
			sum+=adj[i][j];
		}
		if(j==n&&sum<mini) {
			mini=sum;
			ans=i;
		}
	}
	return ans;
}
void solve() {
	floyd();
	printf("%d\n",center());
}
int main() {
	int ncase;
	scanf("%d",&ncase);
	while(ncase--) {
		init();
		solve();
	}
	return 0;
}
