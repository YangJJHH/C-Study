#include <iostream>
#include <string>
#include <limits>
using namespace std;
int main()
{
	//���� ���� ���ڿ� �Է� ������� getline()
	string name, age;
	cout << "Your age? : ";
	cin >> age;
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	cout << "Your name? : ";
	getline(cin,name);
	cout << name << " " << age;

	

	return 0;
}