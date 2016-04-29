#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
//�Ͼ� 
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
	int N;//������
	double M,sumJ;//M è����sumJ �ܹ�����ܻ�õ�JavaBeans
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
		sort(Room,Room+N,cmp);// ����rate�ɴ�С����
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







			

