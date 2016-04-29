#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

struct cat{
	double JavaBean;
	double catFood;
	double quto;
};
bool cmp(room a,room b){
	return a.quto>b.quto;
}
int calculate (int sum,int num){
	struct cat Cat[1000];
	int i,x,y,z;
	int u,v;
	double w;
	double get=0;
	for(i=0;i<num;i++){
		scanf("%d %d",&x,&y);
		if(y==0){
			get+=x;
		}else{
			Cat[i].JavaBean=x;
			Cat[i].catFood=y;
			Cat[i].quto=(double)x/y;
		}		
	} 
	sort(Cat,Cat+1000,cmp);
	for(i=0;i<num;i++){
		if(sum>=Cat[i].catFood){
			sum=sum-Cat[i].catFood;
			get+=Cat[i].JavaBean;
		}else{	
			get+=Cat[i].quto*sum;
			break;
		}
	}
	printf("%.3f\n",get);
}
int main(){
	int sum,num;
	scanf("%d %d",&sum,&num);
	while(sum!=-1&&num!=-1){
		calculate(sum,num);
		scanf("%d %d",&sum,&num);
	} 
	return 0;
}
