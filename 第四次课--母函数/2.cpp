#include<stdio.h>
int main(){
	int n;
	int c1[32769];
	int c2[32769];
	int i,j,k;
	for(i=0;i<=32768;i++){
		c1[i]=1;
		c2[i]=0;
	}
	for(i=2;i<=3;i++){ //3ÖÖÓ²±Ò 
		for(j=0;j<=32768;j++){
			for(k=0;k+j<=32768;k=k+i){
				c2[j+k]=c2[j+k]+c1[j];
			}				
		}
		for(j=0;j<=32768;j++){
			c1[j]=c2[j];
			c2[j]=0;	
		}
	}
	while(scanf("%d",&n)!=EOF){
		printf("%d\n",c1[n]);
	}
	return 0;
} 
