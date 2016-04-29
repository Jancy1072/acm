#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
//Ìï¼ÉÈüÂí
bool ran(int a,int b){
	return a<b;
}
int main(){
	int a,i;
	int king[1000];
	int tj[1000];
	while(true){
		scanf("%d",&a);
		if(a==0)break;
		for(i=0;i<a;i++){
			cin>>tj[i];
		}
		for(i=0;i<a;i++){
			cin>>king[i];
		}
		sort(tj,tj+a,ran);
		sort(king,king+a,ran);
		int king_min=0;
		int king_max=a-1;
		int tj_min=0;
		int tj_max=a-1;
		int money=0;
		while(tj_min<=tj_max){
			if(tj[tj_min]>king[king_min]){
				money+=200;
				tj_min++;
				king_min++;
			}else if(tj[tj_max]>king[king_max]){
				money+=200;
				tj_max--;
				king_max--;
			}else{
				if(tj[tj_min]<king[king_max]){
					money-=200;
					tj_min++;
					king_max--;
				}else{
					break;
				}
				
			}
		}
		printf("%d\n",money);		
	}

} 
