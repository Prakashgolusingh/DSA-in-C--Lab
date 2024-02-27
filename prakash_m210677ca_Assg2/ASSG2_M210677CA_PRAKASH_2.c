#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*void store_word(struct node*[],char[]);
void print_h(struct node*);*/
struct node
{
char *word [100];
struct node*next;
};
int h(char [],int );
struct node *c;
void store_word(struct node *table[],int n,char a[])
{
    int group;
    struct node *newnode= (struct node*)malloc(sizeof(struct node));
    strcpy(newnode->word,a);
    newnode->next=NULL;

    if(find_hash1(table,a,n)>find_hash2(table,a,n))
    {
        group=g(a);
        if(table[group]==NULL)
        {
            table[group]=newnode;
        }
        if(table[group]!=NULL)
        {
            c=table[group];
            while(c->next!=NULL)
            {
                c=c->next;
            }
            c->next=newnode;
        }
    }
    else if(find_hash1(table,a,n)<find_hash2(table,a,n))
    {
        group=h(a,n);
        if(table[group]==NULL)
        {
            table[group]=newnode;
        }
        if(table[group]!=NULL)
        {
            c=table[group];
            while(c->next!=NULL)
            {
                c=c->next;
            }
            c->next=newnode;
        }
    }
    else
    {
        group=h(a,n);
        if(table[group]==NULL)
        {
            table[group]=newnode;
        }
        if(table[group]!=NULL)
        {
            c=table[group];
            while(c->next!=NULL)
            {
                c=c->next;
            }
            c->next=newnode;
        }
    }
}
int h(char w[],int n)
{
    if(strlen(w)==1)
    {
        int a=(int)w;
        return a;
    }
    else
    {
        int a=((int)w[1]+(int)w[2]+(int)w[strlen(w)-1]+(int)w[strlen(w)-2])%n;
        return a;
    }
}
int g(char w[],int n)
{
    int a=strlen(w),b=0;
    for(int i=0;i<a;i++)
    {
        int b=b+(int)w[i];
    }
    return(b%n);
}
int find_hash1(struct node *table[], char w[],int n)
{
    int b=0;
    int i=h(w,n);
    if(table[i]==NULL)
        return b;
    else
    {
        for(c=table[i];c!=NULL;c=c->next)
        {
            if(c->next!=NULL)
            {
                ++b;
            }
        }
        return b;
    }
}
int find_hash2(struct node *table[],char w[],int n)
{
    int b=0;
    int i=g(w,n);
    if(table[i]==NULL)
        return b;
    else
    {
        for(c=table[i];c!=NULL;c=c->next)
        {
            if(c->next!=NULL)
            {
                ++b;
            }
        }
        return b;
    }
}
void main()
{
    int n;
    char s[105];
    scanf("%d",&n);
    fflush(stdin);
    struct node *hashtab[n];
    for(int i=0;i<n;i++)
    {
        hashtab[i]=NULL;
    }
    scanf("%[^\n]s",&s);
    fflush(stdin);
    char *a=strtok(s," ");
    while(a!=NULL)
    {
        store_word(hashtab,n,a);
        a=strtok(NULL," ");
    }
    print_h(hashtab);
}
void print_h(struct node *table[],int n)
{
    for(int i=0;i<n;i++)
    {
        if(table[i]==NULL)
            printf("null\n");
        else
        {
            for(c=table[i];c!=NULL;c=c->next)
            {
                printf("%s ",c->word);
            }
            printf("\n");
        }
    }

}


