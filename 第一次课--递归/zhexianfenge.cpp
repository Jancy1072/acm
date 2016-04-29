#include<stdio.h>
//非递归求折线分割圆
int main(){
	int a,b,i;
	int s[51]={0,2},f[51];
	scanf("%d",&a);
	for(i=1;i<=a;i++){
		scanf("%d",&f[i]);
	}
	for(i=2;i<=51;i++){
		s[i]=s[i-1]+4*i-3;
	}
	for(i=1;i<=a;i++){
		b=f[i];
		printf("%d\n",s[b]);
	}
	return 0;
} 
