#include <iostream>
using namespace std;

int main()
{
	//���� �Ҵ� -> stack ,  ���� �Ҵ� -> heap . heap�� stack���� �� ũ��
	//int var;
	int* ptr = new (nothrow)int; // nothorw : �޸𸮰� ������ new �� �����ϴ��� ptr = null�� �ȴ�
	*ptr = 7;
	cout << *ptr;

	delete ptr; // �޸� �ݳ�
	ptr = nullptr;

	//memory leak;
	while (true)
	{
		int* ptr = new int;
		cout << ptr << endl;
		//delete ptr;
	}

	return 0;
}