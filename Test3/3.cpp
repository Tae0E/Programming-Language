#include <iostream>
using namespace std;
class Circle
{
	int radius;
public:
	Circle();
	~Circle() { }
	void setRadius(int r) { radius = r; }
	double getArea() {
		return 3.14*radius*radius;
	}
};
Circle::Circle()
{
	radius = 1;
}
void main()
{
	int num;
	int rad;
	int count = 0;
	cout << "�����ϰ��� �ϴ� ���� ���� ";
	cin >> num;

	Circle *pArray = new Circle[num];

	for (int i = 0; i < num; i++)
	{
		cout << "��" << i + 1 << " : ";
		cin >> rad;
		pArray[i].setRadius(rad);
	}

	for (int i = 0; i < num; i++)
	{
		cout << pArray[i].getArea() << endl;
		if (pArray[i].getArea()>100 && pArray[i].getArea() < 200)
			count++;
	}
	cout << "������ 100���� 200 ������ ���� ������ " << count << endl;
}