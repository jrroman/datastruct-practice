/**
 * 18 Linked List Problems
 * Stanford University
 * http://cslibrary.stanford.edu/105/LinkedListProblems.pdf
 *
 * Solutions by:
 * John R. Roman
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
	int		data;
	struct node*	next;
};
/**
 * Create base Linked list of {1,2,3}
 * @return | Head node of list
 */
struct node* oneTwoThree() {
	struct node* head = malloc(sizeof(struct node));
	struct node* second = malloc(sizeof(struct node));
	struct node* third = malloc(sizeof(struct node));

	head->data = 1;
	head->next = second;

	second->data = 2;
	second->next = third;

	third->data = 3;
	third->next = NULL;

	return head;
}
/**
 * Push new nodes to the head of list
 * @param headRef | Reference pointer to the Head Pointer
 * @param data	  | integer associated with node
 */
void push(struct node** headRef, int data) {
	struct node* next = malloc(sizeof(struct node));

	next->data = data;
	next->next = *headRef;
	*headRef = next;
}
/**
 * Walk the list structure printing node values
 * @param head | the list head pointer
 */
void print(struct node* head) {
	struct node* current = head;

	int i = 1;
	while (current != NULL) {
		printf("node: %d\ndata: %d\nnext: %p\n====\n", i, current->data, current->next);
		i++;
		current = current->next;
	}
}
/**
 * Problem 1 - Count()
 * Counts the number of times a value is repeated in the list
 * @param  head      | list head pointer
 * @param  searchFor | integer to search in the list
 * @return           | Returns the number of occurances
 */
int count(struct node* head, int searchFor) {
	struct node* current = head;

	int counter = 0;
	while (current != NULL) {
		if (current->data == searchFor) {
			counter++;
		}
		current = current->next;
	}
	return counter;
}
/**
 * Problem 2 - GetNth()
 * Takes an index and a head pointer, and returns the node data at the index specified
 * @param  head | list head pointer
 * @param  idx  | index to return
 * @return      | the currentnode->data
 */
int getNth(struct node* head, int idx) {
	struct node* current = head;
	if (idx == 0) {
		return current->data;
	} else {
		int iter = 0;
		while (current != NULL && iter != idx) {
			iter++;
			current = current->next;
		}
		return current->data;
	}
}
/**
 * Delete list will deallocate all of the nodes memory, and will set head pointer to null
 * @param head | Reference pointer to the head pointer
 */
void deleteList(struct node** head) {
	struct node* current = head;
	struct node* next;

	while (current->next != NULL) {

	}
}
/**
 * Run Linked List Operations
 * @return | int
 */
int main() {
	struct node* head;

	head = oneTwoThree();
	push(&head, 22);
	push(&head, 3);
	print(head);
	printf("GetNth returned: %d\n", getNth(head, 3));
	printf("Count found %d occurances in the list\n", count(head, 3));
	return 0;
}