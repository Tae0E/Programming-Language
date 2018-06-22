#include <stdio.h>

int main()
{
	int n, a;
	printf("ют╥б : ");
	scanf("%d", &n);

	for (a = 2; a < n / 2 + 1; a++)
	{
		if (n%a == 0)
		{
			printf("False\n");
			break;
		}
	}
	if(n%a != 0)
	{
		printf("True\n");
	}
	if (n==2)
	{
		printf("True\n");
	}
}