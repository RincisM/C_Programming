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
node * Delete(node *T,int x)
{       node *p;

    if(T==NULL)
    {
        return NULL;
    }
    else

        if(x > T->data)          
        {
            T->right=Delete(T->right,x);
            if(BF(T)==2)
                if(BF(T->left)>=0)
                    T=LL(T);
                else
                    T=LR(T);
        }
        else
            if(x<T->data)
                {
                    T->left=Delete(T->left,x);
                    if(BF(T)==-2)     
                        if(BF(T->right)<=0)
                            T=RR(T);
                        else
                            T=RL(T);
                }
            else
              {
               
                  if(T->right !=NULL)
                  { 
                      p=T->right;
                      while(p->left != NULL)
                      p=p->left;

                      T->data=p->data;
                      T->right=Delete(T->right,p->data);
                      if(BF(T)==2)             
                        if(BF(T->left)>=0)
                            T=LL(T);
                        else
                            T=LR(T);
                   }
                  else
                   return(T->left);

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
void inorder(node *T)
{
    if(T!=NULL)
    {
        inorder(T->left);
        printf(" %d(Bf=%d)",T->data,BF(T));
        inorder(T->right);
    }
}
void postorder(node *T)
{
    if(T!=NULL)
    {
    	
        postorder(T->left);
        postorder(T->right);
        printf(" %d(Bf=%d)",T->data,BF(T));
    }
}
void main()
{
    node *root=NULL;
    int x,n,i, j;
    printf("\nEnter Total Number of Elements in the AVL Tree: ");
    scanf("%d",&n);
    printf("\nEnter AVL Tree Elements: ");
    for(i=0;i<n;i++){
        scanf("%d",&x);
        root=insert(root,x);
    }
    print2D(root);
    printf("Enter an Element to Delete: ");
    scanf("%d", &j);
    root=Delete(root,j);
    print2D(root);
    printf("\nThe Preorder Sequence is: ");
    preorder(root);
    printf("\nThe Postorder Sequence is: ");
    postorder(root);
    printf("\nThe Inorder Sequence is: ");
    inorder(root);
}