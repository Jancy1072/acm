#include<iostream>  
using namespace std;  
// 用贪心算出最少降序序列个数！
class a  
{  
    public:  
    int x,y,flog;  
};  
int main()  
{  
    int N,i,j,n,count;  
    a f[5010],t;  
    cin>>N;  
    while(N--)  
    {  
        cin>>n;  
        for(i=0; i<n; i++)  
        {  
            cin>>f[i].x>>f[i].y;  
            f[i].flog=1;  
        }  
        for(i=0; i<n; i++)  
            for(j=i+1; j<n; j++)  
                if(f[i].x>f[j].x)  
                {  
                    t=f[i];  
                    f[i]=f[j];  
                    f[j]=t;  
                }  
                else if(f[i].x==f[j].x&&f[i].y>f[j].y)  
                {  
                    t=f[i];  
                    f[i]=f[j];  
                    f[j]=t;  
                }  
        count=0;  
        for(i=0; i<n; i++)  
            if(f[i].flog)  
            {  
                t=f[i];  
                count++;  
                for(j=i+1; j<n; j++)  
                    if(f[j].flog)  
                        if(t.y<=f[j].y)  
                        {  
                            t=f[j];  
                            f[j].flog=0;  
                        }  
            }  
			cout<<count<<endl;  
    }  
	return 0;  
}  
