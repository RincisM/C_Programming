#include<stdio.h>
#include<stdlib.h>

#define COUNT 10

struct node {
    int data;
	int key;
    struct node *lchild, *rchild;
};

struct node *create(int data, int key) {
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
	new->key = key;
    new->lchild = new->rchild = NULL;
    return new;
}

struct node *insert(struct node *root, int data, int key) {
    if(root == NULL)
        return create(data, key);
    else if(key > root->key)
        root->rchild = insert(root->rchild, data, key);
    else 
        root->lchild = insert(root->lchild, data, key);
    return root;
}

struct node *findByKey(struct node *root, int key) {
	if (!root)
		return NULL;
	if (root->key > key)
		return findByKey(root->lchild, key);
	else if (root->key < key)
		return findByKey(root->rchild, key);
	else if (root->key == key)
		return root;
	else
		return NULL;
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
    int ch, data, maxdata, mindata, count=0, ins=0, key;
    struct node *root=NULL;
    struct node *temp;
    while(1) {
        printf("\n\n1.Insert\n2.Find By Key\n3.Print tree\n4.Exit\n\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
				printf("\nEnter element to insert in tree: ");
				scanf("%d", &data);
				printf("\nEnter the key for the element: ");
				scanf("%d", &key);
				root = insert(root, data, key);
				++count;
				break;

			case 2:
					printf("\nEnter the key to search for : ");
					scanf("%d", &key);
					temp = findByKey(root, key);
					if (temp)
						printf("The value for the key %d is %d", temp->key, temp->data);
					else
						printf("No value found for the given key");
					break;
			case 3:
					printtree(root, 0);
					break;
                        
            case 4: exit(0);
            default: printf("\nInvalid choice\n");
        }
    }
}