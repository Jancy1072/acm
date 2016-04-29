#include<stdio.h>
//公式求直线分割圆 
int main(){
	int a,i,c,result;
	scanf("%d",&a);
	int f[51];
	for(i=1;i<=a;i++){
		scanf("%d",&f[i]);
	} 
	for(i=1;i<=a;i++){
		c=f[i];
		result=c*(c+1)/2+1;
		printf("%d\n",result);
	}
	return 0;
	
}
