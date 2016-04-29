#include<stdio.h>
int main(){
	int a,i;
	__int64 s[41]={0,3,8};
	for(i=3;i<41;i++){
		s[i]=2*s[i-1]+2*s[i-2];
	}
	while(scanf("%d",&a)!=EOF){
		printf("%I64d\n",s[a]);
	}
	return 0;
}
