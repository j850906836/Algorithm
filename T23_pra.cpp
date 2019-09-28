#include <bits/stdc++.h>
using namespace std;

struct Edge {
	int a,b,w;
};
Edge edge[10004];
int n,m,k,p[10004];
void init() {
	scanf("%d%d%d",&n,&m,&k); 
	for(int i=0; i<m; i++) {
		scanf("%d%d%d",&edge[i].a,&edge[i].b,&edge[i].w);
	}
	sort(edge,edge+m);
}
bool operator < (Edge a,Edge b) {
	return a.w<b.w;
}
int find(int x) {
	return (x==p[x]) ? x:p[x]=find(p[x]);
}
void uni(int x,int y) {
	p[find(x)]=find(y);
}
void solve() {
	int ans=0;
	for(int i=0; i<n; i++) p[i]=i;
	for(int i=0,j=0; i<n-k&&j<m; i++,j++) {
		while(find(edge[j].a)==find(edge[j].b)) j++;
		uni(edge[j].a,edge[j].b);
		ans+=edge[j].w;
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
