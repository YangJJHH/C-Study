#include <iostream>

using namespace std;
class Simple
{
private:
	int _id;
public:
	Simple(const int& id) : _id(id)
	{
		cout << "������ �Դϴ�. id: " << _id << endl;
	}

	~Simple() {
		cout << "�Ҹ��� �Դϴ� id: ." <<_id<< endl;
	}
};
class ArrayClass
{
private:
	int _len;
	int* arr;
public:
	ArrayClass(const int& len) : _len(len)
	{
		arr = new int[_len];
	}
	~ArrayClass() {
		delete[] arr; //�Ҹ��ڰ� ����Ǹ鼭 �˾Ƽ� �޸� ����, �Ҹ��ڿ� delete�� ������ -> �޸� ����
	}

};
int main()
{
	//Simple s1(1);
	//Simple* s3 = new Simple(3);
	//Simple s2(2);
	//delete s3;

	while (true)
	{
		ArrayClass arr(1000); // �Ҹ��� ���� -> delete �޸� ����
	}
	return 0;
}