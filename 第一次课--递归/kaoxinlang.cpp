#include<stdio.h>
//Ñ¡ĞÂÀÉ
int main(){
	__int64 s[21]={0,0,1};
	__int64 a[21]={1,1,2};
	int b,c,d;
	__int64 e;
	int i;
	for(i=3;i<21;i++){
		s[i]=s[i-1]*(i-1)+s[i-2]*(i-1);
		a[i]=i*a[i-1];
	}
	scanf("%d",&b);
	while(b--){
		scanf("%d %d",&c,&d);
		e=a[c]/a[d]/a[c-d]*s[d];
		printf("%I64d\n",e);
	}
	return 0;
	
} 
