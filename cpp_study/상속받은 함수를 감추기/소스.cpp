#include <iostream>
#include <string>

using namespace std;
class Base
{
protected:
	int m_i;
public:
	Base(int val = 0) : m_i(val)
	{}

	void print()
	{
		cout <<"I'm base" << m_i << endl;
	}
};

class Derived : public Base
{
private:
	double m_d;
public:
	Derived(int i, double d) : Base(i), m_d(d)
	{}

	using Base::m_i; // main���� ��밡�� (public ó��)


private:
	using Base::print; //main���� ���Ұ��� (private ó��)
};
int main()
{

	Derived d(1,3.0);
	d.m_i = 1; // using Base::m_i �� ���ٸ� ��� �Ұ���
	//d.print(); // using Base::print ������ �Ұ���
	return 0;
}
