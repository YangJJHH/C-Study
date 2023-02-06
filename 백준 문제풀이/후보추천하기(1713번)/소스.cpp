#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
int N, COUNT;
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt","r",stdin);
	cin >> N >> COUNT;
	vector<int> photo;
	vector<int> arr(COUNT);
	vector<int> recommend(100,0); //��õ ��
	vector<int> time(100, 0); // �ð� 
	for (int i = 0; i < COUNT; i++)
	{
		cin >> arr[i];
	}
	
	for (int i=0; i<COUNT; i++)
	{
		//����Ʋ�� �̹� �Խõ� �����̶��
		auto it = find(photo.begin(), photo.end(), arr[i]);
		if (it != photo.end())
		{
			recommend[arr[i]]+=1; //��õ�� ����
		}
		// ����Ʋ�� �ڸ��� �ִٸ�
		else if (photo.size()<N)
		{
			photo.push_back(arr[i]);
			recommend[arr[i]]+=1; //��õ�� ����
		}
		//����Ʋ�� ���� ���
		else
		{
			int min_r = 1001;
			int index;
			for (int j=0; j<N; j++)
			{
				//��õ���� ���� ���� �ĺ� ã��
				if (recommend[photo[j]] <= min_r)
				{
					if (recommend[photo[j]] == min_r) //������ �������� ���
					{
						//�� ������ �ĺ� ã��
						if (time[photo[j]] > time[photo[index]])
						{
							index = j;
							min_r = recommend[photo[j]];
						}
					}
					else
					{
						min_r = recommend[photo[j]];
						index = j;
					}
				}
			}
			//���� Ʋ���� ��ü
			recommend[photo[index]] = 0;
			time[photo[index]] = 0;
			photo[index] = arr[i];
			recommend[arr[i]] += 1;
		}

		//�ð� ����
		for (auto& ele : photo)
		{
			time[ele] += 1;
		}
	}
	sort(photo.begin(),photo.end());
	for (auto& ele : photo)
	{
		cout << ele << " ";
	}
	return 0;
}