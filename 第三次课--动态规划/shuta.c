#include<stdio.h>
//ÊýËþÎÊÌâ 
int max(int a,int b){
	return a>b?a:b;
}
int main(){
	int a,b;
	int i,j,k;
	scanf("%d",&a);
	while(a!=0){
		scanf("%d",&b);
		int arr[b][b];
		for(j=0;j<b;j++){
			for(k=0;k<j+1;k++){
				scanf("%d",&arr[j][k]);
			}			
		}
		for(i=b-2;i>=0;i--){
			for(j=0;j<i+1;j++){
				arr[i][j]+=max(arr[i+1][j],arr[i+1][j+1]);
			}
		}
		printf("%d\n",arr[0][0]);
		a--;
	}
	return 0;
}
