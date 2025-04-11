#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Size 20
//stack practice, element is char
//Array stack

typedef struct {
	char ch[Size];
	int top;
} Arraystack;

void initArraystack(Arraystack* Astk) {
	if (!Astk) {
		printf("Astk pointer is NULL!\n");
		return;
	}
	Astk->top = -1;
	strcpy_s(Astk->ch, 20, "");
}

int isEmptyAs(Arraystack* Astk) {
	if (Astk->top == -1) {
		return 1;
	}
	else {
		return 0;
	}
}

int isFullAs(Arraystack* Astk) {
	if (Astk->top == Size - 1) {
		return 1;
	}
	else {
		return 0;
	}
}

void pushAstk(Arraystack* Astk, char a) {
	if (isFullAs(Astk)) {
		printf("Arraystack is Full, push failed!\n");
		return;
	}
	else {
		Astk->ch[++Astk->top] = a;
		return;
	}
}

char popAstk(Arraystack* Astk) {
	if (isEmptyAs(Astk)) {
		printf("Arraystack is empty, pop failed!\n");
	}
	return Astk->ch[Astk->top--];
}

Arraystack* uporder(Arraystack* Astk) {
	Arraystack* temp = (Arraystack*)malloc(1 * sizeof(Arraystack));

	if (!temp) {// temp == NULL
		printf("memory allocation failed!\n");
		return Astk;
	}

	initArraystack(temp);
	for (int i = 0; i < 10000; i++) {//maximum cycle times is 10000
		char curchar = popAstk(Astk);
		while (!isEmptyAs(temp) && curchar > temp->ch[temp->top]) {//temp stack is down order
			pushAstk(Astk, popAstk(temp));
		}
		pushAstk(temp, curchar);
		if (isEmptyAs(Astk)) {
			break;
		}
		else {
			continue;
		}
	}

	while (!isEmptyAs(temp)) {
		pushAstk(Astk, popAstk(temp));
	}

	free(temp);
	return(Astk);
}

typedef struct stackNode {
	char ch;
	struct stackNode* next;
} stackNode;



int isEmptyLs(stackNode* head) {
	if (!head->next) {//head->next == NULL
		return 1;
	}
	else {
		return 0;
	}
}

stackNode* popNode(stackNode* head) {
	stackNode* top = head->next;
	head->next = head->next->next;
	return top;
}

void pushNode(stackNode* head, stackNode* new) {
	new->next = head->next;
	head->next = new;
	return;
}

void freeAllNodes(stackNode* head) {
	stackNode* top = head->next;
	while (top) {//top != NULL
		free(popNode(head));
	}
	free(head);
	return;
}

void printAllNode(stackNode* head) {
	stackNode* p = head->next;
	while (p) {
		printf("%c", popNode(head)->ch);
	}
	printf("\n");
	return;
}

stackNode* uporder2(stackNode* head) {
	stackNode* head2 = malloc(1 * sizeof(stackNode));
	head2->next = NULL;

	
	for (int i = 0; i < 10000; i++) {//maximun cycle times is 10000
		stackNode* curNode = popNode(head);
		while (!isEmptyLs(head2) && curNode->ch > head2->next->ch) {
			pushNode(head, popNode(head2));
		}
		pushNode(head2, curNode);

		if (isEmptyLs(head)) {
			break;
		}
		else {
			continue;
		}
	}

	while (head2->next) {
		pushNode(head, popNode(head2));
		printAllNode(head);
		printf("\n");
	}
	freeAllNodes(head2);
	return head;
}

int main(void) {
	Arraystack* As = (Arraystack*)malloc(1 * sizeof(Arraystack));
	initArraystack(As);

	strcpy_s(As->ch, 20, "Hello, world!");
	As->top = (int)(strlen("Hello, world!")) - 1;

	printf("before arrange:\n%s\n", As->ch);
	As = uporder(As);
	printf("after arrange:\n%s\n", As->ch);
	free(As);

	stackNode* head = (stackNode*)malloc(1 * sizeof(stackNode*));

	if (!head) {
		printf("stack node memory allocation failed!\n");
	}

	head->next = NULL;

	stackNode* a[5];
	for (int i = 0; i < 5; i++) {
		a[i] = (stackNode*)malloc(1 * sizeof(stackNode));
		if (!a[i]) {
			printf("stack node memory allocation failed!\n");
		}
		pushNode(head, a[i]);
	}

	a[0]->ch = 'H';
	a[1]->ch = 'e';
	a[2]->ch = 'l';
	a[3]->ch = 'l';
	a[4]->ch = 'o';
	//printAllNode(head);
	head = uporder2(head);
	printAllNode(head);
}