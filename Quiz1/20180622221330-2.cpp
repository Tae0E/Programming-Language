#include <stdio.h>

int main()
{
	int T;
	int h, m;

	printf("입력 : ");
	scanf("%d", &T);

	h = T / 100;
	m = T % 100;

	h >= 12 ? printf("오후 %d시 %d분", (h == 12 ? h : h - 12), m) : printf("오전 %d시 %d분", (h == 0 ? h + 12 : h), m);
}
/*
하루 중의 시간을 24시간으로 나타낸 정수를 읽어서, 시간과 분으로 바꾸어 출력.
예: 1635 - 오후 4시 35분
예: 1010 - 오전 10시 10분
*/