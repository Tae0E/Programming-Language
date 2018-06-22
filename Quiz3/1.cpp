#include <stdio.h>

int isPrimaryNumer(int n)
{
	int i;
	
	for (i = 2; i <= n; i++)
	{
		if (n % i == 0)
			break;
	}
	if (i == n)
		return 1;
	else
		return 0;
}
void main()
{
	int a;
	
	for(a=2; a<=100; a++)
	{
		if(isPrimaryNumer(a)==1)
			printf("%d ", a);
	}
}