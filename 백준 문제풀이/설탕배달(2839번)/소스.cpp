#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#define fastio cin.tie(NULL)->sync_with_stdio(false);
using namespace std;
//�׸��� �˰���
int main()
{
	int N;
	cin >> N;
	int answer = -1;
	int count = N / 5; //5�� �ִ��� ������ �ִ� Ƚ�� ����
	int rst;
	while (count>=0)
	{
		int tmp = N- 5 * count; // 5�� ���� �������� 3���� ������ �������� ������ 5�� ������ Ƚ���� ����
		if (tmp % 3 == 0)
		{
			answer = count + tmp / 3;
			break;
		}
		count--;
	}

	cout << answer;
	return 0;
}