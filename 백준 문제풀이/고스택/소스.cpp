#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
//#include <cstdlib>
using namespace std;
const int MAX = pow(10, 9);

void calc(vector<string>& commands, vector<int>& stack, vector<int>& inputs)
{
	long long rst = 0;
	string output;
	for (auto& ele : inputs)
	{
		rst = 0;
		output = "";
		stack.emplace_back(ele);
		for (auto& command : commands)
		{
			string tmp = command.substr(0, 3);
			if (tmp == "NUM")
			{
				stack.emplace_back(stoi(command.substr(4, command.size()-4)));
			}
			else if (stack.size() == 0)
			{
				output = "ERROR";
				break;
			}
			else if (tmp == "POP")
			{
				stack.pop_back();
			}
			else if (tmp == "INV")
			{
				stack[stack.size() - 1] = (-1 * stack.back());
			}
			else if (tmp == "DUP")
			{
				stack.emplace_back(stack.back());
			}
			else if (stack.size() < 2)
			{
				output = "ERROR";
				break;
			}
			else if (tmp == "SWP")
			{
				iter_swap(stack.rbegin(), stack.rbegin() + 1);
			}
			else
			{
				long long first = stack.back();
				stack.pop_back();
				long long second = stack.back();
				stack.pop_back();
				if (tmp == "ADD")
				{
					rst = first + second;
				}
				else if (tmp == "SUB")
				{
					rst = second - first;
				}
				else if (tmp == "MUL")
				{
					rst = first * second;
				}
				//0���� ������ ���
				else if (first == 0)
				{
					output = "ERROR";
					break;
				}
				else if (tmp == "DIV")
				{
					//�ǿ����� �� �ϳ��� ������ ���
					if ((first < 0 && second >= 0) || (first > 0 && second <= 0))
					{
						rst = -1;
					}
					else
					{
						rst = 1;
					}

					rst *= (labs(second) / labs(first));
				}
				else if (tmp == "MOD")
				{
					rst = (second >= 0) ? 1 : -1; // �������� ��ȣ�� �������� ����
					rst *= (labs(second) % labs(first));
				}
				if (labs(rst) > MAX)
				{
					output = "ERROR";
					break;
				}
				stack.emplace_back(rst);
			}

		}
		//���� ����
		if (output == "ERROR" || stack.size()!=1)
		{
			output = "ERROR";
		}
		else
		{
			output = to_string(stack[0]);
		}
		cout << output << '\n';
		stack.clear();
	}
	//���͵� �ʱ�ȭ
	commands.clear();
	inputs.clear();
	stack.clear();
	cout <<'\n';
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<string> commands;
	vector<int> stack;
	vector<int> inputs;
	string tmp;
	int n, input;
	freopen("input.txt", "r", stdin);

	while (1)
	{
		getline(cin, tmp);
		if (tmp == "QUIT") break;

		// ��ɾ� �ޱ�
		while (tmp != "END")
		{
			commands.push_back(tmp);
			getline(cin, tmp);
		}
		//�Է� ���� 
		cin >> n;

		//�Է°� �ޱ�
		for (int i = 0; i < n; i++)
		{
			cin >> input;
			inputs.push_back(input);
		}
		cin.ignore();
		getline(cin, tmp);
		calc(commands, stack, inputs);
	}

	return 0;
}