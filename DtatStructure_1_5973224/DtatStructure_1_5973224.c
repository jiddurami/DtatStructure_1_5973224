#include <stdio.h>

int main() {
	int n;
	printf("정수를 입력하세요 : ");
	scanf_s("%d", &n);
	printf("입력된 정수의 32비트 표현 : ");
	for (int i = 31; i >= 0; i--)
	{
		int r = n >> i & 1;
		printf("%d", r);
	}
	return 0;
}