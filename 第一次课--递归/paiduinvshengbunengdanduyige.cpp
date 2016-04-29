#include<stdio.h>
//排队女生不能单独一个 
int main(){
	int s[1001][101]={0};
	int i,n,j;
	s[1][1]=1;
	s[2][1]=2;
	s[3][1]=4;
	s[4][1]=7;
	for(i=5;i<1001;i++){
		for(j=1;j<101;j++){
			s[i][j]+=s[i-1][j]+s[i-2][j]+s[i-4][j];
			s[i][j+1]+=s[i][j]/10000;//保存进位 
			s[i][j]=s[i][j]%10000;
		}
	}
	while(scanf("%d",&n)!=EOF){
		int k=100;
		while(!s[n][k--]);
		printf("%d",s[n][k+1]);
		for(;k>0;k--)
			printf("%04d",s[n][k]);
		printf("\n");
	}
	return 0;
} 
