
//Pełnomocnik (ang. proxy) – strukturalny wzorzec projektowy, którego celem jest utworzenie obiektu zastępującego inny obiekt.
//Stosowany jest w celu kontrolowanego tworzenia na żądanie kosztownych obiektów oraz kontroli dostępu do nich.

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

class Subject
{
public:
	virtual void execute() = 0;
};

class RealSubject : public Subject
{
	string str;
public:
	RealSubject(string s)
	{
		str = s;
	}

	//wirtualny
	void execute()
	{
		cout << str << '\n';
	}
};

class ProxySubject : public Subject
{
	string first, second, third;
	RealSubject *ptr;
public:
	ProxySubject(string s)
	{
		int num = s.find_first_of(' ');
		first = s.substr(0, num);
		s = s.substr(num + 1);
		num = s.find_first_of(' ');
		second = s.substr(0, num);
		s = s.substr(num + 1);
		num = s.find_first_of(' ');
		third = s.substr(0, num);
		s = s.substr(num + 1);
		ptr = new RealSubject(s);
	}
	~ProxySubject()
	{
		delete ptr;
	}
	RealSubject *operator->()
	{
		cout << first << ' ' << second << ' ';
		return ptr;
	}
	
	//wirtualna
	void execute()
	{
		cout << first << ' ' << third << ' ';
		ptr->execute();
	}
};

int main()
{
	ProxySubject obj(string("Byl piekny sloneczny poranek."));
	//Operatory "->" oraz "." mogą dać różne rezultaty.
	obj->execute();
	obj.execute();

	cin.ignore();
	return EXIT_SUCCESS;
}