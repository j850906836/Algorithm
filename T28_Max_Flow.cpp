#include <bits/stdc++.h>
using namespace std;

int n,m,u,v,c;
bool visit[505];
int parent[505];
int rg[505][505];

void init() {
	scanf("%d%d",&n,&m);
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			rg[i][j] = 0;
		}
	}
	for(int i=0; i<m; i++) {
		scanf("%d%d%d",&u,&v,&c);
		rg[u][v]=c;
	}
	memset(parent,-1,sizeof(parent));
}
bool bfs(int s,int t) {
	for(int i=0; i<n; i++) visit[i] = false;

	queue <int> q;
	q.push(s);
	visit[s] = true;
	parent[s] = -1;

	while(!q.empty()) {
		int u = q.front();
		q.pop();

		for(int v=0; v<n; v++) {
			if(visit[v]==false && rg[u][v]>0) {
				q.push(v);
				parent[v] = u;
				visit[v] = true;
			}
		}
	}

	return visit[t];
}
int flow(int s,int t) {
	int maxflow=0;

	while(bfs(s,t)) {
		int pathflow=0x3f3f3f3f;
		for(int i=t; i!=s; i=parent[i]) {
			u=parent[i];
			pathflow = min(pathflow,rg[u][i]);
		}
		for(int i=t; i!=s; i=parent[i]) {
			u=parent[i];
			rg[u][i] -= pathflow;
			rg[i][u] += pathflow;
		}
		maxflow+=pathflow;
	}
	return maxflow;
}	
int main() {
	int ncase;
	scanf("%d",&ncase);
	while(ncase--) {
		init();
		printf("%d\n",flow(0,n-1));
	}
	return 0;
}
