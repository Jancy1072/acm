#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
// ��n��ʿ��ÿ������һ��ˮƽֵ��ˮƽ�ߵĵ��˿��Խ̵͵��ˣ���˼���������ٵ�ɨ�㣬��ô����ֻҪ֪���ҵ�����ظ�Ԫ�صĴ������ɣ���Ϊ��ͬ���˿϶����ܹ���һ��������������ټ�Ϊ�����ظ�����
//ע�⣺ǰ�õ�0����Ҫȥ������������
//ֱ���������ƽ̨(̰���㷨)
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
