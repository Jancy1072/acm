#include<stdio.h>
#include<string.h>
//泛化的最长公共子序列，不需要连续。 
int max(int a,int b){
	return a>b?a:b;
}
int main(){
	char s1[700];
	char s2[700];
	int f[700][700]={
		0
	};
	while(scanf("%s%s",s1,s2)!=EOF){
		int m=strlen(s1);
		int n=strlen(s2);
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(s1[i]==s2[j]){
					f[i+1][j+1]=f[i][j]+1;
				}else{
					f[i+1][j+1]=max(f[i][j+1],f[i+1][j]);
				}	
			}
		}
		int max=0;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(f[i+1][j+1]>max){
					max=f[i+1][j+1];
				}
			}
		}	
		printf("%d\n",max);
	}
	return 0;
}
