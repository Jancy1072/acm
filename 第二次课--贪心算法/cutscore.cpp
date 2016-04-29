#include<stdio.h>
#include<string.h>
#define max 1005
/*
    又是贪心水题，我也想做有水平的题目无奈水平太菜。
    此题大致思路，既然要计算最少扣多少分，就眼前利益
    考虑必然要先把超过最后时间扣分最多的作业先安排了
    如果扣分一样多的话，那必然要把时间比较紧的先安排
    了.所以先按扣分的高低，由高向低排序，如果两门课
    扣分相同就按他们的结束时间有低向高排序!然后选择即可！ 
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
