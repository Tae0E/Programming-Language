#include <stdio.h>

int main()
{
	int N;
	int a, b, c;
	printf("�Է�(3�ڸ�) : ");
	scanf("%d", &N);

	a = N / 100;
	b = (N % 100) / 10;
	c = N % 10;

	printf("%d", a + b + c);
}
/*
3�ڸ��� ������ �Է� ���� ��, �� �ڸ����� �հ踦 ����϶�.
�Է�(3�ڸ�): 123
���: 6
*/