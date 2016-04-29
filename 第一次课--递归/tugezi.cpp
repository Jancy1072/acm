#include<stdio.h>
//Í¿¸ñ×Ó 
int main(){
	__int64 s[51]={0,3,6,6};
	int a;
	for(int i=4;i<51;i++){
		s[i]=s[i-1]+s[i-2]*2;
	} 
	while(scanf("%d",&a)!=EOF){
		printf("%I64d\n",s[a]);
	}
	return 0;
} 
