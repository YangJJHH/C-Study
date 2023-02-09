#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <string>
#define fastio cin.tie(NULL)->sync_with_stdio(false);
using namespace std;
int n, m;
int s[1000001];

//�θ� ã���鼭 ����
int find(int a)
{
	if (s[a] == a) {
		return a;
	}
	int rst = find(s[a]);
	s[a] = rst; // ���� ���� ��Ʈ���� ���ٰ� �� ������ �θ� ����
	return rst;
}
int main()
{
	fastio;
	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	//���� �ʱ�
	for (int i = 1; i <= n; i++)
	{
		s[i] = i;
	}
	int a, b, c;
	for (int i = 1; i <= m; i++)
	{
		cin >> a >> b >> c;
		//������
		if (a == 0)
		{
			//������ ��Ʈ ã�Ƽ� ���� �������� Ȯ��, �ƴѰ�츸 �տ���
			b = find(b);
			c = find(c);
			if (b != c)
			{
				s[b] = c;
			}
		}
		else
		{
			//���� ������ ���
			cout << ((find(b) == find(c)) ? "YES" : "NO") << "\n";
		}
	}
	return 0;
}
