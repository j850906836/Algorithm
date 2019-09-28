#include<bits/stdc++.h>
using namespace std;

int x,y,m;
vector<int> edge[1004];
int match[1004];
bool used[1004];
void init(){
	scanf("%d%d%d",&x,&y,&m);
	for(int i=0;i<(x+y);i++) edge[i].clear();
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		b+=x;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
}
bool dfs(int v){
	used[v]=true;
	for(int i=0;i<edge[v].size();i++){
		int u=edge[v][i];
		int w=match[u];
		if(w<0 || (!used[w] && dfs(w))){
			match[v]=u;
			match[u]=v;
			return true;
		}
	}
	return false;
}
int bipartite_matching(){
	int res=0;
	memset(match,-1,sizeof(match));
	for(int i=0;i<(x+y);i++){
		if(match[i]==-1){
			memset(used,false,sizeof(used));
			if(dfs(i)) res++;
		}
	}
	return res;
}
void solve(){
	printf("%d\n",bipartite_matching());
}
int main(){
	int ncase;
	scanf("%d",&ncase);
	while(ncase--){
		init();
		solve();
	}
}
