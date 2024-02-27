#include<stdio.h>
#include<stdlib.h>
int set1[200]={0},set2[1][200]={0},set3[200]={0};
void MAKE_SET(int );
int FINDSET1(int);
int FINDSET2(int);
void UNION(int,int);
int main()
{
    int c,b;
    char a;
    abc:
        scanf("%c",&a);
        switch(a)
        {
            case 'm':
                scanf("%d",&b);
                MAKE_SET(b);
                break;
            case 'f':
                scanf("%d",&c);
                b=FINDSET1(c);
                printf("%d ",b);

                b=FINDSET2(c);
                printf("%d ",b);

                b=FINDSET1(c);
                printf("%d\n",b);

                break;
            case 'u':
                scanf("%d %d",&a,&b);
                UNION(a,b);
                break;
            case 'e':
                exit(0);
                break;
            default:
                goto abc;
        }
        goto abc;
    return 0;
}
void MAKE_SET(int a)
{
    if(set1[a]==0)
    {
        set1[a]=a;
        set3[a]=a;
        set2[0][a]=a;
        set2[1][a]=0;
        printf("%d\n",a);
    }
    else
        printf("-1\n");
}
int FINDSET1(int a)
{
    while(set1[a]!=a)
    {
        a=set1[a];
        if(set1[a]==0)
            break;
    }
    //print("%d",a);
    return a;
}

int FINDSET2(int a)
{
    while(set2[0][a]!=a)
    {
        a=set2[0][a];
        if(set2[0][a]==0)
            break;
    }
    //print("%d",a);
    return a;
}
void UNION(int x,int y)
{
    //normal union
    int a=FINDSET1(x);
    int b=FINDSET1(y);
    int i=0;
    set1[b]=a;
    printf("%d ",a);

    // union by rank
    int e=FINDSET2(x);
    int f=FINDSET2(y);

    if(set2[0][e]!=0 && set2[0][f]!=0)
    {
        if(set2[1][e]<set2[1][f])
        {
            set2[0][e]=set2[0][f];
            printf("%d ",set2[0][e]);
        }
        else
        {
            set2[0][f]=set2[0][e];
            printf("%d ",set2[0][e]);
            if(set2[1][e]==set2[1][f])
                set2[1][e]++;
        }

    }
    //union by path compression
    i=1;
    int c=FINDSET1(x);
    int d=FINDSET1(y);
    while(set3[i]!=0)
    {
        if(set3[i]==d)
            set3[i]=c;
        i++;
    }
    printf("%d\n",c);
}
