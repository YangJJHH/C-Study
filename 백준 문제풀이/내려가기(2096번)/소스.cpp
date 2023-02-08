#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define fastio cin.tie(NULL)->sync_with_stdio(false);
//���̳��� ���α׷��� DP
//�޸𸮰� 4MB �����̱� ������ ����
//Ǯ�� ����
//���� ĭ�� �ִ� ���� ������ �� �� �ִ� ����� ������ ū�� �� ���ؼ� ����ĭ�� ����, �ּҰ��� �ݴ��
using namespace std;
int N;
int main()
{
	fastio;
	freopen("input.txt","r",stdin);
	cin >> N;
	int max_dp[3] = { 0 }; //�ִ� ���� ���
	int min_dp[3] = { 0 }; //�ּ� ���� ���
	int arr[3] = { 0 }; //���� ĭ�� �ִ� �� ��Ÿ��
	int pre[3] = { 0 }; //���� ĭ�� �ִ� �� ��Ÿ��

	for (int i = 0; i < N; i++)
	{
		cin >> arr[0] >> arr[1] >> arr[2]; //����ĭ
		
		//���� ĭ ����
		pre[0] = max_dp[0];
		pre[1] = max_dp[1];
		pre[2] = max_dp[2];
		//���� ĭ�� �ִ밪 �� �� ����ĭ�� ���� ���ؼ� ����ĭ�� ����
		max_dp[0] = max(pre[0],pre[1]) + arr[0];
		max_dp[2] = max(pre[1], pre[2]) + arr[2];
		max_dp[1] = max(max(pre[0], pre[1]),pre[2]) + arr[1];

		//���� ĭ ����
		pre[0] = min_dp[0];
		pre[1] = min_dp[1];
		pre[2] = min_dp[2];
		//���� ĭ�� �ּҰ� �� �� ����ĭ�� ���� ���ؼ� ����ĭ�� ����
		min_dp[0] = min(pre[0], pre[1]) + arr[0];
		min_dp[2] = min(pre[1], pre[2]) + arr[2];
		min_dp[1] = min(min(pre[0], pre[1]), pre[2]) + arr[1];
	}
	cout << max(max(max_dp[0], max_dp[1]), max_dp[2]) << " " << min(min(min_dp[0], min_dp[1]), min_dp[2]);
	return 0;
}