#include <stdio.h>

int main()
{
	int N;
	int a, b, c;
	printf("입력(3자리) : ");
	scanf("%d", &N);

	a = N / 100;
	b = (N % 100) / 10;
	c = N % 10;

	printf("%d", a + b + c);
}
/*
3자리의 정수를 입력 받은 후, 각 자릿수의 합계를 출력하라.
입력(3자리): 123
출력: 6
*/