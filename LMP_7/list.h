#pragma once
#include <iostream>

struct Node
{
	int data;
	Node* next;
};

struct NodePair
{
	int x;
	int y;
	NodePair* next;
};

void push(Node** head_ref, int new_data);
void printList(struct Node* head);
void insertionSort(Node** head_ref);
void createPairs(NodePair** head_ref, Node* a, Node* b);
void printPairs(NodePair* head);

