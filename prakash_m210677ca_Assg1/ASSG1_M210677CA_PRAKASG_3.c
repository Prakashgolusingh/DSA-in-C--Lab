#include <stdio.h>
#include <stdlib.h>
//creating node data type
struct BSTnode {
    int roll,marks;
    struct BSTnode *left,*right;
};

struct BSTnode* min(struct BSTnode* T){
    if(T==NULL)
        return NULL;
    else if(T->left==NULL)
        return T;
    else
        return min(T->left);
}
struct BSTnode* max(struct BSTnode* T){
    if(T==NULL)
        return NULL;
    else if(T->right==NULL)
        return T;
    else
        return max(T->right);
}

struct BSTnode* deleteBSTnode(struct BSTnode* root,int roll,int marks)
{
    if (root==NULL)
        return root;

    if (marks<root->marks)
        root->left=deleteBSTnode(root->left,roll,marks);
    else if(marks>root->marks)
        root->right=deleteBSTnode(root->right, roll,marks);
    else {
        if(root->left == NULL){
            struct BSTnode* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right==NULL){
            struct BSTnode* temp=root->left;
            free(root);
            return temp;
        }

        struct BSTnode* temp = min(root->right);

        root->roll=temp->roll;
        root->marks=temp->marks;
        root->right = deleteBSTnode(root->right,temp->roll,temp->marks);
    }
    return root;
}

//create a new BSTnode of tree
struct BSTnode* createBSTnode(struct BSTnode temp){
    struct BSTnode* BSTnode=(struct BSTnode*)malloc(sizeof(struct BSTnode));
    BSTnode->roll=temp.roll;
    BSTnode->marks=temp.marks;
    BSTnode->left=BSTnode->right=NULL;
    return BSTnode;
}

struct BSTnode* sortedarrayayToBST(struct BSTnode array[], int start, int end) {
    if(start > end)
        return NULL;

    int mid = start + (end - start) / 2;
    struct BSTnode* BSTnode=createBSTnode(array[mid]);
    BSTnode->left=sortedarrayayToBST(array,start,mid-1);
    BSTnode->right=sortedarrayayToBST(array,mid+1,end);
    return BSTnode;
}

struct BSTnode* insert(struct BSTnode array[],int num) {
  return sortedarrayayToBST(array,0,num-1);
}

void minmax(struct BSTnode *T){
    if(T){
        struct BSTnode *tempmin=NULL;
        tempmin=min(T);
        printf("(%d,%d), ", tempmin->roll,tempmin->marks);

        struct BSTnode *tempmax=NULL;
        tempmax=max(T);
        if(tempmin->roll != tempmax->roll)
        printf("(%d,%d), ", tempmax->roll,tempmax->marks);

        T=deleteBSTnode(T,tempmin->roll,tempmin->marks);
        T=deleteBSTnode(T,tempmax->roll,tempmax->marks);

        minmax(T);
    }
}
void swapping(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
// creating Main function
int main()
{
    int num,roll,marks;
    struct BSTnode* T = NULL,*temp=NULL;
    scanf("%d",&num);
    struct BSTnode array[num];

    for(int i=0;i<num;i++){
        scanf("%d",&roll);
        scanf("%d",&marks);
        array[i].roll=roll;
        array[i].marks=marks;
    }

    int i, j;
    for(i=0;i<num-1;i++)
        for(j=0;j<num-i-1;j++)
           if (array[j].marks>array[j+1].marks){
              swapping(&array[j].marks, &array[j+1].marks);
              swapping(&array[j].roll, &array[j+1].roll);
           }
    T=insert(array,num);
    minmax(T);
    return 0;
}
