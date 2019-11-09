#include <string.h>
#include <stdio.h>
int LCS( char *x, char *y, int m, int n );
int max(int,int,int);
int main()
{
	char x[502] = {0} , y[502] = {0};
	int m,n;
	while( scanf( "%s", x ) != EOF && scanf("%s",y) != EOF ) {
		m=strlen(x);
		n=strlen(y);
		printf("%d\n",LCS(x,y,m,n));
	}
	return 0;
}
int LCS( char *x , char *y,int m, int n )
{
	int L[m+1][n+1];
	int i,j;
	
	L[0][0] = 0;
	for( i=0; i<=m; i++ ) {
		for( j=0; j<=n; j++ ) {
			if( i==0 ) 
				L[i][j]=-3*j;	
			if( j==0 )
				L[i][j]=-3*i;		
		}
	}
	for( i=1; i<=m; i++ ) {
		for( j=1; j<=n; j++ ) {
			if(x[i-1] == y[j-1])
				L[i][j] = max(L[i-1][j]-3,L[i][j-1]-3,L[i-1][j-1]+8);
			else
				L[i][j] = max(L[i-1][j]-3,L[i][j-1]-3,L[i-1][j-1]-5);
		}	
	}
	return L[m][n];
}
int max(int a, int b, int c)
{
	if( a>=b && a>=c )
		return a;
	else if( b>=a && b>=c )
		return b;
	else if( c>=a && c>=b )
		return c;	
}
