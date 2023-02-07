#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int N, M;
int main()
{
	//�� ������
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "r", stdin);
	cin >> N >> M;
	int* arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	int left =0; // ������ ���� ������
	int right =0; // ���� ���ư� ������ ������ ������
	int sum = arr[0];
	int cnt = 0;
	while (right < N)
	{
		if (sum < M) //���� �۴ٸ� �������� ��ĭ �� ������
		{
			right++;
			sum += arr[right];
		}
		else if(sum == M)  //���� ���ٸ� �� �̻� ������ �� �ʿ䰡 ���� ������ ���� ��ĭ ����
		{
			cnt++;
			sum -= arr[left];
			left++;
		}
		else if(sum>M) //���� ũ�ٸ� ������ ��ĭ �� ������ ������ ����
		{
			sum -= arr[left];
			left++;
		}
	}
	cout << cnt;
}