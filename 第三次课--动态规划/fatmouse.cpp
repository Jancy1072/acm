#include<stdio.h>
#include<algorithm>
using namespace std;
typedef struct{
	int w;//体重 
	int s;//速度 
	int e;//编号 
}Mouse;
bool cmp(Mouse a,Mouse b){
	if(a.w==b.w)return a.s<b.s;//体重相等则按速度排 ，速度从小到大 
	else{
		return a.w>b.w;//体重从大到小 
	}
}
int max(int a,int b){
	return a>b?a:b;
}
int main(){
	int count=-1;
	int i=0;
	int j=0;
	Mouse mouse[1000];

	while(scanf("%d %d",&mouse[i].w,&mouse[i].s)!=EOF){
		mouse[i].e=i+1;
		count++;
		i++;
	}
	sort(mouse,mouse+count+1,cmp);
	int f[1000]={0};
	f[0]=1;
	int big=0;
	for(i=1;i<count;i++){
		big=0;
		for(j=0;j<i;j++){
			if(mouse[i].s>mouse[j].s&&mouse[i].w!=mouse[j].w){	
				big=max(f[j],big);
			}
			 
		}
		f[i]=big+1;
	}
	big=0;
	int bignum=0;
	int bigcount=0;
	for(i=0;i<count;i++){
		if(f[i]>big){
			big=f[i];
			bignum=mouse[i].e;
			bigcount=i;
		}
	}
	printf("%d\n",big);
	printf("%d\n",bignum);
	while(big>0){
		big--;
		for(i=bigcount;i>=0;i--){ 
			if(f[i]==big){
				printf("%d\n",mouse[i].e);
				bigcount=i;
				break;
			}
		}
	}
	return 0;
}
