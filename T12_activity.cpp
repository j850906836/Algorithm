#include<bits/stdc++.h>
using namespace std;


struct inter{
	int L,R;
};
bool cmp(inter a,inter b){
	return a.R<b.R;
}
int n;
inter a[200200];
void solve(){
	sort(a,a+n,cmp);
	int ans=1;
	int temp=a[0].R;
	for(int i=1;i<n;i++){
		if(a[i].L>=temp){
			temp=a[i].R;
			ans++;
		}
	}
	printf("%d\n",ans);
}
void init(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&a[i].L,&a[i].R);
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
