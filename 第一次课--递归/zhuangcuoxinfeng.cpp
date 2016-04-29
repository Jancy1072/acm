#include<stdio.h>
//ÐÅ·â×°´í 
int main(){
	__int64 s[21]={0,0,1,2};
	int i=4;
	int a;
	for(;i<21;i++){
		s[i]=s[i-1]*(i-1)+s[i-2]*(i-1);
	}
	while(scanf("%d",&a)!=EOF){
		printf("%I64d\n",s[a]);
	}
	return 0;
} 
