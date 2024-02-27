#include <stdio.h>
#include <stdlib.h>
void printing(int[],int ,int);


// main fn
void main()
{
    int n;
    scanf("%d",&n);
    int x=1,i=0,j;
    int *array;
    array=malloc(n*sizeof(int));
    for(i=1;i<=n;i++)
        scanf("%d",&array[i]);
    scanf("%d",&x);
    printing(array,x,n);

}
void printing(int array[],int a,int n)
{
    int b,c=1;
    for(int i=1;i<=n;i++)
    {
        if(a==array[i])
        {
            b=i;
            break;
        }
        else
            return;
    }
    printf("%d",b);
    for(int i=1;i<=n;i++)
        printf("%d",array[i]);

    if(b==1 || b==2 || b==3)
        return;
    else
    {
        for(int i=0;i<b;i++)
        {
            for(int j=0;j<i;j++)
            {
                c=c*2;
            }
            if(c<=b)
                break;
        }
        for(int j=c;j<2*c;j++)
        {
            if(j<=n && j!=b){
            if(b%2==0 && j !=b+1)
            {
                printf("%d ,",array[j]);
            }
            else if(b%2!=0 && j!=b-1)
            {
                printf("%d ",array[j]);
                if(j<2*c)
                    printf(",");

            }
            }
        }
    }
}
