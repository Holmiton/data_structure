#include <stdio.h>
#include <math.h>
#include <time.h>

//first O(n)
int PrmJudge1(int n) {
	for (int i = 2; i < n; i++) {
		if (n % i == 0) {
			return 0;
		}
	}
	return 1;
}

//second O(sqrt(n))
int PrmJudge2(int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			return 0;
		}
	}
	return 1;
}

//exp1-4
__int64 AcmltFactorial(int n) {
	int x = 0;		//result
	int fac = 1;	//factorial
	for (int i = 1; i <= n; i++) {
		fac *= i;
		x += fac;
	}
	return x;
}

int main(void) {
	printf("enter a number for exp1-3: ");
	int x;
	scanf_s("%d", &x);

	int counter = 0;

	clock_t start = clock();	//start timepoint
	for (int i = 2; i <= x; i++) {
		if (PrmJudge1(i)) {
			counter++;
		}
	}

	clock_t end = clock();

	double TimeSpend = (double)(end - start) / CLOCKS_PER_SEC;
	printf("time spend of first method is %f\n", TimeSpend);

	printf("there's %d prime number\n", counter);

	counter = 0;				//refresh counter
	//second method
	start = clock();			//start timepoint
	for (int i = 2; i <= x; i++) {
		if (PrmJudge2(i)) {
			counter++;
		}
	}
	end = clock();

	TimeSpend = (double)(end - start) / CLOCKS_PER_SEC;
	printf("time spend of second method is %f\n", TimeSpend);

	printf("there's %d prime number\n", counter);

	//exp1-4
	printf("enter a number for exp1-4:");
	int y = 0;
	scanf_s("%d", &y);
	printf("\n%lld", AcmltFactorial(y));

	return 0;
}