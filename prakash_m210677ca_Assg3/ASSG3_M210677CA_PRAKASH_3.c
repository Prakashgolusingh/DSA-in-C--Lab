/* q-3.Given an array of n integers with any of these integers appearing any number of times. Write
a program to sort these n integers in O(nlog m) time, where m is the number of distinct elements
in array*/

#include <stdio.h>
#include <stdlib.h>

//defining struct data type
struct node
{
int key;
int count; //number of times a key appears in the array
int height;
struct node *left;
struct node *right;
};

//declaring our all function
void printtree(struct node *);
int height(struct node *);
struct node *rightRotate(struct node *);
struct node *leftRotate(struct node *);
struct node* createavlnode(int);
struct node *insert(struct node *,int);
int getbalance(struct node *);
int max(int, int);

//defining main function
int main()
{
    int n,*arr;
    struct node *T=NULL;
    scanf("%d",&n);
    arr=malloc(n*sizeof(n));
    for(int i=0;i<n;i++)
    {
        scanf("%d",arr+i);
        T=insert(T,*(arr+i));
    }
    printtree(T);
}

//starting of height fn
int height(struct node *A)
{
	if (A == NULL)
		return 0;
	return A->height;
}

//starting of right rotation fn
struct node *rightRotate(struct node *K)
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
struct node *leftRotate(struct node *K)
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

//function for creating node for avl tree
struct node* createavlnode(int K)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->key = K,temp->left = temp->right = NULL,temp->height=1,temp->count=1;
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
    if(K==A->key)
    {
        A->count++;
        return A;
    }
    A->height = 1 + max(height(A->left),
						height(A->right));
	int balance = getbalance(A);

	if (balance > 1 && K < A->left->key)
		return rightRotate(A);

	if (balance < -1 && K > A->right->key)
		return leftRotate(A);
	if (balance > 1 && K > A->left->key)
	{
		A->left = leftRotate(A->left);
		return rightRotate(A);
	}

	if (balance < -1 && K < A->right->key)
	{
		A->right = rightRotate(A->right);
		return leftRotate(A);
	}
	return A;
}
//end of insert fn

int getbalance(struct node *N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

int max(int a, int b)
{
	if(a>b)
        return a;
    else
        return b;
}

//starting of our last fn that is printtree fn
void printtree(struct node *A)
{
    if(A==NULL)
    {
        return ;
    }
    else
    {
        printtree(A->left);
        int a=A->count;
        while(a)
        {
            printf("%d ",A->key);
            a--;
        }
        printtree(A->right);

    }
}
