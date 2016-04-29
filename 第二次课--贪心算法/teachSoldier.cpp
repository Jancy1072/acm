#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
// 有n个士兵每个人有一个水平值，水平高的的人可以教低的人，意思就是求最少的扫帚，那么我们只要知道找到最大重复元素的次数即可，因为相同的人肯定不能共用一个，所以求得最少即为最大的重复次数
//注意：前置的0必须要去掉，例如数据
//直接排序找最长平台(贪心算法)
int main()
{
      int n,i,max,t;
      int a[3005];
      while(scanf("%d",&n)!=EOF)
      {
          for(i=0;i<n;++i)
              scanf("%d",&a[i]);
          sort(a,a+n);
          max=1;
          t=1;
          for(i=1;i<n;++i)
          {
              if(a[i]!=a[i-1])
                  t=1;
              else 
                  ++t;
              if(t>max)
                  max=t;
          }
          printf("%d\n",max);
      }
	return 0;
}
