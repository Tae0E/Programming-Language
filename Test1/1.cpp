
#include <iostream>
using namespace std;
class MyengTae
{
	int n;
	char name1[10] = "����";
	char name2[10] = "����";
	char name3[10] = "�Ͼ�";
public:
	void reset();//���·� �ʱ�ȭ
	void heat();//���¸� �Ͼ��, ���¸� ���·�
	void freeze();//���¸� ���·�, �Ͼ ���·�
	void print();//�ش� ������ ���¸� ���
};
void MyengTae::reset()
{
	n = 0;
}
void MyengTae::heat()
{
	if (n == 0)
		n = 2;
	else if (n == 1)
		n = 0;
}
void MyengTae::freeze()
{
	if (n == 0)
		n = 1;
	else if (n == 2)
		n = 0;
}
void MyengTae::print()
{
	if (n == 0)
		cout << name1 << endl;
	else if(n == 1)
		cout << name2 << endl;
	else
		cout << name3 << endl;
}

void main()
{
	MyengTae myFish;
	myFish.reset();
	myFish.print();

	myFish.heat();
	myFish.print();

	myFish.heat();
	myFish.print();

	myFish.freeze();
	myFish.print();

	myFish.freeze();
	myFish.print();
}