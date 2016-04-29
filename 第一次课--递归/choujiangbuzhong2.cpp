#include<stdio.h>
int main()
{
     int i,n,T;
     double a[21]={0,0,1};
     double b[21]={1,1,2};//定义为double型就不需使用long long，同时输出不需要转换类型
     for(i=3;i<=20;++i)
     {
         a[i]=(a[i-1]+a[i-2])*(i-1); //错排公式--不懂的可以参考信封装错的那题
         b[i]=b[i-1]*i;
     }
     scanf("%d",&T);
     while(T--)
     {
         scanf("%d",&n);
         printf("%.2lf%%\n",a[n]/b[n]*100);
     }
     return 0;
}
