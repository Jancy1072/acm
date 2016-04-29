#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
//紫君 
using namespace std;

#define Max 1000

struct room{
	double j,f;
	double rate;
}Room[Max];

bool cmp(room a,room b)
{
	return a.rate>b.rate;
}


int main()
{
	int N;//房间数
	double M,sumJ;//M 猫粮，sumJ 总共最多能获得的JavaBeans
	int i;
	while(scanf("%lf %d",&M,&N))
	{
		if(M==-1&&N==-1)
			break;
		for(i=0;i<N;i++)
		{
			scanf("%lf%lf",&Room[i].j,&Room[i].f);
			Room[i].rate=(double)Room[i].j/Room[i].f;
		}
		sort(Room,Room+N,cmp);// 根据rate由大到小排序
		sumJ=0;
		for(i=0;i<N;i++)
		{
			if(M>=Room[i].f)
			{
				sumJ+=Room[i].j;
				M-=Room[i].f;
			}
			else
			{
				sumJ+=(Room[i].rate)*M;
				break;
			}
		}
		printf("%.3lf\n",sumJ);
	}
	return 0;
}







			

