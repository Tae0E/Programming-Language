#include <iostream>
using namespace std;
class Circle
{
	int x=0;
	int y=0;
	int radius=0;
public:
	bool setPoint(int x, int y);
	bool setRadius(int radius);
	double getArea(void);
};
bool Circle::setPoint(int a, int b)
{
	if (a >= 2 && b >= 2 && a <= 49 && b <= 49)
	{
		x = a;
		y = b;
		return 1;
	}
	else
	{
		cout << "좌표를 다시 확인해 주세요" << endl;
		return 0;
	}
}
bool Circle::setRadius(int r)
{
	
	if (x - r >= 1 && y - r >= 1 && r != 0 && x + r <= 50 && y + r <= 50)
	{
		radius = r;
		return 1;
	}	
	else
	{
		cout << "반지름을 다시 확인해 주세요" << endl;
		return 0;
	}
}
double Circle::getArea(void)
{
	if (radius == 0)
	{
		cout << "반지름까지 더 입력하세요" << endl;
		return 0;
	}
	else
		return 3.14*radius*radius;
}
void main()
{
	Circle c;
	c.setPoint(1, 1);
	c.getArea();

	c.setPoint(5, 5);
	c.setRadius(6);

	c.setRadius(3);
	cout << c.getArea() << endl;
}