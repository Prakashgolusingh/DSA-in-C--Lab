#include <stdio.h>
#include <stdlib.h>
// defining data type of node
int main()
{
    int n,i,j;
    scanf("%d",&n);
    int array[n][n];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&array[i][j]);
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%d ",i);
        for(j=0;j<n;j++)
        {
            if(array[i][j]==1)
                printf("%d ",j);
        }
        printf("\n");
    }
}

