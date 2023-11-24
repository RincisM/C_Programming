#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct Node {
    int data;
    struct Node* next;
};
int largestElement(struct Node* head)
{
    int max = INT_MIN;
    while (head != NULL) {
        if (max < head->data)
            max = head->data;
        head = head->next;
    }
    return max;
}
int smallestElement(struct Node* head)
{
    int min = INT_MAX;
    while (head != NULL) {
        if (min > head->data)
            min = head->data;
        head = head->next;
    }
    return min;
}
void push(struct Node** head, int data)
{
    struct Node* newNode =
        (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = (*head);
    (*head) = newNode;
}

int main()
{
    struct Node* head = NULL;
    int limit, item, to_find;

	printf("Enter the amount of data to store: ");
	scanf("%d", &limit);

	for (int i = 0; i < limit; i++) {
		printf("Enter the value: ");
		scanf("%d", &item);
		push(&head, item);
	}
    

    printf("Maximum element in linked list: ");
    int max_element = largestElement(head);
    printf("%d\n",max_element);
    printf("Minimum element in linked list: ");
    int small = smallestElement(head);
     printf("%d\n",small);
  
    return 0;
}