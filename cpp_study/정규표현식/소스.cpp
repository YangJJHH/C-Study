#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main()
{
	//regex re("\\d"); // �����ϳ�
	//regex re("\\d*"); //���ڿ�����
	// regex re("[ab]*"); // a��b �� ok
	//regex re("[[:digit:]]{3}"); // :digit: == \d ���� ���� �ǹ�, ���������� ���� 3�� �̻� ������ ok
	//regex re("[A-Z]+"); //���ĺ� ������ 1���̻�
	//regex re("[A-Z]{1,3}"); //�ּ�1�� �ִ� 3��
	regex re("([0-9]{1})([-]?)([0-9]{1,4})"); //  ?: �־�ǰ� ����ǰ�
	string str;
	while (true)
	{
		getline(cin, str);
		if (regex_match(str, re))
		{
			cout << "Match" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
	return 0;
}