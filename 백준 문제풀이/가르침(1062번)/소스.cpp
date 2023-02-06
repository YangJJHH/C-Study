#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
/// <summary>
/// ��Ʈ����ŷ, DFS
/// </summary>
using namespace std;
int N, K;
int bitmask = 0; // ��� ���ڿ� ���� ��Ʈ����ũ ����
int words[50];
int rst;
void DFS(int cnt, int ch)
{
	if (cnt == K || ch == 26) //K���� ���ڸ� ����� ��� , ��� �ܾ ���� �� �ֳ� Ȯ��
	{
		int count = 0;
		for (int i = 0; i < N; i++)
		{
			if ((words[i] & bitmask) == words[i]) count++;
		}
		rst = max(count, rst);
		return;
	}

	for (int i = ch; i < 26; i++)
	{
		if ((bitmask & (1 << i)) == 0) //���� ��� ���ڿ� �߰����� �ʾҴٸ�
		{
			bitmask |= (1 << i);
			DFS(cnt + 1, i + 1);
			bitmask &= ~(1 << i);
		}
	}
}

int main()
{


	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "r", stdin);
	cin >> N >> K;
	
	string tmp;
	char ch[5] = { 'a','n','t','i','c' };
	for (auto& ele : ch)
	{
		bitmask |= (1 << (ele - 'a'));
	}
	//cout << bitset<26>(bitmask);
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		for (int j = 0; j < tmp.length(); j++)
		{
			int alpha = 1 << (tmp[j] - 'a');
			words[i] |= alpha; //�ܾ �����ϴ� ���ڵ� ��Ʈ����ŷ
		}
	}
	if (K < 5 || K == 26)
	{
		cout << ((K == 26) ? N : 0);
	}
	else
	{
		DFS(5, 0);
		cout << rst;
	}
	
	return 0;
}