#include<stdio.h>
//�����Ľ�Ŀ 
void search(int b[100],int e[100],int a){
	int num=1;//��¼�ɿ��Ľ�Ŀ�� 
	int esm;
	int i,j,t;
	for(i=0;i<a;i++){
		scanf("%d %d",&b[i],&e[i]);
	}
	for(i=0;i<a-1;i++){//�������������� 
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
	int b[100],e[100];//������������ſ�ʼʱ��ͽ���ʱ�� 
	int a;// ��Ŀ���� 
	scanf("%d",&a);
	while(a!=0){
		search(b,e,a);
		scanf("%d",&a);
	}
	return 0;
}
