#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node node_t;

struct Node {
	int item;
	node_t *next;
};

node_t *head = NULL;

void insert(int item) {
	node_t *node = (node_t *)malloc(sizeof(node_t));
	node->item = item;
	node->next = head;
	head = node;
}


int display() {
	node_t *current = head;
	int count = 0;


	while (current != NULL) {
		printf("%d - ", current->item);
		current = current->next;
	}

	return count;
}

int main() {
	int number;
	printf("Enter the number : ");
	scanf("%d", &number);

	while (number > 0) {
		int item = number % 10;
		insert(item);
		number /= 10;
	}

	display();
}