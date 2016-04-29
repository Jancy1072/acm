#include<stdio.h> 
#include<stdlib.h> 
int main() 
{ 
    void f(int t,int *p,int *q); 
    int m,n,i,a[1000],b[1000]; 
    double s; 
    while(1) 
    { 	s=0; 
        scanf("%d %d",&m,&n); 
        if(m==-1&&n==-1) 
            break; 
        for(i=0;i<n;i++) 
            scanf("%d %d",&a[i],&b[i]); 
        f(n,&a[0],&b[0]); 
        for(i=0;i<n;i++) 
        { 
            if(m>b[i]) 
            { 
              m-=b[i]; 
              s+=a[i]; 
            } 
            else
            { 
              s+=a[i]*((double)m/b[i]); 
              break; 
            } 
        } 
        printf("%.3f\n",s); 
    } 
    return 0; 
} 
void f(int t,int *p,int *q) 
{ 
  int i,j,k,m; 
  for(i=0;i<t-1;i++) 
  { 
      k=i; 
      for(j=i+1;j<t;j++) 
          if((double)p[j]/q[j]>(double)p[k]/q[k]) 
              k=j; 
      m=p[i]; 
      p[i]=p[k]; 
      p[k]=m; 
      m=q[i]; 
      q[i]=q[k]; 
      q[k]=m; 
  } 
} 
