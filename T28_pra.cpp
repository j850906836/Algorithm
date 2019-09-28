#include <bits/stdc++.h>
using namespace std;
int parent[505];
int graph[505][505];
bool visit[505];
int n,m,u,v,c;

void init() {
	scanf("%d%d",&n,&m);
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			graph[i][j]=0;
		}
	}
	for(int i=0; i<m; i++) {
		scanf("%d%d%d",&u,&v,&c);
		graph[u][v]=c;
	}
	memset(parent,-1,sizeof(parent));
}
bool bfs(int s, int t) {
	for(int i=0; i<n; i++) visit[i]=false;
	
	queue<int> q;
	q.push(s);
	visit[s]=true;
	parent[s] = -1;
	while(!q.empty()) {
		u = q.front();	
		q.pop();
		for(int v=0; v<n; v++) {
			if(!visit[v] && graph[u][v]>0) {
				visit[v]=true;
				parent[v]=u;
				q.push(v);
			}
		}
	}
	return visit[t];
}
int ford(int s,int t) {
	int maxflow=0;

	while(bfs(s,t)) {
		int pathflow=0x3f3f3f3f;

		for(int i=t; i!=s; i=parent[i]) {
			u=parent[i];
			pathflow=min(pathflow,graph[u][i]);
		}
		for(int i=t; i!=s; i=parent[i]) {
			u=parent[i];
			graph[u][i] -= pathflow;
			graph[i][u] += pathflow;
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
		printf("%d\n",ford(0,n-1));
	}
	return 0;
}
