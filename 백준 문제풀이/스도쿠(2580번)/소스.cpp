#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int board[9][9];
int flag = 0;
vector<pair<int, int>> zero;
bool Check(int r, int c)
{
	
	for (int i = 0; i < 9; i++)
	{
		//���� ���� ���� �ִ���
		if (board[r][c] == board[r][i] && i!= c) return false;
		//�࿡ ���� ���� �ִ���
		if (board[r][c] == board[i][c] && i!= r) return false;
		//���� �ִ� �簢���� ���� ���� �ִ���
	}
	int start_r, start_c;
	start_r = (r < 3) ? 0 : ((r < 6) ? 3 : 6);
	start_c = (c < 3) ? 0 : ((c < 6) ? 3 : 6);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int rr = start_r + i;
			int cc = start_c + j;
			if (board[r][c] == board[rr][cc] && rr!=r && cc!=c) return false;
		}
	}

	return true;
}

void Play(int n)
{
	if (n == zero.size())
	{
		flag = 1; // �÷��� ����
		return;
	}

	for (int i = 1; i <= 9; i++)
	{
		
		board[zero[n].first][zero[n].second] = i; //���� �ϳ� �־��
		if (Check(zero[n].first, zero[n].second)) //üũ
		{
			Play(n+1);
		}
		if (flag) return; //�� ã���� ��� �ݺ����� ������ �ʿ䰡 ���� 
		
	}
	board[zero[n].first][zero[n].second] = 0; //�ݺ��� ���� ������ ���� ��ã���� ��� ��ĭ���� �ٲپ� �ְ� ���� ��� Ż��
}
void Print()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "r", stdin);
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 0) zero.push_back({ i,j }); //��ĭ ��ġ ����
		}
	}
	Play(0);
	Print();
}