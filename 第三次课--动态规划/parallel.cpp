#include<stdio.h>
int main()
{
	int i,n,st[21][200],j,k;
    for(i=1;i<=20;i++)
  		for(j=0;j<=200;j++)
   			st[i][j]=0;
  	st[0][0]=1;
	st[1][0]=1;
  	st[2][0]=1;
  	st[2][1]=1;
  	for(i=3;i<=20;i++)
   		for(j=0;j<i;j++)
    		for(k=0;k<=(j-1)*j/2;k++)
     			if(st[j][k]==1)
      				st[i][k+j*(i-j)]=1;
     while(scanf("%d",&n)!=EOF)
     {       
      printf("0");
      for(i=1;i<=(n-1)*n/2;i++)
       	if(st[n][i]==1)
        	printf(" %d",i);
       	printf("\n");
     }
     return 0;
}
/*
思考方法：
容易列举出N=1,2,3的情况：
0
0，1
0，2，3
如果已知<N的情况，我们来分析加入第N条直线的情况(这里N=4)：
1、第四条与其余直线全部平行 => 无交点；
2、第四条与其中两条平行，交点数为(n-1)*1+0=3;
3、第四条与其中一条平行，这两条平行直线和另外两点直线的交点数为(n-2)*2=4,而另外两条直线既可能平行也可能相交，因此可能交点数为：
（n-2）*2+0=4 或者 (n-2)*2+1=5
4、 第四条直线不与任何一条直线平行，交点数为：
(n-3)*3+0=3 或者 (n-3)*3+2=5 或者 (n-3)*3+3=6
即n=4时，有0个，3个，4个，5个，6个不同交点数。
从上述n=4的分析过程中，我们发现：

m条直线的交点方案数

=（m-r）条平行线与r条直线交叉的交点数 + r条直线本身的交点方案

=（m-r）*r+r条之间本身的交点方案数（1<=r<=m）
*/
