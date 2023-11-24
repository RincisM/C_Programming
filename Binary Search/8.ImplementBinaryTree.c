#include<stdio.h>
#include<stdlib.h>

#define COUNT 10

struct tree {
    int data;
	struct node *lchild, *rchild;
};
typedef struct tree tree;
tree *create() {
    tree *newnode;
    int x;
    newnode = (tree *)malloc(sizeof(tree));
    printf("\nEnter the Data: ");
    scanf("%d", &x);
    newnode->data = x;
    if(newnode->data==-1) {
        return 0;
    }
    printf("Enter the Data for Left Node of %d", newnode->data);
    newnode->lchild = create();
    printf("Enter the Data for Right Node of %d", newnode->data);
    newnode->rchild = create();
    return newnode;
}

void printtree(tree *root, int space) {
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

void deleteTree(tree *root){
    if(root == NULL)
        return;
    /* Delete Left sub-tree */
    deleteTree(root->lchild);
    /* Delete right sub-tree */
    deleteTree(root->rchild);
     
    /* At last, delete root node */
    printf("Deleteing Node : %d\n", root->data);
    free(root);
     
    return;
}

int main() {
    tree*root;
    root = 0;
    root = create();
    if(root == NULL)
        printf("\nTree empty\n");
    else  
        printtree(root, 0);
    deleteTree(root);
}