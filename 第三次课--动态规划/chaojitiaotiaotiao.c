#include<stdio.h>
//���������� 
int max(int a,int b){
	return a>b?a:b;
}
int main(){
	int i,j;
	int b;
	int temp;
	scanf("%d",&b);
	__int32 a[1001]; 
	while(b!=0){//��Ȧ����Ŀ 
		for(i=0;i<b;i++)scanf("%I32d",&a[i]);
		__int32 f[1001];
		f[0]=a[0];
		for(i=1;i<b;i++){
			f[i]=a[i];
			temp=0;
			for(j=0;j<i;j++){//���û��a[j]<a[i]��tempΪ0		
				if(a[j]<a[i]){
					if(f[j]+a[i]>f[i])f[i]=f[j]+a[i];				
				}					
			}
		}
		int Max=f[0];
		for(i=1;i<b;i++){
			Max=max(Max,f[i]);
		}
		printf("%d\n",Max);
		scanf("%d",&b);
	}
	return 0;
}
