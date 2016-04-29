#include<stdio.h>
//非递归求直线分割圆 ,直线数目0<a<50
int main(){
	int s[51]={0,2};//存放所有直线数目对应的的圆的份数 
	int f[51];
	int i,a,b,c;
	for(i=2;i<51;i++){//计算数组s中的所有值 
		s[i]=s[i-1]+i;
	} 
	scanf("%d",&b);//输入b为要查找的直线数目的总数 
	for(i=1;i<=b;i++){
		scanf("%d",&f[i]);	//将要查找的直线数目放在一个数组中 
	}
	for(i=1;i<=b;i++){
		c=f[i];
		printf("%d\n",s[c]);	
	}
	
	return 0;
} 
