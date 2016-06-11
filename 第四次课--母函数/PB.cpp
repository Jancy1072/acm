#include<stdio.h>
int main(){
	int a,b,c;
	scanf("%d",&a);
	scanf("%d",&b);
	scanf("%d",&c);
	while(1){
		if(a==0&&b==0&&c==0){
			break;
		}
		if(a==0)printf("1\n");
		else{
			if(a+2*b<4)printf("%d\n",a+2*b+1);
			else{
				printf("%d\n",a+2*b+5*c+1);
			}
		}
	scanf("%d",&a);
	scanf("%d",&b);
	scanf("%d",&c);	
	}
	return 0;
} 
