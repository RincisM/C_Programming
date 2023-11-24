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

bool is_sorted() {
	node_t *current = head->next;
	node_t *prev = head;
	int count = 0;

	while (current != NULL) {
		if (prev->item < current->item)
			return false;
		prev = prev->next;
		current = current->next;
	}

	return true;
}


int main() {
	int limit, item;

	printf("Enter the amount of data to store: ");
	scanf("%d", &limit);

	for (int i = 0; i < limit; i++) {
		printf("Enter the value: ");
		scanf("%d", &item);
		insert(item);
	}
	
	bool sorted = is_sorted();
	if (sorted) {
		printf("The given list is sorted\n");
	} else {
		printf("The given list is not sorted\n");
	}

}