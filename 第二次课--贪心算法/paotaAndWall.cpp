/*���ڵ�ͼ�Ĵ�С���Ϊ4*4����ô���Ǿͽ���ͼ��һ��char�������������map[4][4]�����map[i][j]='X'���ʾ��ͼ�˴���ŵ�Ϊǽ��map[i][j]='.'���ʾ�˴���ŵ�Ϊ�յأ���map[i][j]='o'���ʾ�˴���ŵ�Ϊ������

�ؼ�����������ͬʱ��ˮƽ�ʹ�ֱ���ϣ�������ǽ��Ϊ�����

���Ƕ���kΪλ�ã�k=0��Ϊ��ͼ���Ϸ���һ�����ӡ�

����������ʾ��

��4*4�ĵ�ͼ��

0  1  2  3

4  5 6  7

8  9  10  11

12 13 14 15

��ô���������з��������ж�����������1.�ŵ�λ���Ƿ�Ϊ�յ�2.ͬ��ͬ�в��ܹ���������������ǽ�������canput������

�������k=n*n����ֹ����ʱ����Ŀǰ������������Ƿ����bestn������������

�������������ɵõ���õĽ����

�������£�
*/

#include<stdio.h>
//���еĳߴ� 
int n;
//���еĵ�ͼ�������4*4
char map[4][4];
//���ŵ�������
int bestn;
//�������Ƿ��ܹ����� 
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
//K��ʾ����������λ�� 
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
