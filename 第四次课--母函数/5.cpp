#include<stdio.h>
#include<string.h> 
int a[250010],s[250010];
int v[55],m[55]; 
int main()
{
	int n,i,j,k,sum,ans;
	while(scanf("%d",&n)&&n>0)
	{
		sum=0;
		memset(s,0,sizeof(s));
		memset(a,0,sizeof(a));
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&v[i],&m[i]);
			sum+=v[i]*m[i];
		}
		for(i=0;i<=v[1]*m[1];i+=v[1])
		{
			s[i]=1;
		}
		for(i=2;i<=n;i++)
		{
			for(j=0;j<=sum;j++)
			{
		      	for(k=0;k+j<=sum&&k<=v[i]*m[i];k+=v[i])
				{
				   a[k+j]+=s[j];
			    }
			}
			for(k=0;k<=sum;k++)
			{
				s[k]=a[k];
				a[k]=0;
			}
		}
		for(i=sum/2;i>=0;i--)
		{
			if(s[i])
			{
			    printf("%d %d\n",sum-i,i);
			    break;
			}
		}
	}
	return 0;
} 
