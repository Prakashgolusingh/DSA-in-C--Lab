#include <stdio.h>
#include <stdlib.h>
void printing(int[],int ,int);


// main fn
void main()
{
    int n;
    scanf("%d",&n);
    int x,i;
    int *array;
    array=malloc((n+1)*sizeof(int));
    for(i=1;i<=n;i++)
        scanf("%d",&array[i]);
    scanf("%d",&x);
    printing(array,x,n);

}
void printing(int array[],int a,int n)
{
    int b,i,j,s,c=1;
    for(int i=1;i<=n;i++)
    {
        if(a==array[i])
        {
            b=i;
            break;
        }
    }
    if(b==3 || b==1 ||b==2 )
        return;
    else
    {
        for(int i=1;i<b;i++)
        {
            c=1;
            for(int j=0;j<i;j++)
            {
                c=c*2;
            }
            if(c<=b && b<2*c)
                break;
        }
        if(b%2==0)
            s=b+1;
        else
            s=b-1;
        for(int j=c;j<2*c;j++)
        {
            if(j<=n){
            if(j==b || j==s)
            {
                continue;
            }
            else
            {
                printf("%d ,",array[j]);
            }
            }
        }
    }
}
