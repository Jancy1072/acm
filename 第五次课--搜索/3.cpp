#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
int dx[] = {-1,0,1,0};//up Right down Left
int dy[] = {0,1,0,-1};

int N,M,T;
char map[10][10];
int Wall;
int di,dj;
int si,sj;
bool is;
void dfs(int si,int sj,int t)
{
    if(si<1||sj<1||si>N||sj>M||t>T||is)
        return;
    if(si==di && sj==dj && t==T)
    {
        is=true;
        return;
    }

    if ((abs(di-si)+abs(dj-sj))%2!=(T-t)%2) return ;

    for(int i=0;i<4;i++)
    {
        if(map[si+dx[i]][sj+dy[i]]!='X')
        {
            map[si+dx[i]][sj+dy[i]]='X';
            dfs(si+dx[i],sj+dy[i],t+1);
            map[si+dx[i]][sj+dy[i]]='.';
        }
    }
    return;
}
int main()
{
    while(~scanf("%d %d %d",&N,&M,&T) && N!=0)
    {
        Wall=0;
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=M;j++)
            {
                scanf(" %c",&map[i][j]);//此处scanf里面%c前面的空格很重要，不然读入会出问题，求高手解释..
                if(map[i][j]=='S')
                {
                    si=i;sj=j;
                }
                if(map[i][j]=='X')
                    Wall++;
                if(map[i][j]=='D')
                {
                    di=i;dj=j;
                }
            }
        }
        is=false;
        if(N*M-Wall<T)
            is=false;
        else
        {
            map[si][sj]='X';
            dfs(si,sj,0);
        }
        if(is)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
