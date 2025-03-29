#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
} Node;

void printAll(int* arry, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", arry[i]);
	}
	printf("\n");
	return;
}

int next(int i, int n) {		//next i in cycle
	if (++i == n) {
		i = 0;
	}
	return i;
}

//all persons are initialized as 1, deleted as 0, time:O(n), space:O(n)
int finalone(int* persons, int n) {		//n = number of persons
	int nop = n;
	int i = 0;//subindex of persons, 0 to n-1
	int cntr = 0;//counter of 1, 2, 3
	for (int j = 0; j < 10000; j++) {//maximum cycle times is 10000
		
		while (!persons[i]) {//person[i] is 0, in, 1, out	
			i = next(i, n);
		}
		//check delete it or not
		cntr++;
		if (cntr == 3) {
			persons[i] = 0;
			nop--;
			cntr = 0;
		}
		if (nop == 1) {//inperfect, but it runs well, in fact it do when nop change from 2 to 1
			while (i = next(i, n)) {//find the final one
				if (persons[i]) {
					return i;
				}
			}
		}
		else {
			i = next(i, n);
		}
	}
	printf("find final one failed!\n");
}

//void IniCycList(Node* head) { //tailnode->next = head, already
//	int i = 0;
//	head->data = i;
//	Node* p = head->next;
//	while (p != head) {
//		p->data = ++i;
//		p = p->next;
//	}
//	return;
//}

int finalone2(Node* head, int n) {
	/*n = number of Nodes, assume data are initialized as 1 to n
	time: O(n), space: O(n)*/
	Node* p = head;
	int cntr = 0;
	for (int i = 0; i < 10000; i++) {
		cntr++;
		if (cntr == 2) {// the node before 3
			Node* temp = p->next;
			p->next = p->next->next;
			free(temp);
			p = p->next;
			cntr = 0;
			n--;
			if (n == 1) {//p->next stores address of p, p = p->next, address of p gives to p, p stores address of p
				return p->data;
			}
		}
		else {
			p = p->next;
		}
	}
}

int main(void) {
	int kids[5] = { 0 };
	for (int i = 0; i < 5; i++) {//all are initialized as 1
		kids[i] = 1;
	}
	printf("final one's subindex is %d\n", finalone(kids, 5));

	Node* head = (Node*)malloc(1 * sizeof(Node));
	Node* p = head;
	p->data = 1;
	for (int i = 2; i < 6; i++) {
		Node* s = (Node*)malloc(1 * sizeof(Node));
		s->data = i;
		p->next = s;
		p = p->next;
	}
	p->next = head;//a cycle list
	printf("final one's number is %d\n", finalone2(head, 5));
	return 0;
}
