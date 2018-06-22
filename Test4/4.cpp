#include <stdio.h>
#include "Turboc.h"
#define RIGHT 77
#define LEFT 75
#define UP 72
#define DOWN 80

void main()
{
	int key;
	int x = 0, y = 0;
	char C = '#';

	while (1)
	{
		gotoxy(x, y);
		printf("%c", C);
		key = getch();

		if (key == RIGHT)
		{
			x = x + 1;
			clrscr();
		}
		if (key == LEFT)
		{
			if (x == 0)
				;
			else
			{
				x = x - 1;
				clrscr();
			}
		}
		if (key == UP)
		{
			if (y == 0)
				;
			else
			{
				y = y - 1;
				clrscr();
			}
		}
		if (key == DOWN)
		{
			y = y + 1;
			clrscr();
		}
	}
}