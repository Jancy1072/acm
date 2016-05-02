#include<stdio.h>  
#include<string.h>  
#include<stdlib.h>  
#define s 30  
//双线程dp 
int dp[s][s][s][s];  
int vis[s][s][s][s];  
int n;  
int map[s][s];  
int max(int a,int b,int c,int d)  
{  
    if(a>=b&&a>=c&&a>=d)  
        return a;  
    if(b>=a&&b>=c&&b>=d)  
        return b;  
    if(c>=a&&c>=b&&c>=d)  
        return c;  
    if(d>=a&&d>=b&&d>=c)  
        return d;  
}  
int dfs(int t,int r,int p,int q)  
{  
    int i,j,k,l;  
    if(t<0||t>=n||r<0||r>=n||p<0||p>=n||q<0||q>=n)  
        return 0;  
    if(vis[t][r][p][q]==1)  
        return dp[t][r][p][q];  
    vis[t][r][p][q]=1;  
    dp[t][r][p][q]=max(dfs(t-1,r,p-1,q),dfs(t-1,r,p,q-1),dfs(t,r-1,p-1,q),dfs(t,r-1,p,q-1))+map[t][r]+map[p][q];  
    vis[t][r][p][q]=1;  
    return dp[t][r][p][q];    
}  
  
int main()  
{  
    int i,j,k,l;  
    while(scanf("%d",&n)!=EOF)  
    {  
        for(i=0;i<n;i++)  
            for(j=0;j<n;j++)  
                scanf("%d",&map[i][j]);  
        memset(dp,0,sizeof(dp));  
        memset(vis,0,sizeof(vis));  
        dp[0][0][0][0]=0;  
        vis[0][0][0][0]=1;  
        for(i=0;i<n;i++)  
        {  
            for(j=0;j<n;j++)  
            {  
                dp[i][j][i][j]=0;  
                vis[i][j][i][j]=1;  
            }  
        }  
        printf("%d\n",dfs(n-1,n-2,n-2,n-1)+map[0][0]+map[n-1][n-1]);  
    }  
    return 0;  
}  
/*
求从左上角走到右下角再返回左上角的路径最大权值，因为有走回去的过程，当成一次走完的话直接dp会不好写，
这里将路径看成从左上角到右下角不相交的两条路径，dp[t][r][p][q]中存第一条路走到(t,r)点和第二条路走到(p,q)点的最大权值，
容易得到转移方程dp[t][r][p][q]=max(dfs(t-1,r,p-1,q),dfs(t-1,r,p,q-1),dfs(t,r-1,p-1,q),dfs(t,r-1,p,q-1))+map[t][r]+map[p][q]，
每一次dp两条路径都分别向前走一步，为了保证这样走不会重复（是重点，这里开始漏了），
在计算最后要用到状态前先将两条路走到相同点的情况dp[i][j][i][j]赋成0，vis[i][j][i][j]=1，这样就不会计算走到同一点的情况，
走到同一点的情况也不会影响正确情况的值。
*/
