#include <iostream>

using namespace std;
template<typename T>
T getMax(T a, T b)
{
	return (a > b) ? a : b;
}

//Ư���� �ڷ��������� ó�� ex: char
//���ø��� ������ Ÿ�ӿ� �������� ������ if������ ��� �Ұ�
template<>
char getMax(char a, char b)
{
	cout << "Warning : comparing chars.." << endl;
	return (a > b) ? a : b;
}

int main()
{

	cout << getMax('a', 'b') << endl;
	//cout << getMax(1.0, 2.0) << endl;
	//cout << getMax('a', 'b') << endl;

	return 0;
}