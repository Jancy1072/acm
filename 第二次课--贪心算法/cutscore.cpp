#include<stdio.h>
#include<string.h>
#define max 1005
/*
    ����̰��ˮ�⣬��Ҳ������ˮƽ����Ŀ����ˮƽ̫�ˡ�
    �������˼·����ȻҪ�������ٿ۶��ٷ֣�����ǰ����
    ���Ǳ�ȻҪ�Ȱѳ������ʱ��۷�������ҵ�Ȱ�����
    ����۷�һ����Ļ����Ǳ�ȻҪ��ʱ��ȽϽ����Ȱ���
    ��.�����Ȱ��۷ֵĸߵͣ��ɸ��������������ſ�
    �۷���ͬ�Ͱ����ǵĽ���ʱ���е��������!Ȼ��ѡ�񼴿ɣ� 
*/
struct he
{
         int time;
         int score;
};
bool f[max];
int main()
{
         int t,n,i,min,j;
         he student[max],temp;
         scanf("%d",&t);
         while(t--)
         {
                   scanf("%d",&n);
                   for(i=0;i<n;i++)
                            scanf("%d",&student[i].time);
                   for(i=0;i<n;i++)
                            scanf("%d",&student[i].score);
                   min=0;
                   memset(f,0,sizeof(f));
                   for(i=0;i<n;i++)
                            for(j=i+1;j<n;j++)
                            {
                                     if(student[j].score>student[i].score)
                                     { temp=student[j];student[j]=student[i];student[i]=temp; }
                                     else if(student[j].score==student[i].score && student[j].time<student[i].time)
                                     { temp=student[j];student[j]=student[i];student[i]=temp; }
                            }
                   for(i=0;i<n;i++)
                   {
                            for(j=student[i].time;j>0;j--)
                            {
                                     if(f[j]==false)
                                     {
                                               f[j]=true;
                                               break;
                                     }
                            }
                            if(j==0)
                            min+=student[i].score;
                   }
                   printf("%d\n",min);
         }
         return 0;
}
