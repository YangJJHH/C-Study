#include <iostream>

using namespace std;
class B
{
private:
	int _b;
public:
	B(const int& b) : _b(b)
	{

	}
};
class Something
{
private:
	int _i;
	int _d;
	char _c;
	int _arr[5]; //�迭�� �ʱ�ȭ ����
	B _b;
public:
	Something() : _i(1), _d(2), _c('a'), _arr{ 1,2,3,4,5 },_b(_i-1) //�ʱ�ȭ �ϴ� ���
	{

	}

	void Print()
	{
		cout << _i << " " << _d << " " << _c <<endl;
		for (auto& e : _arr)
		{
			cout << e << " ";
		}
		cout << endl;
	}
};

int main()
{
	Something s;
	s.Print();
	return 0;
}