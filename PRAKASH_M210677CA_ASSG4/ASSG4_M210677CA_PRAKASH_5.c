#include<stdio.h>
#include<stdlib.h>
int main()
{
    int v,e,first,second,third,i,j;
    scanf("%d %d",&v,&e);
    int array[v][v],k;
    int compare[v][v];
    for(i=0;i<v;i++)
    {

        for(j=0;j<v;j++)
        {
            array[i][j]=0;

            compare[i][j]=10000;
        }
        compare[i][0]=0;
    }

    for(i=0;i<e;i++)
    {

        scanf("%d %d %d",&first,&second,&third);
        array[first][second]=third;
    }
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            if(array[i][j]!=0)
            {
                if(compare[0][i]+array[i][j]<compare[0][j])
                    compare[0][j]=compare[0][i]+array[i][j];
            }
        }
    }
    for(k=1;k<v;k++)
    {
         for(i=0;i<v;i++)
         {
            for(j=0;j<v;j++)
            {
                if(array[i][j]!=0)
                {
                    if(compare[k-1][i]+array[i][j]<compare[k-1][j])
                        compare[k][j]=compare[k-1][i]+array[i][j];
                    else
                        compare[k][j]=compare[k-1][j];
                }
            }
        }
    }
    k=0;
    for(i=0;i<v;i++)
    {
        if(compare[v-1][i]==compare[v-2][i])
            k++;
    }

    if(k==v)
        printf("-1");
    else
        printf("1");

}
