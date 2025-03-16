#include <stdio.h>
#include <stdlib.h>
//wrong edition
typedef struct {
	int data[200];
	int length;
}Sqlist;

int* LinkListup(Sqlist* L1, Sqlist* L2) {
	int AllLength = L1->length + L2->length;
	
	if (AllLength <= 200) {
		for (int i = L1->length; i < AllLength; i++) {
			L1->data[i] = L2->data[L2->length - 1 - (i - L1->length)];//(i - L1->length) is the counter of steping back in L2->data
		}
		return L1->data;
	}
	else {
		int* temp = (int*)malloc(sizeof(int) * AllLength);
		for (int i = 0; i < L1->length; i++) {
			temp[i] = L1->data[i];
		}
		for (int i = L1->length; i < AllLength; i++) {
			temp[i] = L2->data[L2->length - 1 - (i - L1->length)];//(i - L1->length) is the counter of steping back in L2->data
		}
		int* result = temp;
		free(temp);
		return result;
	}
}

int main(void) {
	Sqlist L1, L2;
	for (int i = 0; i < 99; i++) {
		L1.data[i] = 2 * i + 1;
		L1.length = 100;
		L2.data[i] = 200 - 2 * i;
		L2.length = 100;
	}
	
	int* res = LinkListup(&L1, &L2);

	int counter = 0;		//to find appropriate point to change line
	for (int i = 0; i < 200; i++) {
		printf("%d\t", res[i]);
		if (++counter == 10) {
			printf("\n");
		}
	}
	return 0;
}