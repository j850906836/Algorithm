#include <bits/stdc++.h>
using namespace std;

vector<int> edge[1004];
int x,y,m;
int match[1004];
bool visit[1004];
void init() {
	scanf("%d%d%d",&x,&y,&m);
	for(int i=0; i<(x+y); i++) edge[i].clear();
	for(int i=0; i<m; i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		b+=x;
		edge[a].push_back(a);
		edge[b].push_back(b);
	}
}
bool dfs(int v) {
	visit[v]=true;
	for(int i=0; i<edge[v].size(); i++) {
		int u=edge[v][i];
		int w=match[u];
		if(w<0&&(!visit[w]||dfs(w))) {
			match[u]=v;
			match[v]=u;
			return true;
		}
	}
	return false;
}
void solve() {
	int ans=0;
	memset(match,-1,sizeof(match));	
	for(int i=0; i<(x+y); i++) {
		if(match[i]==-1) {
			memset(visit,false,sizeof(visit));
			if(dfs(i)) ans++;
		}
	}
	printf("%d\n",ans);
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
