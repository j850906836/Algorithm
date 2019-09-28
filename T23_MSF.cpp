#include <bits/stdc++.h>
using namespace std;

struct Edge {
	int a, b, w;
};

Edge e[500004];
int n, m, p[10004];

int find(int x) {
	return (x == p[x])? x : (p[x] = find(p[x]));
}

void uni(int x, int y) {
	p[find(x)] = find(y);
}

void kruskal() {
	int ans = 0;
	for (int i = 0; i < n; ++i)
		p[i] = i;
	for (int i = 0, j = 0; i < n - k && j < m; ++i, ++j) {
		while (find(e[j].a) == find(e[j].b))
			++j;
		uni(e[j].a, e[j].b);
		ans += e[j].w;
	}
	printf("%d\n", ans);
}

bool operator<(Edge a, Edge b) {
	return a.w < b.w;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n,&m);
		for (int i = 0; i < m; ++i)
			scanf("%d%d%d", &e[i].a,&e[i].b,&e[i].w);
		sort(e, e + m);
		kruskal();
	}
	return 0;
}
