#include <stdio.h>
#include <stdlib.h>
#define COUNT 10
struct node
{
	int data;
	struct node *left;
	struct node *right;
};

void printArray(int ints[], int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		printf("%d ", ints[i]);
	}
	printf("\n");
}

void printPathsRecur(struct node *node, int path[], int pathLen)
{
	if (node == NULL)
		return;

	path[pathLen] = node->data;
	pathLen++;

	if (node->left == NULL && node->right == NULL)
	{
		printArray(path, pathLen);
	}
	else
	{
		printPathsRecur(node->left, path, pathLen);
		printPathsRecur(node->right, path, pathLen);
	}
}

void printPaths(struct node *node)
{
	int path[1000];
	printPathsRecur(node, path, 0);
}

struct node *newnode(int data)
{
	struct node *node = (struct node *)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

void printtree(struct node *root, int space) {
    if (root == NULL)
        return;
    space += COUNT;
    printtree(root->right, space);
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);
    printtree(root->left, space);
}

struct node *insertLevelWise(int arr[], struct node *root, int i, int n) {
   if (i < n) {
      struct node *temp = newnode(arr[i]);
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
	scanf("%d", &s);

	for (int i = 0; i < s; i++)
	{
		printf("Enter Element %d: ", i + 1);
		scanf("%d", &arr[i]);
	}
	struct node *root = insertLevelWise(arr, root, 0, s);
	printtree(root, 0);
    printf("The Paths from the Root Node are: \n");
	printPaths(root);
	return 0;
}