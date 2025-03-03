#include <stdio.h>

typedef struct{
	int ID;
	int money;
	int billday;
}User;

int main_3(void) {
	User users[10];
	for (int i = 0; i < 10; i++) {
		users[i].ID = i;
		users[i].money = 111 * i + 345;
		users[i].billday = 20 + i;
	}
	for (int i = 0; i < 10; i++) {
		printf("userID:%d has %d RMB,whose billday is %d every month.\n", users[i].ID, users[i].money, users[i].billday);
	}
	return 0;
}