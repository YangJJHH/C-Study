#include <iostream>
#include <typeinfo>
using namespace std;
void ex1()
{
	// ������ ����
	int x = 5;
	cout << x << endl;
	cout << &x << endl;
	cout << (int)&x << endl; // & : address - of operator

	//de - reference operator(*) ���� �� �ּ��� ���� �鿩�� ����
	// �����ʹ� �޸��� �ּҸ� ��� ����

	cout << *(&x) << endl;
}
void ex2()
{
	int x = 5;
	double d = 1.45;
	//typedef int* pint; �̷������� Ÿ������ ���� ��밡��
	int* ptr_x = &x;
	double* ptr_d = &d;
	cout << ptr_x << endl;
	cout << *ptr_x << endl;
	cout << *ptr_d << endl;
	cout << typeid(ptr_x).name() << endl;

}
int main()
{
	ex2();
	return 0;
}

