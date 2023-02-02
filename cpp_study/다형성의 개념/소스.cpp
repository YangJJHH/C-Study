#include <iostream>
#include <string>

using namespace std;

class Animal
{
private:
	string _name;
public:
	Animal(string name ="") : _name(name)
	{}

	virtual void speak()  //virtual Ű���带 ���� �ڽ� Ŭ�������� �����ǵ� �Լ� ���
	{
		cout << "???" << endl;
	}
};
class Cat : public Animal
{
public:
	Cat(string name) : Animal(name)
	{}

	void speak()
	{
		cout << "Cat!" << endl;
	}
};

class Dog : public Animal
{
public:
	Dog(string name) : Animal(name)
	{}

	void speak()
	{
		cout << "Dog!" << endl;
	}
};

int main()
{
	Cat c("cat1");
	Cat c2("cat2");
	Dog d("dog");
	Animal* animals[] = {&c,&c2,&d };
	for (auto& ele : animals)
	{
		ele->speak();
	}
	return 0;
}