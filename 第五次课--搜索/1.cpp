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
            //�ҵ���̵��ַ���
            if(strlen(string[i])<min_len)
            {
                min_len = strlen(string[i]);
                index = i;
            }
        }
        int len;
        len = min_len;
        strcpy(str,string[index]);//���ַ�����������
        while(len>0)
        {
            flag = 0;
            for(i = 0; i <= min_len-len;i++)
            {
                flag = 1;//���Ϊ����
                strncpy(pos,str+i,len);//�����ַ���
                for(j = 0;j<len;j++)
                inv[j] = pos[len-j-1];//�����ַ���
                pos[len] = inv[len] ='\0';
                for(j = 0;j<n;j++)
                {
                    /**
                    �����ļ���string.h
����                ������: strstr
����                ����ԭ�ͣ�extern char *strstr(char *str1, char *str2);
����                ���ܣ��ҳ�str2�ַ�����str1�ַ����е�һ�γ��ֵ�λ�ã�������str2�Ĵ�����������
                    */

                    if(strstr(string[j],pos)==NULL&&strstr(string[j],inv)==NULL)
                    {
                        flag = 0;//���ַ���������
                        break;
                    }
                }
                if(flag)break;//������˵�����ַ�����ÿ���ַ����ж��У���û�ҵ�����ѭ��
            }
            if(flag)break;//ͬ��
            len--;
        }
        printf("%d\n",len);
    }
    return 0;
}
