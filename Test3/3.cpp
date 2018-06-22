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
	cout << "생성하고자 하는 원의 개수 ";
	cin >> num;

	Circle *pArray = new Circle[num];

	for (int i = 0; i < num; i++)
	{
		cout << "원" << i + 1 << " : ";
		cin >> rad;
		pArray[i].setRadius(rad);
	}

	for (int i = 0; i < num; i++)
	{
		cout << pArray[i].getArea() << endl;
		if (pArray[i].getArea()>100 && pArray[i].getArea() < 200)
			count++;
	}
	cout << "면적이 100에서 200 사이인 원의 개수는 " << count << endl;
}