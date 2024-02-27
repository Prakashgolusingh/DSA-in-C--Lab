/*Each line contains an operation represented by characters from ‘i’, ‘and ‘e’ followed by at most
one integer.
● Character ‘i’ is followed by an integer separated by space. In this operation, a node with
this integer as the key is created and inserted into T.
● Character ‘p’ is to print the Parenthesis Representation of the tree T.
● Character ‘e’ is to ‘exit’ from the program.*/
#include <stdio.h>
#include <stdlib.h>
// defining data type of node
struct binary_tree {
    int data;
    struct binary_tree *left,*right;
};
struct binary_tree *root=NULL;
// creating node for binary tree
struct binary_tree* create_node(int data)
{
    struct binary_tree* node = (struct binary_tree*)malloc(sizeof(struct binary_tree));
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}
//inserting data to binary tree
struct binary_tree* insert(int array[], struct binary_tree* node,int i, int arrsize)
{
    if (i<arrsize)
    {
        struct binary_tree *ptr = create_node(array[i]);
        node=ptr;
        node->left = insert(array,node->left,2*i+1,arrsize);
        node->right = insert(array,node->right,2*i+2,arrsize);
    }
    return node;
}
void printing(struct binary_tree*n){
    if(n==NULL) {
        printf("()");
        return ;}
    else{
         printf("(%d",n->data);

        printing(n->left);
        printing(n->right);
        printf(")");
    }
}
// main fn
void main()
{
    int x=1,array[200],i=0,j;
    char b;
    abc:
        scanf("%c",&b);
        switch(b)
        {
            case'i':
                scanf("%d",&array[i++]);
                break;
            case 'p':
                root=insert(array,root,0,i);
                printing(root);
                break;
            case 'e':
                exit(0);
                break;
            default:
                goto abc;
        }
        goto abc;
}
