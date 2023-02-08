#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define fastio cin.tie(NULL)->sync_with_stdio(false);

using namespace std;
long long sum;
int N, T, M;
long long rst = 0;
// Ǯ�̹��
// ������ 1000��,�ð��� 2�� �����̱� ������ O(n^2) �̿��� �����
// ���� �κ����� ��� �����ְ� T���� �� �κ����� �� ���� �ٸ� �κ��տ� � �ִ��� ã�Ƴ��� ���
// lower_bound(����,�� ,��ǥ��) : ��ǥ������ ũ�ų� ���� ������ ���� ó�� �����°�
// upper_bound(����,�� ,��ǥ��) : ��ǥ������ ū ������ ���� ó�� �����°�
// �� lower_bound() - upper_bound() �ϸ� �����ϴ� �κ����� � �ִ��� �� �� ����

//��������
int Lower(const vector<long long>& v,long long target)
{
	int start = -1;
	int end = v.size();
	int mid ;
	//�̺�Ž��
	while (end - start > 1)
	{
		mid = (start + end) / 2;
		if (v[mid] >= target)
		{
			end = mid;
		}
		else if (v[mid] < target)
		{
			start = mid;
		}
	}
	return end;
}
int Upper(const vector<long long>& v, long long target)
{
	int start = -1;
	int end = v.size();
	int mid;
	//�̺�Ž��
	while (end - start > 1)
	{
		mid = (start + end) / 2;
		if (v[mid] > target)
		{
			end = mid;
		}
		else if (v[mid] <= target)
		{
			start = mid;
		}
	}
	return end;
}
int main()
{
	fastio;
	freopen("input.txt", "r", stdin);
	cin >> T >> N;
	vector<int> a(N);
	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
	}
	cin >> M;
	vector<int> b(M);
	for (int i = 0; i < M; i++)
	{
		cin >> b[i];
	}

	vector<long long> v, v2;
	for (int i = 0; i < N; i++)
	{
		sum = a[i];
		v.push_back(sum);
		for (int j = i+1; j < N; j++)
		{
			sum += a[j];
			v.push_back(sum);
		}
	}

	for (int i = 0; i < M; i++)
	{
		sum = b[i];
		v2.push_back(sum);
		for (int j = i + 1; j < M; j++)
		{
			sum += b[j];
			v2.push_back(sum);
		}
	}
	sort(v2.begin(),v2.end());
	for (auto& ele : v)
	{
		//auto a = lower_bound(v2.begin(), v2.end(), T - ele) - v2.begin();
		//auto b = upper_bound(v2.begin(), v2.end(), T - ele) - v2.begin();
		auto a = Lower(v2, T - ele);
		auto b = Upper(v2, T - ele);
		rst += b - a;
	}
	

	cout << rst;
	return 0;
}