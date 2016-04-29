#include<stdio.h>
//看最多的节目 
void search(int b[100],int e[100],int a){
	int num=1;//记录可看的节目数 
	int esm;
	int i,j,t;
	for(i=0;i<a;i++){
		scanf("%d %d",&b[i],&e[i]);
	}
	for(i=0;i<a-1;i++){//对两个数组排序 
		for(j=0;j<a-1-i;j++){
			if(e[j]>e[j+1]){
		 		t=e[j];
				e[j]=e[j+1];
				e[j+1]=t;
				t=b[j];
				b[j]=b[j+1];
				b[j+1]=t;
			}			
		}
	}
	esm=e[0];
	for(i=1;i<a;i++){		
		if(b[i]>=esm){
			num++;
			esm=e[i];
		}
	}
	printf("%d\n",num);
}
int main(){
	int b[100],e[100];//定义两个数组放开始时间和结束时间 
	int a;// 节目总数 
	scanf("%d",&a);
	while(a!=0){
		search(b,e,a);
		scanf("%d",&a);
	}
	return 0;
}
