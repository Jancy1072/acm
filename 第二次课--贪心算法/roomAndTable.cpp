#include<stdio.h>
//���ȡ������� 
void search(int b){
	int i,t,f,j;
	int temp;
	int s[200]={0};
	for(i=0;i<b;i++){
		scanf("%d %d",&t,&f);
		if(t>f){//��֤t<f 
			temp=t;
			t=f;
			f=temp;
		}
		for(j=(t-1)/2;j<=(f-1)/2;j++){//��¼�ص����� ������Ŷ�Ӧ�����ȶ��� 
			s[j]++;
		}
	}
	int max=s[0];
	for(i=1;i<200;i++){		//������ص��� 
		if(s[i]>max){
			max=s[i];
		}
	}
	printf("%d\n",max*10);
}
int main(){
	int a,i,b;
	scanf("%d",&a);
	for(i=0;i<a;i++){
		scanf("%d",&b);
		search(b);
	}	
	return 0;
}
