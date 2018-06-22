#include <stdio.h>

void binary(int n)
{
	int a, b, count=0;
	char s[8];
	for(a=0; n>=1; a++)
	{
		if(n%2==1)
			s[a] = 1;
		else
			s[a] = 0;
		n=n/2;
		count++;
	}
	for(b=count-1; b>=0; b--)
		printf("%d", s[b]);
}
void main()
{
	int num, b;


	printf("ют╥б : ");
	scanf("%d", &num);

	binary(num);
}