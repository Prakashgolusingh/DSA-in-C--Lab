
#include<stdio.h>
#include<stdlib.h>

//starting of struct datatype
struct node
{
    struct node *left;
    struct node *right;
    int height;
    int key;
};
//declaring all fn
void printtree(struct node *);
int height(struct node *);
struct node *rightrotate(struct node *);
struct node *leftrotate(struct node *);
struct node* createavlnode(int);
struct node *insert(struct node *,int);
struct node *deletenode( struct node * , int);
int getbalance(struct node *);
int max(int, int);
//end of struct

int max(int a, int b)
{
	return (a > b)? a : b;
}
//starting of search fn
struct node *search(struct node *A,int K)
{
    if(A==NULL)
    {
        return NULL;
    }
    else if(A->key==K)
    {
        return A;
    }
    else if(A->key>K)
    {
        search(A->left,K);
    }
    else if(A->key<K)
    {
        search(A->right,K);
    }
}
//end of search fn

struct node* createavlnode(int K)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->key = K,temp->left = temp->right = NULL,temp->height=1;
    return temp;
}

//starting of insert fn
struct node *insert(struct node *A,int K)
{
    if(A==NULL)
    {
       return (createavlnode(K));
    }
    else if(A->key>K)
    {
        A->left=insert(A->left,K);
    }
    else if(A->key<K)
    {
        A->right=insert(A->right,K);
    }

    A->height = 1 + max(height(A->left),
						height(A->right));
	int balance = getbalance(A);
	if (balance > 1 && K < A->left->key)
		return rightrotate(A);
	if (balance < -1 && K > A->right->key)
		return leftrotate(A);
	if (balance > 1 && K > A->left->key)
	{
		A->left = leftrotate(A->left);
		return rightrotate(A);
	}

	if (balance < -1 && K < A->right->key)
	{
		A->right = rightrotate(A->right);
		return leftrotate(A);
	}
	return A;
}
//end of insert fn

//starting of min fn
struct node * min(struct node*A)
{
	struct node* temp = A;
	while (temp->left != NULL)
		temp = temp->left;

	return temp;
}
//ending of min fn

//starting of deletenode fn
struct node* deletenode(struct node*A, int key)
{
	if (A == NULL)
		return A;

	if ( key < A->key )
		A->left = deletenode(A->left, key);


	else if( key > A->key )
		A->right = deletenode(A->right, key);
	else
	{
		if( (A->left == NULL) || (A->right == NULL) )
		{
		    struct node *temp;
		    if(A->left!=NULL)
                temp=A->left;
            else
                temp=A->right;
			if (temp == NULL)
			{
				temp = A;
				A = NULL;
			}
			else
			*A = *temp;
			free(temp);
		}
		else
		{
			struct node* temp = min(A->right);

			A->key = temp->key;
			A->right = deletenode(A->right, temp->key);
		}
	}
	if (A == NULL)
	return A;
	A->height = 1 + max(height(A->left),height(A->right));
	int balance = getbalance(A);
	if (balance > 1 && getbalance(A->left) >= 0)
		return rightrotate(A);
	if (balance > 1 && getbalance(A->left) < 0)
	{
		A->left = leftrotate(A->left);
		return rightrotate(A);
	}

	if (balance < -1 && getbalance(A->right) <= 0)
		return leftrotate(A);
	if (balance < -1 && getbalance(A->right) > 0)
	{
		A->right = rightrotate(A->right);
		return leftrotate(A);
	}
	return A;
}
//ending of delete fn

//starting of rightrotate fn
struct node *rightrotate(struct node *K)
{
	struct node *KC = K->left;
	struct node *temp = KC->right;

	KC->right = K;
	K->left = temp;

	K->height = max(height(K->left), height(K->right))+1;
	KC->height = max(height(KC->left), height(KC->right))+1;
	return KC;
}
//end of right rotate fn

//starting of left rotate fn
struct node *leftrotate(struct node *K)
{
	struct node *KC = K->right;
	struct node *temp = KC->left;

	KC->left = K;
	K->right = temp;

	K->height = max(height(K->left), height(K->right))+1;
	KC->height = max(height(KC->left), height(KC->right))+1;
	return KC;
}
//end of left rotate

//starting of gebalance fn
int getbalance(struct node *A)
{
	if (A == NULL)
		return 0;
	return (height(A->left) - height(A->right));
}
//ending of getbalance fn

//starting of height fn
int height(struct node *A)
{
	if (A == NULL)
		return 0;
	return A->height;
}
//ending of height fn

//starting of printtree fn
void printtree(struct node *A)
{
    if(A==NULL)
    {
        printf("()");
        return ;
    }
    else
    {
        printf("(%d",A->key);
        printtree(A->left);
        printtree(A->right);
        printf(")");
    }
}
//end of printtree fn

//starting of isavl fn
int  isavl(struct node *A)
{
    int a=getbalance(A);
    while(A!=NULL)
    {
        if(a>-2 && a<2)
        {
            isavl(A->left);
            isavl(A->right);
            return 1;
        }
        if(a>2 && a<-2)
            return 2;
    }
}
//ending of isavl fn

//starting of main fn
int main()
{
    struct node*T=NULL,*m;
    int b;
    char a;
    printf("enter \"i\"for insert no\nenter \"s\" for searching\nenter \"d\" for delete\nenter \"b\" for balance no\nenter \"c\"for check is avl\nenter \"p\"for print tree\nenter \"e\" to exit\nenter your option\n ");

    abc:
        scanf("%c",&a);
        switch(a)
        {
            case 'i':
                scanf("%d",&b);
                T=insert(T,b);
                break;
            case 'd':
                scanf("%d",&b);
                struct node *n=search(T,b);
                m=deletenode(T,b);
                if(n!=NULL)
                    printf("%d\n",n->key);
                else
                    printf("FALSE\n");
                break;
            case 's':
                scanf("%d",&b);
                m=search(T,b);
                if(m!=NULL)
                    printf("TRUE\n");
                if(m==NULL)
                    printf("FALSE\n");
                break;
            case 'b':
                scanf("%d",&b);
                m=search(T,b);
                printf("%d\n",getbalance(m));
                break;
            case 'c':
              b=isavl(T);
              if(b==2)
                printf("FALSE\n");
              else
                printf("TRUE");
               break;
            case 'p':
                printtree(T);
                printf("\n");
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
