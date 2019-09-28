#include <bits/stdc++.h>
using namespace std;

struct Edge {
	int to,w;
};
vector<Edge> edge[5004];
int n,m,q;

void init() {
	scanf("%d%d%d",&n,&m,&q);
	for(int i=0; i<n; i++) edge[i].clear();
	for(int i=0; i<m; i++) {
		int a,b,w;
		scanf("%d%d%d",&a,&b,&w);
		edge[a].push_back({b,w});
	}
}
void bellman(int s,int t) {
	int dis[n+5];
	memset(dis,0x3f3f3f3f,sizeof(dis));
	dis[s]=0;
	bool flag=true;
	
	for(int k=0; k<n; k++) {
		for(int i=0; i<n; i++) {
			for(int j=0; j<edge[i].size(); j++) {
				Edge x=edge[i][j];
				if(dis[x.to]>dis[i]+x.w) {
					if(k==n-1&&(t==x.to||t==i)) {
						flag=false;
					}
					dis[x.to]=dis[i]+x.w;
				}
			}
		}
	}
	
	if(!flag||dis[t]==0x3f3f3f3f) printf("no\n");
	else printf("%d\n",dis[t]);
}
void solve() {
	while(q--) {
		int s,t;
		scanf("%d%d",&s,&t);
		bellman(s,t);
	}
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
