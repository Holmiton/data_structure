#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
}Node;

int main(void) {
	Node Mynodes[6];

	Mynodes[0].data = 100; Mynodes[0].next = &Mynodes[4];
	Mynodes[1].data = 400; Mynodes[1].next = &Mynodes[3];
	Mynodes[2].data = 300; Mynodes[2].next = &Mynodes[1];
	Mynodes[3].data = 500; Mynodes[3].next = NULL;
	Mynodes[4].data = 200; Mynodes[4].next = &Mynodes[2];
	Mynodes[5].data = -1; Mynodes[5].next = NULL;			//NULL is replaced by -1 as the end of list

	Node curnode = Mynodes[0];

	printf("所有data：\n");
	int i = 0;			//Nodes counter
	while (curnode.data != -1) {
		++i;
		printf("%d ", curnode.data);
		if (curnode.next != NULL) {
			curnode = *curnode.next;
		}
		else {
			break;
		}		
	}
	
	printf("fast and slow:kdfsaafbl\n");

	//快慢步
	Node* fast = &(Mynodes[0]), * slow = fast;	//start node are same

	if (fast == NULL) {
		printf("startnode address is NULL!");
		return 0;
	}
	else {
		do {
			printf("%d \n", (*fast).data);
			fast = (*fast).next;
			if (fast == NULL) {
				printf("there's only one node %d, or the quantity of nodes is even.");
				return 0;
			}
			
			fast = (*fast).next;			//fast move 2 steps
			slow = (*slow).next;				//slow move 1 step

		} while (fast != NULL);

		if (slow == NULL) {
			printf("the middle node address is NULL");
			return 0;
		}
		printf("middle data is %d\n", (*slow).data);
	}
	

	return 0;
}