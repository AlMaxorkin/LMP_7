#include "list.h"

using namespace std;

void push(Node** head_ref, int new_data)
{
	Node* new_node = new Node;
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void createPairs(NodePair** head_ref, Node* a, Node* b)
{
	Node* temp_a = a;
	Node* temp_b = b;
	while (temp_a != NULL || temp_b != NULL)
	{
		if ((temp_b == NULL && temp_a != NULL) || (temp_a == NULL && temp_b != NULL))
		{
			cout << "A and must have the same number of elements";
			return;
		}
		NodePair* new_node = new NodePair;
		new_node->x = temp_a->data;
		new_node->y = temp_b->data;
		temp_a = temp_a->next;
		temp_b = temp_b->next;
		new_node->next = (*head_ref);
		(*head_ref) = new_node;
	}
}

void printList(Node* head)
{
	Node* temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";	
		temp = temp->next;
	}
}

void printPairs(NodePair* head)
{
	NodePair* temp = head;
	while (temp != NULL)
	{
		cout << "("<< temp->x << ", " << temp->y << ")  ";
		temp = temp->next;
	}
}

void sortedInsert(Node** head_ref,  Node* new_node)
{
	Node* current;
	/* Special case for the head end */
	if (*head_ref == NULL || (*head_ref)->data >= new_node->data)
	{
		new_node->next = *head_ref;
		*head_ref = new_node;
	}
	else
	{
		/* Locate the node before the point of insertion */
		current = *head_ref;
		while (current->next != NULL && current->next->data < new_node->data)
		{
			current = current->next;
		}
		new_node->next = current->next;
		current->next = new_node;
	}
}

void insertionSort(Node** head_ref)
{
	// Initialize sorted linked list 
	Node* sorted = NULL;

	// Traverse the given linked list and insert every 
	// node to sorted 
	Node* current = *head_ref;
	while (current != NULL)
	{
		// Store next for next iteration 
		Node* next = current->next;

		// insert current in sorted linked list 
		sortedInsert(&sorted, current);

		// Update current 
		current = next;
	}

	// Update head_ref to point to sorted linked list 
	*head_ref = sorted;
}