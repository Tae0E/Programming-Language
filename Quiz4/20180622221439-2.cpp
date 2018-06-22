#include <stdio.h>

void main()
{
	char num[10];
	int result, n;
	gets_s(num);
	
	printf("변환결과 : ");
	for (n = 0; num[n] != '\0'; n++)
	{
		result = num[n]-48;
		printf("%d", result);
	}
}