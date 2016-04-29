#include<stdio.h>
#include<iostream>
using namespace std;
int max(int a,int b){
	return a>b?a:b;
}
int main(){
	int a,b,t=0;
	int c[100000];
	int f[100000];
	int p[100000];
	cin>>a;
	while(a--){
		t++;
		cin>>b;
		for(int i=0;i<b;i++){
			cin>>c[i];
			p[i]=i;
		}
		f[0]=c[0];
		for(int i=1;i<b;i++){
			f[i]=max(c[i],f[i-1]+c[i]);
			if(f[i]==c[i])p[i]=i;
			if(f[i]==c[i]+f[i-1])p[i]=p[i-1];
		}
		int Max=f[0];
		int s=p[0];
		int e=0;
		for(int i=1;i<b;i++){
			if(Max<f[i]){
				Max=f[i];
				s=p[i];
				e=i;
			}	
		}
		cout<<"Case "<<t<<":"<<endl<<Max<<" "<<s+1<<" "<<e+1<<endl;
		if(a)cout<<endl;//题目要求两个case之间要有空行 
	}
	return 0;
} 
