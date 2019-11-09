#include <bits/stdc++.h>
using namespace std;
int LCS( char *x, char *y, int m, int n );
int max(int,int);
int main()
{
	char x[502] = {0} , y[502] = {0};
	int m,n;
	while( scanf("%s",x)!=EOF && scanf("%s",y)!=EOF  ) {
		m=strlen(x);
		n=strlen(y);
		cout<<LCS(x,y,m,n)<<endl;
	}
	return 0;
}
int LCS( char *x , char *y,int m, int n )
{
	int L[m+1][n+1];
	int i,j;
	for( i=0; i<=m; i++ ){
		for( j=0; j<=n; j++ ) {
			if( i==0||j==0 )
				L[i][j]=0;
			else if( x[i-1] == y[j-1] )
				L[i][j] = L[i-1][j-1]+1;
			else
				L[i][j] = max(L[i-1][j],L[i][j-1]);
			}
		}
		return L[m][n];		
}
int max(int a, int b)
{
	return (a>b)? a : b;
}
