#include<stdio.h>
//һֻС�۷� 
int main(){
	__int64 s[51]={1,1,2};
	int a,b,c;
	int i=3;
	for(;i<51;i++){
		s[i]=s[i-1]+s[i-2];
	}
	scanf("%d",&a);
	while(a--){
		scanf("%d %d",&b,&c);
		printf("%I64d\n",s[c-b]);
	}
	return 0;
}
