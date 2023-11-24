#include<stdio.h>
#include<stdlib.h>
#define Count 10

struct node {
    int data;
    struct node*left, *right;
};
typedef struct node tree;

tree*create(int data) {
    tree*root = (tree*)malloc(sizeof(tree));
    root->data = data;
    root->left = root->right = NULL;
    return root;
}

tree*insertLevel(int a[], tree*root, int i, int n) {
    if(i<n) {
        tree*temp = create(a[i]);
        root = temp;
        root->left = insertLevel(a, root->left, 2*i+1, n);
        root->right = insertLevel(a, root->right, 2*(i+1), n);
    }
    return root;
}

void printtree(tree*root, int space) {
    if(root==NULL)
        return;
    space = space +Count;
    printtree(root->right, space);
    printf("\n");
    for(int i=Count; i<space; i++)
        printf(" ");
    printf("%d ", root->data);
    printtree(root->left, space);
}

unsigned int count(tree*root) {
    if(root==NULL)
        return 0;
    return (1+count(root->left) +count(root->right));
}

void main() {
    int a[100], n, i;
    printf("Enter the size of the Arry: ");
    scanf("%d", &n);
    printf("Enter the Nodes: ");
    for(i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    tree*root = insertLevel(a, root, 0, n);
    printtree(root, 0);
    unsigned int nodes = count(root);
    printf("%d", nodes);
}
