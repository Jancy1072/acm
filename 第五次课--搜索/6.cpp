#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int n,m;
int d[4][2]={-1,0,1,0,0,-1,0,1};
char str[210][210];
struct point{//自定义最小优先队列
	int x,y,time;
	friend bool operator<(point a,point b)
	{
 	 	return a.time>b.time;
	}
};
int bfs(point start)
{
   priority_queue<point> q;
   q.push(start);
   point now,next;
   int i;
   while(!q.empty())
   {
    now=q.top();
    q.pop();
    for(i=0;i<4;i++)
    {
     next.x=now.x+d[i][0];
     next.y=now.y+d[i][1];
     if(str[next.x][next.y]=='r')
     {
      next.time=now.time+1;
      while(!q.empty())
       q.pop();
      return next.time;
     }
     if(next.x>=0&&next.y>=0&&next.x<n&&next.y<m&&str[next.x][next.y]!='#')
     {
      if(str[next.x][next.y]=='x')
      {
       str[next.x][next.y]='#';
       next.time=now.time+2;
       q.push(next);
      }
      else
      {
       str[next.x][next.y]='#';
       next.time=now.time+1;
       q.push(next);
      }
     }
    }
   }
   return -1;
}
int main()
{
int i,j,t;
point start;
while(scanf("%d%d",&n,&m)!=-1)
{
  for(i=0;i<n;i++)
  {
   scanf("%s",str[i]);
   for(j=0;j<m;j++)
   {
    if(str[i][j]=='a')
    {
     start.x=i;
     start.y=j;
     start.time=0;
    }
   }
  }
  t=bfs(start);
  if(t==-1)
   printf("Poor ANGEL has to stay in the prison all his life.\n");
  else
   printf("%d\n",t);
}
return 0;
}
