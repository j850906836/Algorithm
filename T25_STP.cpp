#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
struct EDGE{
	int to,w;
};
vector<EDGE> edge[10004];
EDGE path[10004];
int n,m,q;
int dis[10004];
void init(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=0;i<n;i++) edge[i].clear();
	for(int i=0;i<m;i++){
		int a,b,w;
		scanf("%d%d%d",&a,&b,&w);
		edge[a].push_back({b,w});
	}
}
int dijkstra(int s){
	fill(dis,dis+n,0x3f3f3f3f);
	memset(path,0,sizeof(path));
	priority_queue<pii,vector<pii>,greater<pii> > pq;
	dis[s]=0;
	pq.push(pii(0,s));
	while(!pq.empty()){
		pii top=pq.top();
		pq.pop();
		int u=top.second;
		if(dis[u]<top.first) continue;
		for(int i=0;i<edge[u].size();i++){
			EDGE x=edge[u][i];
			if(dis[x.to]>=dis[u]+x.w){
				dis[x.to]=dis[u]+x.w;
				path[x.to].to=u;
				path[x.to].w=x.w;
				pq.push(pii(dis[x.to],x.to));
			}
		}
	}
	int sum=0;
	for(int i=0;i<n;i++){
		sum+=path[i].w;
	}
	return sum;
}
void solve(){
	while(q--){
		int s;
		scanf("%d",&s);
		printf("%d\n",dijkstra(s));
	}
}
int main(){
	int ncase;
	scanf("%d",&ncase);
	while(ncase--){
		init();
		solve();
	}
}
