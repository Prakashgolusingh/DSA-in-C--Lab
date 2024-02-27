#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*void insert(struct node*[],char[]);
void display(struct node*);*/
struct node
{
char *word [100];
struct node*next;
};
struct node *c;
int k,group;

//starting of function insert
void insert(struct node *table[],char a[])
{
    struct node *newnode= (struct node*)malloc(sizeof(struct node));
    strcpy(newnode->word,a);
    newnode->next=NULL;
    if(table[group]==NULL)
    {
        table[group]=newnode;
    }
    else
    {
        c=table[group];
        int k=0,same=5;
        while(c->next!=NULL)
        {
            int same=strcmp(a,c->word);
            if(same==0)
            {
                k=1;
            }
            c=c->next;
        }
        if(k!=1)
        {
            c->next=newnode;
        }
    }
}
//ending of function insert

// starting of main function
void main()
{
    char s[500];
    scanf("%d",&k);
    fflush(stdin);
    struct node *hashtab[k];
    for(int i=0;i<k;i++)
    {
        hashtab[i]=NULL;
    }
    scanf("%[^\n]s",&s);
    fflush(stdin);
    int len=strlen(s);
    char *a=strtok(s," ");
    while(a!=NULL)
    {
        group=(strlen(a)*strlen(a))%k;
        insert(hashtab,a);
        a=strtok(NULL," ");
    }
    display(hashtab);
}
//ending of main function

//starting of display function
void display(struct node *table[])
{
    for(int i=0;i<k;i++)
    {
        printf("%d :",i);
        if(table[i]==NULL)
            printf("null\n");
        else
        {
            for(c=table[i];c!=NULL;c=c->next)
            {
                printf("%s",c->word);
                if(c->next!=NULL)
                {
                    printf("-");
                }
            }
            printf("\n");
        }
    }
//ending of display function
}


