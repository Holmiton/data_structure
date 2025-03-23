#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
} Node;

Node* creathead(void) {
	Node* h = (Node*)calloc(1, sizeof(Node));
	h->next = NULL;
	return h;
}

void tailInsert(Node* tail, Node* new) {
	tail->next = new;
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

//infinite cycle
void printAllData(Node* head) {
	Node* p = head;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
	return;
}

void printThirdData(Node* head) {
	Node* p = head->next->next;
	printf("%d", p->data);
}

int JudNullChain(Node* head) {
	if (head->next = NULL) {
		return 1;
	}
	else {
		return 0;
	}
}

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


void arrangeBasedonX(Node* newhd, Node* head, int x) {
	Node* xp = findNode(head, x);
	newhd->data = 0;
	newhd->next = xp;
	Node* i = xp, * j = xp;
	Node* p = head;
	while (p != NULL) {
		if (p->data > x) {
			p->next = i;
			newhd->next = p;
			i = p;
		}
		else {
			j->next = p;
			j = p;
		}
		p = p->next;
	}
	return;
}

int main(void) {
	//tailInsert 6 Node
	Node* p = creathead();
	Node* head = p;
	for (int i = 0; i < 6; i++) {
		Node* new = (Node*)calloc(1, sizeof(Node));
		new->data = 2 * i + 1;
		p->next = new;
		p = p->next;
	}
	p->next = NULL;//tail Node

	printAllData(head);
}