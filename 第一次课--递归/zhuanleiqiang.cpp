#include<stdio.h>
int main(){
	__int64 s[51]={0,1,2};
	int i,n;
	for(i=3;i<51;i++){
		s[i]=s[i-1]+s[i-2];
	}
	while(scanf("%d",&n)!=EOF){//ÊäÈëCtrl+z³ÌÐò½áÊø 
		printf("%I64d\n",s[n]);
	}
	return 0;
} 
