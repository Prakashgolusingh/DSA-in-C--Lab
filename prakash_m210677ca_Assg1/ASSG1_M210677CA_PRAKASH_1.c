/*constructing a bst and then then we use some function*/
#include <stdio.h>
#include <stdlib.h>
struct BSTnode
{
    int data;
    struct BSTnode *left, *right;
};
struct BSTnode *max(struct BSTnode*);
struct BSTnode* create_BSTnode(int x)
{
    struct BSTnode* temp=(struct BSTnode*)malloc(sizeof(struct BSTnode));
    temp->data = x;
    temp->left = temp->right = NULL;
    return temp;
}
struct BSTnode* insert(struct BSTnode* T, int data)
{
    if (T == NULL)
        return create_BSTnode(data);
    if (data < T->data)
        T->left = insert(T->left, data);
    else if (data > T->data)
        T->right = insert(T->right, data);
    return T;
}
//searching fn
struct BSTnode* searching( struct BSTnode *root , int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (key < root->data)
        return(searching(root->left, key));
    if(key>root->data)
        return(searching(root->right, key));
    if(key==root)
        return root;
}
//deletion fn
struct BSTnode *delete( struct BSTnode *root , int key)
{
    struct BSTnode *temp;
    if (root == NULL)
    {
        return NULL;
    }
    if (key==searching(root,key))
    {
        if (key < root->data)
            root->left =delete(root->left, key);
        if(key>root->data)
            root->right=delete(root->right, key);
        else
        {
            if(root->left && root->right)
            {
                return root;
                temp=max(root->left);
                root->data=temp->data;
                root->left=delete(root->left,root->data);
            }
            else
            {
                temp=root;
                if(root->left==NULL && root->right!=NULL)
                    root=root->right;
                if(root->right==NULL && root->left!=NULL)
                    root=root->left;
            }
        }
    }
}
//function for min
struct BSTnode *min(struct BSTnode *root)
{
    while(root->left!=NULL && root!=NULL)
    {
        root=root->left;
    }
    return root;
}
struct BSTnode *max(struct BSTnode *root)
{
    while(root->right!=NULL && root!=NULL)
    {
        root=root->right;
    }
    return root;
}
// creating main function
main()
{
    struct BSTnode*T=NULL,*m;
    int b;
    char a;
    printf("enter \"a\"for insert no\nenter \"s\" for searching\nenter \"d\" for delete\nenter \"m\" for max.\nenter \"x\"for min.\nenter \"e\" to exit\nenter your option ");

    abc:
        scanf("%c",&a);
        switch(a)
        {
            case 'a':
                scanf("%d",&b);
                T=insert(T,b);
                break;
            case 'd':
                scanf("%d",&b);
                m=delete(T,b);
                if(b==searching(T,b))
                    printf("%d",b);
                if(m==NULL)
                    printf("-1\n");
                break;
            case 's':
                scanf("%d",&b);
                m=searching(T,b);
                if(m!=NULL)
                    printf("1\n");
                if(m==NULL)
                    printf("-1\n");
                break;
            case 'x':
                m=max(T);
                printf("%d\n",m->data);
                break;
            case 'm':
               m=min(T);
               printf("%d\n",m->data);
               break;
            case 'e':
                exit(0);
                break;
            default:
                goto abc;

        }
    goto abc;
}

