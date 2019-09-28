#include<bits/stdc++.h>
#define oo 0x3f3f3f3f
using namespace std;


int no0[2000],no1[2000],ch[2000],n,a[2000];
bool xx[2000];
void solve(){
	if(n==1){
		printf("%d\n",a[0]);
		return ;
	}
	if(n==2){
		printf("%d\n",min(a[0],a[1]));
		return ;
	}
	if(n==3){
		printf("%d\n",min(a[1],a[0]+a[2]));
		return ;
	}
	if(a[0]<a[1]) no0[2]=a[0];
	no1[2]=a[1];
	ch[2]=a[2]+min(a[0],a[1]);
	for(int i=3;i<n-1;i++){
		if(ch[i-1]<=no1[i-1]) no0[i]=oo;
		else no0[i]=no1[i-1];
		no1[i]=ch[i-1];
		ch[i]=min(min(no0[i-1],no1[i-1]),ch[i-1])+a[i];
	}
	no1[n-1]=ch[n-2];
	ch[n-1]=min(min(no0[n-2],no1[n-2]),ch[n-2])+a[n-1];
	printf("%d\n",min(no1[n-1],ch[n-1]));
}
void init(){
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	memset(no0,oo,sizeof(no0));
	memset(no1,oo,sizeof(no1));
	memset(ch,oo,sizeof(ch));
}
int main(){
	while(1){
		init();
		if(n==0) return 0;
		solve();
	}
}
