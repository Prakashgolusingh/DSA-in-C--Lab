#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
int v;
int main()
{
    char a;
    scanf("%c",&a);
    scanf("%d",&v);
    int edges,first=INT_MAX,check=0,d=0,second=INT_MAX,element1,element2,third=INT_MAX,i,j,matrix[v][v],k,compare[v][v],kruskalarray[v],primarray[v],kruskalsum=0,primsum=0,count=0;
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            matrix[i][j]=0;
            compare[i][j]=0;
        }
        kruskalarray[i]=i;
        primarray[i]=0;
    }
    char s[2*v];
    for(i=0;i<v;i++)
    {
        scanf(" %[^\n]s",s);

        char *ttookkeenn=strtok(s," ");
        while(ttookkeenn!=NULL)
        {

            edges=atoi(ttookkeenn);
            if(edges!=i)
                matrix[i][edges]=1;
            ttookkeenn = strtok(NULL, " ");
        }
    }
    for(i=0;i<v;i++)
    {
        fflush(stdin);
        scanf("%[^\n]s",s);

        char *ttookkeenn=strtok(s," ");
        while(ttookkeenn!=NULL)
        {
            edges=atoi(ttookkeenn);
            for(j=0;j<v;j++)
            {
                if(edges!=i && matrix[i][j]==1)
                {
                    matrix[i][j]=edges;
                    break;
                }
            }
            ttookkeenn = strtok(NULL, " ");
        }
    }
    if(a=='b')
    {
    primarray[0]=1;
    while(count<v-1){
    third=INT_MAX;
    for(j=0;j<v;j++)
    {
        if(primarray[j]==1)
        {
        for(i=0;i<v;i++)
        {
            if(matrix[j][i]!=0)
            {
                if(matrix[j][i]<third)
                {
                    first=j;
                    second=i;
                    third=matrix[j][i];
                }
            }
        }
    }
    }
    if((primarray[first]==1 && primarray[second]==0)||(primarray[first]==0 && primarray[second]==1))
    {
        primsum+=third;
        primarray[first]=primarray[second]=1;
        matrix[first][second]=0;
        matrix[second][first]=0;
        count++;
    }
    }

    printf("%d",primsum);
    }
}
