#include <bits/stdc++.h>
using namespace std;

typedef unsigned int lint;
lint n,m,k;
lint t[104];
lint value[5004];
vector<lint> edge[5004];
bool visit[5004];
lint maxi;

void init() {
	scanf("%u %u %u",&n,&m,&k);
	for(int i=0; i<n; i++) edge[i].clear();
	for(int i=0; i<k; i++) scanf("%u",&t[i]);
	for(int i=0; i<n; i++) scanf("%u",&value[i]);
	for(int i=0; i<m; i++) {
		lint a,b;
		scanf("%u%u",&a,&b);
		edge[a].push_back(b);
	}
}
void dfs(int a) {
	if(visit[a]) return;
	visit[a]=true;
	maxi=max(maxi,value[a]);
	for(int i=0; i<edge[a].size();i++) dfs(edge[a][i]);
}
void solve() {
	maxi=0;
	for(int i=0; i<k; i++) {
		memset(visit,false,sizeof(visit));
		dfs(t[i]);
	}
	printf("%u\n",maxi);
}
int main() {
	while(1) {
		init();
		if(n==0) return 0;
		solve();
	}
	return 0;
}
