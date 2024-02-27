
#include <stdio.h>
#include<stdlib.h>
// defining all function use in this program
void search_1(int[],int);
void delete_1(int[], int);
void insert_1(int[],int);
void print_1(int[]);
void search_2(int[],int);
void delete_2(int[], int);
void insert_2(int[],int);
void print_2(int[]);
void search_3(int[],int);
void delete_3(int[], int);
void insert_3(int[],int);
void print_3(int[]);
int hash(int);
int prime(void);
int m,c1,c2,b;
// starting of insert_1 function
void insert_1(int table[],int k)
{
    int a=hash(k);
    int position=a;
    for(int j=1;j<m;j++)
    {
        if(table[position]==0)
        {
            table[position]=k;
            break;
        }
        if(table[position]!=0)
        {
            position=(a+j)%m;
        }
    }
}
//ending of insert_1 function
//starting of search_1 function
void search_1(int table[],int k)
{
    int a=hash(k),c=0;
    int position=a;
    for(int j=1;j<m;j++)
    {
        if(table[position]==k)
        {
            printf("1\n");
            c=1;
            break;
        }
        else
        {
            position=(a+j)%m;
        }
    }
    if(c!=1)
    {
        printf("-1\n");
    }
}
//ending of search function
//starting of delete function
void delete_1(int table[],int k)
{
    int a=hash(k);
    int position=a;
    for(int j=1;j<m;j++)
    {
        if(table[position]==k)
        {
            table[position]=0;
            break;
        }
        else
            position=(a+j)%m;
    }
}
//ending of delete function
//starting of print function
void print_1(int table[])
{
    for(int j=0;j<m;j++)
    {
        if(table[j]!=0)
            printf("%d (%d)\n",j ,table[j]);
        if(table[j]==0)
            printf("%d ()\n",j);
    }
}
//ending of print function

//starting of hash function
int hash(int k)
{
    return (k%m);
}
//ending of hash function

//starting of insert_2 function
void insert_2(int table[],int k)
{

    int a=hash(k);
    int position=a;

    for(int j=1;j<m;j++)
    {
        if(table[position]==0)
        {
            table[position]=k;
            break;
        }
        if(table[position]!=0)
        {
            position=(a+(c1*j)+(c2*j*j))%m;
        }
    }
}
//ending of insert_2 function

//starting of search_2 function
void search_2(int table[],int k)
{
    int a=hash(k);
    int position=a,c=0;
    for(int j=1;j<m;j++)
    {
        if(table[position]==k)
        {
            printf("1\n");
            c=1;
            break;
        }
        else
        {
            position=(a+(c1*j)+(c2*(j*j)))%m;
        }
    }
    if(c!=1)
    {
        printf("-1\n");
    }
}
//ending of search_2 function

//starting of delete_2 function
void delete_2(int table[],int k)
{
    int a=hash(k);
    int position=a;
    for(int j=1;j<m;j++)
    {
        if(table[position]==k)
        {
            table[position]=0;
            break;
        }
        else
            position=(a+(c1*j)+(c2*(j*j)))%m;
    }
}
//ending of delete_2 function

//starting of print_2 function
void print_2(int table[])
{
    for(int j=0;j<m;j++)
    {
        if(table[j]!=0)
            printf("%d (%d)\n",j ,table[j]);
        if(table[j]==0)
            printf("%d ()\n",j);
    }
}
//ending of print_2 function

//prime no to m
int prime()
{
    int c=0;
    for(int i=m-1;i>1;i--)
    {
        for(int j=2;j<i;j++)
        {
            if(i%j==0)
                c=1;
                break;
        }
        if(c==0)
        {
            return i;
            break;
        }
        else
            c=0;
    }
}
//starting of insert_3 function
void insert_3(int table[],int k)
{
    int a=hash(k);
    int position=a;
    int r=prime();
    for(int j=1;j<m;j++)
    {
        if(table[position]==0)
        {
            table[position]=k;
            break;
        }
        if(table[position]!=0)
        {
            position=(a+(j*(r-(k%r))))%m;
        }
    }
}
//ending of insert_3 function

//starting of search_3 function
void search_3(int table[],int k)
{
    int a=hash(k),r=prime();
    int position=a,c=0;
    for(int j=1;j<m;j++)
    {
        if(table[position]==k)
        {
            printf("1\n");
            c=1;
            break;
        }
        else
        {
            position=(a+(j*(r-(k%r))))%m;
        }
    }
    if(c!=1)
    {
        printf("-1\n");
    }
}
//ending of search_3 function

//starting of delete_3 function
void delete_3(int table[],int k)
{
    int a=hash(k);
    int position=a;
    int r=prime();
    for(int j=1;j<m;j++)
    {
        if(table[position]==k)
        {
            table[position]=0;
            break;
        }
        else
            position=(a+(j*(r-(k%r))))%m;
    }
}
//ending of delete_3 function

//starting of print_3 function
void print_3(int table[])
{
    for(int j=0;j<m;j++)
    {
        if(table[j]!=0)
            printf("%d (%d)\n",j ,table[j]);
        if(table[j]==0)
            printf("%d ()\n",j);
    }
}
//ending of print function

//starting of hashtable
int *hashtable(int m)
{
    int *table=malloc(m*sizeof(int));
    for(int j=0;j<m+1;j++)
    {
        table[j]=0;
    }
    return table;
}
//ending of hashtable

//starting of main functon
int main()
{
    char a;
    scanf("%c",&a);
//starting of linear probing
    if(a=='a')
    {
            char i;
            scanf("%d",&m);
            int *table=hashtable(m);

//abc1
            abc1:

                scanf("%c",&i);
                switch(i)
                {
                    case 'i':
                        scanf("%d",&b);
                        insert_1(table,b);
                        break;
                    case 'd':
                        scanf("%d",&b);
                        delete_1(table,b);
                        break;
                    case 's':
                        scanf("%d",&b);
                        search_1(table,b);
                        break;
                    case 'p':
                        print_1(table);
                        break;
                    case 't':
                        exit(0);
                        break;
                    default:
                        goto abc1;
                }
            goto abc1;
        }
//end of linear probing

// case if quadratic probing choosen
            if(a=='b')
            {
                char i;
                scanf("%d",&m);
                scanf("%d %d",&c1,&c2);
                int *table=hashtable(m);
                abc2:
                    scanf("%c",&i);
                    switch(i)
                    {
                       case 'i':
                        scanf("%d",&b);
                        insert_2(table,b);
                        break;
                    case 'd':
                        scanf("%d",&b);
                        delete_2(table,b);
                        break;
                    case 's':
                        scanf("%d",&b);
                        search_2(table,b);
                        break;
                    case 'p':
                        print_2(table);
                        break;
                    case 't':
                        exit(0);
                        break;
                    default:
                        goto abc2;
                }
            goto abc2;
            }
//end of quadrating probing
//starting of double hashing
            if(a=='c')
            {
                scanf("%d",&m);
                int b;
                char i;
                int *table=hashtable(m);
                abc3:
                    scanf("%c",&i);
                    switch(i)
                    {
                        case 'i':
                            scanf("%d",&b);
                            insert_3(table,b);
                            break;
                        case 'd':
                            scanf("%d",&b);
                            delete_3(table,b);
                            break;
                        case 's':
                            scanf("%d",&b);
                            search_3(table,b);
                            break;
                        case 'p':
                            print_3(table);
                            break;
                        case 't':
                            exit(0);
                            break;
                        default:
                            goto abc3;
                    }
                goto abc3;
            }
//end of double hashing
    else
        printf("not valid input");
    return 0;
}
