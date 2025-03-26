#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
} Node;


void tailInsert(Node* tail, Node* new) {
	tail->next = new;
	new->next = NULL;
}

void freeAllNodes(Node* head) {
	Node* p = head;
	while (1) {
		Node* np = p->next;
		free(p);
		p = np;
		if (p != NULL) {
			continue;
		}
		else {
			break;
		}
	}

}

void printAllData(Node* head) {
	Node* p = head;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
	return;
}

void printThridData(Node* head) {
	Node* p = head->next->next;
	printf("%d", p->data);
}

//int JudNullChain(Node* head) {
//	if (head->next = NULL) {
//		return 1;
//	}
//	else {
//		return 0;
//	}
//}

Node* findNode(Node* head, int a) {
	Node* p = head;
	while (p != NULL) {
		if (p->data == a) {
			return p;
		}
		else {
			p = p->next;
			continue;
		}
	}
	printf("No such Node!");
	return head;
}

void InsertNode(int position, Node* head, Node* f) {
	Node* p = head;
	int front = position - 1;
	for (int i = 0; i < front - 1; i++) {		//p = p->next do (front - 1) times
		p = p->next;
	}
	//now p points to frontNode
	f->next = p->next;
	p->next = f;
	return;
}

void delNode(int position, Node* head) {
	Node* p = head;
	int front = position - 1;
	for (int i = 0; i < front - 1; i++) {		//p = p->next do (front - 1) times
		p = p->next;
	}
	//now p points to frontNode
	//may free p->next?
	p->next = (p->next)->next;
}


Node* arrangeBasedonX(Node* head, int x) {		
	Node* moreListhd = (Node*)calloc(1, sizeof(Node*));
	Node* lessListhd = (Node*)calloc(1, sizeof(Node*));
	Node* j = moreListhd;		//more list
	Node* i = lessListhd;		//less list

	if (i == NULL || j == NULL) {		//avoid NULL pointer
		printf("Memory allocation failed!\n");
		return head;
	}

	Node* p = head;		 //search through original linklist
	while (p != NULL) {
		if (p->data >= x) {
			j->next = p;
			j = j->next;
		}
		else {
			i->next = p;
			i = i->next;
		}
		p = p->next;
	}

	j->next = NULL;
	//link 2 list
	i->next = moreListhd->next;


	return lessListhd;
}

int main(void) {
	//tailInsert 6 Node
	Node* p = (Node*)calloc(1, sizeof(Node*));
	p->data = 0;
	p->next = NULL;//creat a head

	if (p->next == NULL) {
		printf("null chain\n");
	}
	else {
		printf("not a null chain\n");
	}

	Node* head = p;
	for (int i = 0; i < 6; i++) {
		Node* new = (Node*)calloc(1, sizeof(Node));
		new->data = (-2) * i + 1;
		p->next = new;
		p = p->next;
	}
	p->next = NULL;//tail Node

	printf("All nodes : \n");
	printAllData(head);
	printf("\n");

	Node* a = (Node*)calloc(1, sizeof(Node*));
	a->data = 1;
	tailInsert(p, a);
	p = a; //tailnode

	printf("tailinsert 1 :\n");
	printAllData(head);
	printf("\n");

	printf("Thrid data :\n");
	printThridData(head);
	printf("\n");
	
	Node* b = (Node*)calloc(1, sizeof(Node*));
	b->data = 10;
	b->next = NULL;
	printf("insert in the 3 position :\n");
	InsertNode(3, head, b);
	printAllData(head);
	printf("\n");

	
	
	delNode(3, head);
	printf("delete Node in the 3 position :\n");
	printAllData(head);
	printf("\n");

	//printf("%d", findNode(head, -5)->data);

	head = arrangeBasedonX(head, -5);
	printf("the arranged linklist(original head and new head included) :\n");
	printAllData(head);
	free(head);

	freeAllNodes(head);
	return 0;
}
