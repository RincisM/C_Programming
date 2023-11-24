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
    int ch, data, maxdata, mindata, count=0, ins=0;
    struct node *root=NULL;
    struct node *temp;
    while(1) {
        printf("\n\n1. Insert\n2. Total node count\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1: printf("\nEnter element to insert in tree: ");
                    scanf("%d", &data);
                    root = insert(root, data);
                    ++count;
                    break;

            case 2: printf("\nTotal number of nodes: %d", count);
                    break;

            
            case 3: printtree(root, 0);
                    break;

            case 4: exit(0);
            default: printf("\nInvalid choice\n");
        }
    }
}