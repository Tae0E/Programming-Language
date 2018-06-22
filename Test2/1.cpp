
#include <iostream>
using namespace std;
class MyengTae
{
	int n;
	char name1[10] = "명태";
	char name2[10] = "동태";
	char name3[10] = "북어";
public:
	void reset();//명태로 초기화
	void heat();//명태를 북어로, 동태를 명태로
	void freeze();//명태를 동태로, 북어를 명태로
	void print();//해당 명태의 상태를 출력
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