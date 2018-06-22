#include <stdio.h>
#include <string.h>

void main()
{
	char Str[20];
	char Arr1[26];
	int a, b, i, count = 0;
	char c = 'a';

	printf("ют╥б : ");
	gets_s(Str);

	for (i = 0; i<26; i++)
	{
		Arr1[i] = c;
		c++;
	}

	for (b = 0; b < 26; b++)
	{
		for (a = 0; a < strlen(Str); a++)
		{
			if (Str[a] == Arr1[b])
				count++;
		}
		if (count != 0)
			printf("%c : %d, ", Arr1[b], count);
		count = 0;
	}
}