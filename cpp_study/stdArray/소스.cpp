#include <iostream>
#include <array>
#include <algorithm> //sort
using namespace std;
void printArray(const array<int,5> &arr) { //array�� �Լ��� ���޵ǵ� �����ͷ� ��ȯ���� �ʴ´�.
										   // ���ʿ��� ���簡 �Ͼ�� �ʵ��� ������ �ޱ�
	for (auto i : arr) {
		cout << i << " ";
	}
}
void SortingArr(array<int,5> &arr) {
	sort(arr.begin(), arr.end());
}
int main()
{
	int arr1[] = {1,2,3,4,5};
	array<int, 5> arr2 = {11, 2, 23, 4, 45};

	cout << arr2[0] << endl;
	cout << arr2.at(0) << endl;
	SortingArr(arr2);
	printArray(arr2);
	return 0;
}