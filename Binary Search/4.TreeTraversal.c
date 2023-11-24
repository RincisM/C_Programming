#include<stdio.h>
#include<stdlib.h>

#define COUNT 10

struct node {
    int data;
	struct node *lchild, *rchild;
};

struct node *create(int data) {
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    new->lchild = new->rchild = NULL;
    return new;
}

struct node *insert(struct node *root, int data) {
    if(root == NULL)
        return create(data);
    else if(data > root->data)
        root->rchild = insert(root->rchild, data);
    else 
        root->lchild = insert(root->lchild, data);
    return root;
}
void inorder(struct node *root) {
  if(root){
    inorder(root->lchild);
    printf("%d\t",root->data);
    inorder(root->rchild);
  }
}

void preorder(struct node *root) {
  if(root){
    printf("%d\t",root->data);
    preorder(root->lchild);
    preorder(root->rchild);
  }
}

void postorder(struct node *root) {
  if(root){
    postorder(root->lchild);
    postorder(root->rchild);
    printf("%d\t",root->data);
  }
}

void printtree(struct node *root, int space) {
    if (root == NULL)
        return;
    space += COUNT;
    printtree(root->rchild, space);
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);
    printtree(root->lchild, space);
}

int main() {
    int ch, data;
    struct node *root=NULL;
    struct node *temp;
    printf("Enter the Number of nodes to be created: ");
    scanf("%d", &ch);
    for(int i=0; i<ch; i++) {
        printf("\nEnter the Element: ");
        scanf("%d", &data);
        root = insert(root, data);
    }
    if(root == NULL)
        printf("\nTree empty\n");
    else  
        printf("\nThe Inorder Traversal is: ");
        inorder(root);
        printf("\nThe Preorder Traversal is: ");
        preorder(root);
        printf("\nThe Postorder Traversal is: ");
        postorder(root);
        printtree(root, 0);
}