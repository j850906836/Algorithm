#include <bits/stdc++.h>
using namespace std;

int n,m;
int u,v,c;
bool visit[505];
int parent[505];
int g[505][505];
int rg[505][505];

void init(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			g[i][j]=0;
			rg[i][j]=0;
		}
	}
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&u,&v,&c);
		g[u][v]=c;
	}
	memset(parent,-1,sizeof(parent));
}

bool bfs(int s,int t){
	for(int i=0;i<n;i++){
		visit[i]=false;
	}
//	memset(visit,false,sizeof(visit));
	queue <int> q;
    q.push(s);
    visit[s] = true;
    parent[s] = -1;

   // Standard BFS Loop
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
 
        for (int v=0; v<n; v++)
        {
            if (visit[v]==false && rg[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visit[v] = true;
            }
        }
    }
    // If we reached sink in BFS starting from source, then return
    // true, else false
    return (visit[t] == true);	
}


int ford(int s,int t){
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			rg[i][j]=g[i][j];
		}
	}
	int maxflow=0;
	
	while(bfs(s,t)){
		int pathflow=INT_MAX;
		for (int i=t; i!=s; i=parent[i])
        {
            u = parent[i];
            pathflow = min(pathflow, rg[u][i]);
        }
 
        // update residual capacities of the edges and reverse edges
        // along the path
        for (int i=t; i != s; i=parent[i])
        {
            u = parent[i];
            rg[u][i] -= pathflow;
            rg[i][u] += pathflow;
        }
 
        // Add path flow to overall flow
        maxflow += pathflow;
		
	}
	return maxflow;
}
int main(){
	int ncase;
	scanf("%d",&ncase);
	while(ncase--){
		init();
		printf("%d\n",ford(0,n-1));
	}
	return 0;
}
