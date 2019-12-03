#include <iostream>
#include "list.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	Node* a = NULL;
	Node* b = NULL;
	
	push(&a, 5);
	push(&a, 20);
	push(&a, 4);
	push(&a, 3);
	push(&a, 30);

	push(&b, 10);
	push(&b, 1);
	push(&b, -2);
	push(&b, 16);
	push(&b, 7);


	cout <<("Linked List before sorting \n");
	printList(a);
	cout << endl;
	printList(b);

	insertionSort(&a);
	insertionSort(&b);

	cout <<("\nLinked List after sorting \n");
	printList(a);
	cout << endl;
	printList(b);

	NodePair* Pairs = NULL;
	createPairs(&Pairs, a, b);
	cout << endl;
	printPairs(Pairs);

	system("pause");
	return 0;
}