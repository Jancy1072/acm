#include<stdio.h>
int main(){
	int n;
	int c1[301];
	int c2[301];
	int i,j,k;
	for(i=0;i<=300;i++){
		c1[i]=1;
		c2[i]=0;
	}
	for(i=2;i<=17;i++){ 
		for(j=0;j<=300;j++){
			for(k=0;k+j<=300;k=k+i*i){//每次增加的幅度不一样 
				c2[j+k]=c2[j+k]+c1[j];
			}				
		}
		for(j=0;j<=300;j++){
			c1[j]=c2[j];
			c2[j]=0;	
		}
	}
	scanf("%d",&n);
	while(n!=0){
		printf("%d\n",c1[n]);
		scanf("%d",&n);
	}
	return 0;
} 
