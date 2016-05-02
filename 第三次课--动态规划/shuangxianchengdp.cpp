#include<stdio.h>  
#include<string.h>  
#include<stdlib.h>  
#define s 30  
//˫�߳�dp 
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
������Ͻ��ߵ����½��ٷ������Ͻǵ�·�����Ȩֵ����Ϊ���߻�ȥ�Ĺ��̣�����һ������Ļ�ֱ��dp�᲻��д��
���ｫ·�����ɴ����Ͻǵ����½ǲ��ཻ������·����dp[t][r][p][q]�д��һ��·�ߵ�(t,r)��͵ڶ���·�ߵ�(p,q)������Ȩֵ��
���׵õ�ת�Ʒ���dp[t][r][p][q]=max(dfs(t-1,r,p-1,q),dfs(t-1,r,p,q-1),dfs(t,r-1,p-1,q),dfs(t,r-1,p,q-1))+map[t][r]+map[p][q]��
ÿһ��dp����·�����ֱ���ǰ��һ����Ϊ�˱�֤�����߲����ظ������ص㣬���￪ʼ©�ˣ���
�ڼ������Ҫ�õ�״̬ǰ�Ƚ�����·�ߵ���ͬ������dp[i][j][i][j]����0��vis[i][j][i][j]=1�������Ͳ�������ߵ�ͬһ��������
�ߵ�ͬһ������Ҳ����Ӱ����ȷ�����ֵ��
*/
