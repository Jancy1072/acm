#include<stdio.h>
//递归求直线分割圆 
int g(int k){
	if(k==1)return 2;
	return g(k-1)+k;
}
int main(){
	int a,i,c;
	int f[51];
	scanf("%d",&a);
	for(i=1;i<=a;i++){
		scanf("%d",&f[i]);
	} 
	for(i=1;i<=a;i++){
		c=g(f[i]);
		printf("%d\n",c);
	}
	return 0;
} 
