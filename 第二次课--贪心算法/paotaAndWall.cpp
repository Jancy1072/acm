/*由于地图的大小最大为4*4，那么我们就将地图用一个char数组存起来，即map[4][4]。如果map[i][j]='X'则表示地图此处存放的为墙，map[i][j]='.'则表示此处存放的为空地，而map[i][j]='o'则表示此处存放的为炮塔。

关键：炮塔不能同时在水平和垂直线上，除非有墙作为间隔。

我们定义k为位置，k=0即为地图左上方第一个格子。

依次如下所示：

如4*4的地图：

0  1  2  3

4  5 6  7

8  9  10  11

12 13 14 15

那么依次往其中放炮塔，判断两个条件：1.放的位置是否为空地2.同行同列不能够有炮塔，除非有墙间隔（见canput函数）

如果到了k=n*n即终止条件时，看目前的最大炮塔数是否大于bestn最优炮塔数。

这样搜索，即可得到最好的结果。

代码如下：
*/

#include<stdio.h>
//城市的尺寸 
int n;
//城市的地图，最多是4*4
char map[4][4];
//最多放的炮塔数
int bestn;
//看炮塔是否能够放置 
int canput(int row,int col)
{
  int i;
  for(i=row-1;i>=0;i--)
  {
     if(map[i][col]=='X')
     {
         break; 
     } 
     if(map[i][col]=='o')
     {
         return 0; 
     }
  } 
  for(i=col-1;i>=0;i--)
  {
     if(map[row][i]=='X')
     {
        break; 
     }
     if(map[row][i]=='o')
     {
        return 0; 
     }
  }
  return 1;
}
//K表示放置炮塔的位置 
void backtrack(int k,int current)
{
   int x,y;
   if(k>=n*n)
   {
       if(current>bestn)
       {
           bestn=current;
       }
       return;
   }
   else
   {
     x=k/n;
     y=k%n;
     if(map[x][y]=='.'&&canput(x,y))
     {
        map[x][y]='o';
        backtrack(k+1,current+1);
        map[x][y]='.';
     }
     backtrack(k+1,current);
   }
} 
void initial()
{
  int i,j;
  for(i=0;i<4;i++)
  {
      for(j=0;j<4;j++)
      {
          map[i][j]='.';
      } 
  }
}
int main()
{
    scanf("%d",&n);
    while(n)
    {
       int i,j;
       bestn=0; 
       initial();
       for(i=0;i<n;i++)
       {
          for(j=0;j<n;j++)
          {
             char ch;
             ch=getchar();
             if(ch=='\n')
             {
                j--;
                continue; 
             }
             else
             {
                 map[i][j]=ch;
             }
          } 
       }  
       backtrack(0,0);
       printf("%d\n",bestn);
       scanf("%d",&n);
    }
    
    return 0; 
}
