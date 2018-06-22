#include <stdio.h>

void main()
{
	int num, a, b, count=0;
	char s[8];

	printf("ют╥б : ");
	scanf("%d", &num);

	for(a=0; num>=1; a++)
	{
		if(num%2==1)
			s[a] = 1;
		else
			s[a] = 0;
		num=num/2;
		count++;
	}
	for(b=count-1; b>=0; b--)
		printf("%d", s[b]);
}