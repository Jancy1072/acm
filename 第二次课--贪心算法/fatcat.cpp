#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
//sort函数所在文件，源程序要保存为cpp格式 
using namespace std;

struct cat{
	double JavaBean; 
	double catFood;//猫粮 
	double quto;
};
bool cmp(cat a,cat b){
	return a.quto>b.quto;
}
void calculate (double sum,int num){
	struct cat Cat[1000];
	double x,y;
	int i;
	double get=0;
	int count=0;
	for(i=0;i<num;i++){
		scanf("%lf %lf",&x,&y);
		if(y==0){
			get+=x;
		}else{
			Cat[count].JavaBean=x;
			Cat[count].catFood=y;
			Cat[count].quto=(double)x/y;
			count++;
		}		
	} 
	sort(Cat,Cat+count,cmp);
	for(i=0;i<count;i++){
		if(sum>=Cat[i].catFood){
			sum=sum-Cat[i].catFood;
			get+=Cat[i].JavaBean;
		}else{	
			get+=(Cat[i].quto)*sum;		
			break;
		}
	}
	printf("%.3lf\n",get);
}
int main(){
	int num;
	double sum;
	scanf("%lf %d",&sum,&num);
	while(sum!=-1||num!=-1){
		calculate(sum,num);
		scanf("%lf %d",&sum,&num);
	} 
	return 0;
}
