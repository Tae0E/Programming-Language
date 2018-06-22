#include <stdio.h>

int main()
{
	int num;
	int a, b, c;
	int N;
	int sum=0;

	printf("입력 : ");
	scanf("%d", &num);

	for (b = 1; num > b; b = b * 10)
	{
		N = num / b;
		c = N % 10;
		sum = sum + c;	
	}

		printf("자리수 합 : %d", sum);
}