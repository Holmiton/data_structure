#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int data[200];
	int length;
}Sqlist;

int* LinkListup(Sqlist* L1, Sqlist* L2, int* tempAdr) {
	int AllLength = L1->length + L2->length;
	
	
	int i = 0, j = L2->length - 1, k = 0;//index i in L1 from 0 to L1->length, j in L2 from L2->length to 0, k in tempAdr increase from 0
	while (k < AllLength) {
		tempAdr[k++] = (L1->data[i] < L2->data[j]) ? L1->data[i++] : L2->data[j--];

		if (i >= L1->length) {
			while(k < AllLength) {
				tempAdr[k++] = L2->data[j--];
			}
			break;
		}
		if (j <= 0) {
			while (k < AllLength) {
				tempAdr[k++] = L1->data[i++];
			}
			break;
		}
	}
	
	return tempAdr;
}

int main(void) {
	Sqlist L1, L2;
	L1.length = 100;
	L2.length = 100;
	for (int i = 0; i < 99; i++) {
		L1.data[i] = 2 * i + 1;	
		L2.data[i] = 300 - 2 * i;
	}
	
	int* res = NULL;
	res = LinkListup(&L1, &L2, res);

	int counter = 0;		//to find appropriate point to change line
	for (int i = 0; i < 200; i++) {
		printf("%d\t", res[i]);
		if (++counter%10 == 0) {
			printf("\n");
		}
	}
	return 0;
}