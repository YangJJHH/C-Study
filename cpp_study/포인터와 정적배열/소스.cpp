#include <iostream>
using namespace std;
void PrintArray(int arr[]) // int arr[] == int *arr ���� �ǹ�
{
	cout << sizeof(arr) << endl; // arr�� ���������δ� �������̱� ������ 8����
}
int main()
{
	int array[5] = { 9,3,5,3,1 };
	int* ptr = array;
	cout << array << endl;
	cout << *ptr  << endl;

	cout << sizeof(array) << endl; // 20
	PrintArray(array); // 8
	/*char name[] = "JaeHyeock";
	cout << *name << endl;*/
}