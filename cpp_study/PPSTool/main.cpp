#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <io.h>
#include <Windows.h>
#include <tchar.h>

using namespace std;

typedef vector<string> stringvec;
const string workDirPath = "C:\\Users\\didwo\\OneDrive\\���� ȭ��\\work\\";
const string resouceDirPath = "C:\\Users\\didwo\\OneDrive\\���� ȭ��\\Resouce\\";


const string pps = "*.pps";
const char ppi[] = ".ppi";
const string ppsToken = "key_info";			// ppi ���� �̸� ���п�
const string ppiToken1 = "dress_image";		// ���ҽ� �̸� ���п�
const string ppiToken2 = "dress";	// ���ҽ� �̸� ���п�
stringvec notFoundPPI;
stringvec notFoundResouce;
//  string -> wstring ��ȯ
//	���� ����/ �ٿ��ֱ� �Ҷ� �μ��� LPCWSTR ������ �����ؾ���, LPCWSTR�� �ٲٱ��� �߰�����
std::wstring s2ws(const std::string& s)
{
	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
	std::wstring r(buf);
	delete[] buf;
	return r;
}
bool OpenDir(intptr_t& handle, struct _finddata_t& fd, const string& dir, const string& token)
{
	string fullpath = (dir + token);
	//������ tokenȮ���� ���� ã��
	if ((handle = _findfirst(fullpath.c_str(), &fd)) == -1L)
	{
		return false;
	}
	return true;
}
void Copy(string target, string dest)
{
	wstring tmp1 = s2ws(target);
	wstring tmp2 = s2ws(dest);
	LPCWSTR t = tmp1.c_str();
	LPCWSTR d = tmp2.c_str();
	CopyFile(t, d, false);
}
string Split(string::size_type startIdx,const string& data)
{
	string::size_type i = startIdx;
	while (i != data.size() && !isspace(data[i]))
	{
		++i;
	}
	return data.substr(startIdx+1, i - startIdx-2); // " " �� ����
}
void OpenPPI(const string& filename)
{
	ifstream file;
	string data;
	
	string fullFileName = resouceDirPath + filename;

	
	
	//ppi���� �б�
	file.open(fullFileName);
	if (file)
	{
		while (getline(file, data))
		{
			// dress�� �����ϴ� �� ã��
			string tmp = data.substr(0, ppiToken2.length());
			int startIdx = 0;
			if (tmp == ppiToken2 || tmp == ppiToken1)
			{
				startIdx = (data.substr(0, ppiToken1.length()) == ppiToken1) ? ppiToken1.length() + 2 : ppiToken2.length() + 2;	// ����� " ���� ���ҽ����� �̸� ����������
				string resouceFileName = data.substr(startIdx, data.length() - startIdx - 1);				// ���ڿ� ���������� "������
				
				//�ش� �̸� ���ҽ� ã��
				struct _finddata_t fd;
				intptr_t handle;
				int result = 1;
				string fullpath = (resouceDirPath + resouceFileName);
				//������ �ش� ���ҽ� ���� ã��
				if (!OpenDir(handle, fd, resouceDirPath, resouceFileName))
				{
					string tmp = resouceFileName + "("+ filename +")";
					notFoundResouce.push_back(tmp);
					continue;
				}
				Copy(fullpath, (workDirPath + resouceFileName));
				

			}
		}
		// ã�� ppi ���� Ÿ�������� ����, �ٿ��ֱ�
		Copy(fullFileName, (workDirPath + filename));
	}
	else 
	{
		cout << "������ �� �� �����ϴ�" << endl;
		notFoundPPI.push_back(filename);
	}
}
void OpenPPS(const char* filedir)
{
	ifstream file;
	string data;
	//pps���� �б�
	file.open(filedir);
	if (file)
	{
		while (getline(file, data))
		{
			// ppi ���� �̸��� �ִ� �� ã��
			if (data.substr(0, ppsToken.length()) == ppsToken)
			{
				// ppi ���� �̸� ����
				string::size_type startIdx = ppsToken.length() + 1; // ���� ������� ����(+1)
				string ppiFileName = Split(startIdx,data);

				// ppi ���� �б�
				OpenPPI(ppiFileName);
			}
		}
	}
	else
	{
		cout << "������ �� �� �����ϴ�" << endl;
	}
	
	cout << endl;
	file.close();
}
void FindDir()
{
	
	struct _finddata_t fd;
	intptr_t handle;
	int result = 1;
	//������ pps���� �б�
	if (!OpenDir(handle, fd, workDirPath, pps))
	{
		return;
	}


	ifstream file;
	while (result != -1)
	{
		cout << fd.name<<endl;
		char filedir[256];
		strcpy_s(filedir, workDirPath.c_str());
		strcat_s(filedir, fd.name);
		
		OpenPPS(filedir);

		result = _findnext(handle, &fd);
	}
	_findclose(handle);
		
}
void PrintResult()
{
	cout << "=======================================" << endl << "��ã�� ppi ���ϸ��" << endl;
	for (auto& val : notFoundPPI)
	{
		cout << val << endl;
	}
	cout << endl << "��ã�� ���ҽ� ���ϸ��" << endl;
	for (auto& val : notFoundResouce)
	{
		cout << val << endl;
	}
}
int main()
{
	
	FindDir();
	PrintResult();
	return 0;
}