#include <stdio.h>
typedef struct student
{
	char name[20];
	int code;
	int kor, eng, math;
	double score;
}STUDENT;

STUDENT Input();
int Delete(STUDENT info[], int * cnt);
void Output(STUDENT info[], int cnt);
char grade(double score);

void main()
{
	STUDENT s[10];
	int cnt = 0, select, i;
	while (1)
	{
		printf("메뉴구성: 1.입력 2.출력 3.삭제 4.종료\n");
		scanf("%d", &select);
		if (select == 1)
		{
			s[cnt] = Input();
			cnt++;
		}
		if (select == 2)
		{
			Output(s, cnt);
		}
		if (select == 3)
		{
			Delete(s, &cnt);
			cnt--;
		}
		
	}
}
STUDENT Input() //입력된 데이터를 반환
{
	STUDENT info;
	printf("이름, 학번, 국어성적, 영어성적, 수학성적 : ");
	scanf("%s", info.name);
	scanf("%d", &info.code);
	scanf("%d", &info.kor);
	scanf("%d", &info.eng);
	scanf("%d", &info.math);

	return info;
}

int Delete(STUDENT info[], int * cnt) //code를 입력받아 해당하는 code를 찾아서 삭제
{
	int code;
	printf("학번 : ");
	scanf("%d", &code);

	for (int i = 0; i < *cnt; i++)
	{
		if (code == info[i].code)
			for (int j = i; j < *cnt; j++)
				info[j] = info[j + 1];
		else
			continue;
	}
	return 0;

}
void Output(STUDENT info[], int cnt) //입력된 모든 데이터 출력
{
	for (int i = 0; i < cnt; i++)
	{
		printf("이름 : %s ", info[i].name);
		printf("학번 : %d ", info[i].code);
		info[i].score = (info[i].kor + info[i].eng + info[i].math) / 3.0;
		printf("평점 : %c\n", grade(info[i].score));
	}
}
char grade(double score) //점수를 입력받아 학점을 반환(A-F)
{
	if (score >= 90 && score <= 100)
		return 'A';
	else if (score >= 80)
		return 'B';
	else if (score >= 70)
		return 'C';
	else if (score >= 60)
		return 'D';
	else
		return 'F';
}