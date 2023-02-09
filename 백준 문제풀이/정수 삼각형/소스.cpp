#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <string>
#define fastio cin.tie(NULL)->sync_with_stdio(false);
//DP
//Ǯ�̹��
//����ĭ�� ���� �Ʒ��� �� ���ִ� ĭ�� ���� ������ �����ϸ� ������
//�� ������ �ٿ��� �� ��쿡�� ���� ū����� ������ �յ��� ������ ��
using namespace std;
int arr[500][500]{0}; // ���� �迭
int tri[500][500]{0}; //�����ϸ鼭 ���� �յ��� ����
int N;
int max_sum =0;
void move()
{
	for (int i = 0; i < N-1; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			tri[i + 1][j] = max(tri[i+1][j],tri[i][j]+arr[i+1][j]); //�Ʒ��� �ִ� ĭ�� ���ؼ� tri�� �ִ� ���� ���Ͽ� ū�� ����
			tri[i + 1][j+1] = max(tri[i + 1][j+1], tri[i][j] + arr[i + 1][j+1]); //�밢������
		}
	}

}

int main()
{
	fastio;
	freopen("input.txt", "r", stdin);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cin >> arr[i][j];
		}
	}
	tri[0][0] = arr[0][0];
	move();
	for (int i=0; i<N; i++)
	{
		max_sum = max(max_sum,tri[N-1][i]);
	}
	cout << max_sum;
	return 0;
}