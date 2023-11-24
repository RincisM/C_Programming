#include<stdio.h>
#include<stdlib.h>
#define COUNT 10

struct Node
{
	int key;
	struct Node *left, *right;
};
struct Node *newNode(int data)
{
	struct Node *node = (struct Node*)malloc(sizeof(struct Node));
	node->key = data;
	node->right = node->left = NULL;
	return node;
}

unsigned int countNodes(struct Node* root)
{
	if (root == NULL)
		return (0);
	return (1 + countNodes(root->left) + countNodes(root->right));
}

void printtree(struct Node *root, int space) {
    if (root == NULL)
        return;
    space += COUNT;
    printtree(root->right, space);
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->key);
    printtree(root->left, space);
}

struct Node *insertLevelWise(int arr[], struct Node *root, int i, int n) {
   if (i < n) {
      struct Node *temp = newNode(arr[i]);
      root = temp;
      root->left = insertLevelWise(arr, root->left, 2 * i + 1, n);
      root->right = insertLevelWise(arr, root->right, 2 *(i + 1), n);
   }
   return root;
}

int main()
{
	int arr[20];
    int s;
   printf("Enter the size of Array: ");
   scanf("%d",&s);

   for(int i=0;i<s;i++)
   {
       printf("Enter Element %d: ",i+1);
       scanf("%d",&arr[i]);
   }
   struct Node *root = insertLevelWise(arr, root, 0, s);
   printtree(root, 0);
   unsigned int node_count = countNodes(root);

	if (node_count%2==0)
		printf("It is not a tournament tree\n");
	else
		printf("It is a tournament tree\n");
	return (0);
}