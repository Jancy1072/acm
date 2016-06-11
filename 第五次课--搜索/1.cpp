#include <stdio.h>
#include <string.h>

int main()
{
    char string[105][105],str[105],pos[105],inv[105];
    int i,j,t,n,min_len,index;
    int flag;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        min_len = 105;
        for(i = 0; i < n; i++)
        {
            scanf("%s",string[i]);
            //找到最短的字符串
            if(strlen(string[i])<min_len)
            {
                min_len = strlen(string[i]);
                index = i;
            }
        }
        int len;
        len = min_len;
        strcpy(str,string[index]);//将字符串拷贝出来
        while(len>0)
        {
            flag = 0;
            for(i = 0; i <= min_len-len;i++)
            {
                flag = 1;//标记为符合
                strncpy(pos,str+i,len);//正向字符串
                for(j = 0;j<len;j++)
                inv[j] = pos[len-j-1];//逆向字符串
                pos[len] = inv[len] ='\0';
                for(j = 0;j<n;j++)
                {
                    /**
                    包含文件：string.h
　　                函数名: strstr
　　                函数原型：extern char *strstr(char *str1, char *str2);
　　                功能：找出str2字符串在str1字符串中第一次出现的位置（不包括str2的串结束符）。
                    */

                    if(strstr(string[j],pos)==NULL&&strstr(string[j],inv)==NULL)
                    {
                        flag = 0;//该字符串不符合
                        break;
                    }
                }
                if(flag)break;//符合则说明该字符串在每个字符串中都有，若没找到继续循环
            }
            if(flag)break;//同上
            len--;
        }
        printf("%d\n",len);
    }
    return 0;
}
