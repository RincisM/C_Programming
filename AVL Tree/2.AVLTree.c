#include<stdio.h>
#include<stdlib.h>
#define COUNT 10

typedef struct node
{  int data;
   struct node *left,*right;
   int ht;
}node;

void print2DUtil(struct node *root, int space)
{
    int i;
    if (root == NULL)
        return;
    space += COUNT;
    print2DUtil(root->right, space);
    printf("\n");
    for (i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);
    print2DUtil(root->left, space);
}

void print2D(struct node *root)
{
    print2DUtil(root, 0);
}

int height(node *T)
{
    int lh,rh;
    if(T==NULL)
        return(0);
    if(T->left==NULL)
        lh=0;
    else
        lh=1+T->left->ht;
    if(T->right==NULL)
        rh=0;
    else
        rh=1+T->right->ht;
    if(lh>rh)
        return(lh);
    return(rh);
}

node * rotateright(node *x)
{
    node *y;
    y=x->left;
    x->left=y->right;
    y->right=x;
    x->ht=height(x);
    y->ht=height(y);
    return(y);
}

node * rotateleft(node *x)
{
    node *y;
    y=x->right;
    x->right=y->left;
    y->left=x;
    x->ht=height(x);
    y->ht=height(y);
    return(y);
}

node * RR(node *T)
{
    T=rotateleft(T);
    return(T);
}

node * LL(node *T)
{
    T=rotateright(T);
    return(T);
}

node * LR(node *T)
{
    T->left=rotateleft(T->left);
    T=rotateright(T);
    return(T);
}

node * RL(node *T)
{
    T->right=rotateright(T->right);
    T=rotateleft(T);
    return(T);
}

int BF(node *T)
{
    int lh,rh;
    if(T==NULL)
    return(0);
    if(T->left==NULL)
        lh=0;
    else
        lh=1+T->left->ht;
    if(T->right==NULL)
        rh=0;
    else
        rh=1+T->right->ht;
    return(lh-rh);
}

node * insert(node *T,int x)
{
    if(T==NULL)
    {
        T=(node*)malloc(sizeof(node));
        T->data=x;
        T->left=NULL;
        T->right=NULL;
    }
    else
        if(x > T->data)                
        {
            T->right=insert(T->right,x);
            if(BF(T)==-2)
                if(x>T->right->data)
                    T=RR(T);
                else
                    T=RL(T);
        }
        else
            if(x<T->data)
            {
                T->left=insert(T->left,x);
                if(BF(T)==2)
                    if(x < T->left->data)
                        T=LL(T);
                    else
                        T=LR(T);
            }
            T->ht=height(T);
            return(T);
}

void preorder(node *T)
{
    if(T!=NULL)
    {
        printf(" %d(Bf=%d)",T->data,BF(T));
        preorder(T->left);
        preorder(T->right);
    }
}
void main()
{
    node *root=NULL;
    int x,n,i;
    printf("\nEnter Total Number of Elements in the AVL Tree: ");
    scanf("%d",&n);
    printf("\nEnter AVL Tree Elements: ");
    root=NULL;
    for(i=0;i<n;i++){
        scanf("%d",&x);
        root=insert(root,x);
    }
    print2D(root);
    preorder(root);
}