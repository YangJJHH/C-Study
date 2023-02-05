#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;
int x[] = { 0,0,-1,1 };
int y[] = { -1,1,0,0 };
int R, C;
string* map;
class Point
{
public:
	int x;
	int y;
	Point(int ix = 0, int iy = 0) : x(ix), y(iy)
	{}
};
bool CheckPos(int x, int y)
{
	if (x>=0 && x<R && y>=0 && y<C && map[x][y]=='.')
	{
		return true;
	}

	return false;
}
void MoveBFS(queue<Point> &water, queue<Point> &gosm)
{
	int minutes = 0;
	while (!gosm.empty())
	{
		minutes++; //1�о� �߰�

		Point p;
		int cnt = water.size();
		// �� �̵�
		for (int i = 0; i < cnt; i++)
		{
			p = water.front();
			water.pop();
			// ���� �� �� �ִ� ����
			for (int j = 0; j<4; j++)
			{
				int dx = p.x + x[j];
				int dy = p.y + y[j];
				if (CheckPos(dx,dy))
				{
					map[dx][dy] = '*';
					water.emplace(dx,dy);
				}
			}
		}

		//����ġ �̵�
		cnt = gosm.size();
		for (int i = 0; i < cnt; i++)
		{
			p = gosm.front();
			gosm.pop();
			for (int j = 0; j < 4; j++)
			{
				int dx = p.x + x[j];
				int dy = p.y + y[j];
				//��� �� ���� Ȯ��
				if (dx >= 0 && dx < R && dy >= 0 && dy < C)
				{
					if (map[dx][dy] == 'D')
					{
						cout << minutes;
						return;
					}
				}
				if (CheckPos(dx, dy))
				{
					map[dx][dy] = 'S';
					gosm.emplace(dx,dy);
				}
			}
			
		}

	}
	cout << "KAKTUS";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "r", stdin);

	cin >> R >> C;
	cin.ignore();
	map = new string[R];
	//���� ����ġ ��ǥ
	queue<Point> water;
	queue<Point> gosm;

	for (int i = 0; i < R; i++)
	{
		getline(cin, map[i]);
		int w, g;
		w = map[i].find('*');
		g = map[i].find('S');
		if (w != string::npos)
		{
			water.emplace(i,w);
		}
		if (g != string::npos)
		{
			gosm.emplace(i,g);
		}
	}

	
	MoveBFS(water,gosm);

	//�޸� ����
	delete[] map;
	return 0;
}