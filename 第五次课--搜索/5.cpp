#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#include<cstdlib>
#include<string>
using namespace std; 
typedef long long ll;
const double pi=acos(-1.0);
char s[120][120];
int a[8]={-1,-1,0,1,1,1,0,-1};
int b[8]={0,1,1,1,0,-1,-1,-1};
void dfs(int i,int j){
	if(i<0 || j<0)
		return;
	if(s[i][j]=='@'){
		s[i][j]='*';
		for(int k=0;k<8;k++)
			dfs(i+a[k],j+b[k]);
	}
}

int main(){
	int m,n;
	while(scanf("%d%d",&m,&n)!=EOF && (m||n)){
		int i,j;
		for(i=0;i<m;i++)
			scanf("%s",s[i]);
		int ans=0;
		for(i=0;i<m;i++){
			for(j=0;j<n;j++){
				if(s[i][j]=='@'){
					ans++;
					dfs(i,j);
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}


 
