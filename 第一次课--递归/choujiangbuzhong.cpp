#include<stdio.h>
int main(){
	__int64 s[21]={0,0,1,2};
	int a,c,i,t;
	float b;
	__int64 sum;
	for(i=4;i<21;i++){
		s[i]=s[i-1]*(i-1)+s[i-2]*(i-1);
	}
	scanf("%d",&a);
	for(i=1;i<=a;i++){
		sum=1;
		scanf("%d",&c);
		t=c;
		while(t!=0){
			sum*=t;
			t--;
		}
		b=(float)s[c]/sum;
		b=b*100;
		printf("%.2f",b);
		printf("%%\n");
	}
	return 0;
} 
