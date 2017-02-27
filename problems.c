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
struct node*
oneTwoThree()
{
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
void
push(struct node** headRef, int data)
{
	struct node* next = malloc(sizeof(struct node));

	next->data = data;
	next->next = *headRef;
	*headRef = next;
}
/**
 * Walk the list structure printing node values
 * @param head | the list head pointer
 */
void
print(struct node* head)
{
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
int
count(struct node* head, int searchFor)
{
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
int
getNth(struct node* head, int idx)
{
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
 * Problem 3 - DeleteList()
 * Delete list will deallocate all of the nodes memory, and will set head pointer to null
 * @param head | Reference pointer to the head pointer
 */
void
deleteList(struct node** headRef)
{
	struct node* current = *headRef;
	struct node* next;

	while (current != NULL) {
		next = current->next;
		free(current);
		current = next;
	}
	*headRef = NULL;
}
/**
 * Problem 4 - Pop()
 * Remove the first node from the list and return its data value
 * @param  headRef | Reference pointer to the head pointer
 * @return         | the data value from the first node
 */
int
pop(struct node** headRef)
{
	struct node* head = *headRef;
	int result;
	// make sure head is not null
	assert(head != NULL);
	// set the result to the heads data
	result = head->data;
	// set the head node to the next node
	*headRef = head->next;
	// deallocate memory from first node
	free(head);
	// return the data value from first node
	return result;
}
/**
 * Problem 5 - InsertNth()
 * Insert node into index specified
 * @param headRef | Reference pointer to the head pointer
 * @param data    | node data value
 * @param idx     | index to insert node
 */
void
insertNth(struct node** headRef, int data, int idx)
{
	if (idx == 0 || headRef == NULL) {
		push(headRef, data);
	} else {
		struct node* current = *headRef;
		struct node* newnode = malloc(sizeof(struct node));
		int iter;

		newnode->data = data;
		for (iter = 0; iter < idx - 1; iter++) {
			current = current->next;
		}
		newnode->next = current->next;
		current->next = newnode;
	}
}
/**
 * Run Linked List Operations
 * @return | int
 */
int
main(void)
{
	struct node* head;

	head = oneTwoThree();
	push(&head, 22);
	push(&head, 3);
	insertNth(&head, 3023, 2);
	print(head);
	printf("GetNth returned: %d\n", getNth(head, 3));
	printf("Count found %d occurances in the list\n", count(head, 3));
	printf("Popped result: %d\n", pop(&head));
	printf("Popped result: %d\n", pop(&head));
	deleteList(&head);
	return 0;
}