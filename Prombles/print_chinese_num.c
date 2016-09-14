#include "stdio.h"

int main() {
	int n;
	int sum = 0;
	scanf("%d", &n);
	while (n) {
		sum += n % 10;
		n /= 10;
	}
	printf("%d\n", sum);
	p(sum);
	return 0;
}

void p(int n) {
	if (n) {
		p(n / 10);
		if (n >= 10)
			printf(" ");
		switch (n % 10) {
		case 0: printf("ling");
			break;
		case 1: printf("yi");
			break;
		case 2: printf("er");
			break;
		case 3: printf("san");
			break;
		case 4: printf("si");
			break;
		case 5: printf("wu");
			break;
		case 6: printf("liu");
			break;
		case 7: printf("qi");
			break;
		case 8: printf("ba");
			break;
		case 9: printf("jiu");
			break;
		}
	}
}