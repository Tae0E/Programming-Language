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
		printf("�޴�����: 1.�Է� 2.��� 3.���� 4.����\n");
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
STUDENT Input() //�Էµ� �����͸� ��ȯ
{
	STUDENT info;
	printf("�̸�, �й�, �����, �����, ���м��� : ");
	scanf("%s", info.name);
	scanf("%d", &info.code);
	scanf("%d", &info.kor);
	scanf("%d", &info.eng);
	scanf("%d", &info.math);

	return info;
}

int Delete(STUDENT info[], int * cnt) //code�� �Է¹޾� �ش��ϴ� code�� ã�Ƽ� ����
{
	int code;
	printf("�й� : ");
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
void Output(STUDENT info[], int cnt) //�Էµ� ��� ������ ���
{
	for (int i = 0; i < cnt; i++)
	{
		printf("�̸� : %s ", info[i].name);
		printf("�й� : %d ", info[i].code);
		info[i].score = (info[i].kor + info[i].eng + info[i].math) / 3.0;
		printf("���� : %c\n", grade(info[i].score));
	}
}
char grade(double score) //������ �Է¹޾� ������ ��ȯ(A-F)
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