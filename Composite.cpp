
//Kompozyt � strukturalny wzorzec projektowy, kt�rego celem jest sk�adanie obiekt�w w taki spos�b,
//aby klient widzia� wiele z nich jako pojedynczy obiekt. 

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Component {
public:
	virtual void cover() = 0;
};

class Leaf : public Component {
	int x;
public:
	Leaf(int y) {
		x = y;
	}
	void cover() {
		cout << x << ' ';
	}
};

class Composite : public Component {
	vector < Component * > children;
public:
	void add(Component *ele) {
		children.push_back(ele);
	}
	void cover() {
		for (int i = 0; i < children.size(); i++)
			children[i]->cover();
	}
};

int main() {
	Composite containers[4];

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 3; j++)
			containers[i].add(new Leaf(i * 3 + j));

	for (int i = 1; i < 4; i++)
		containers[0].add(&(containers[i]));

	for (int i = 0; i < 4; i++) {
		containers[i].cover();
		cout << endl;

		cin.ignore();
		return 0;
	}
}

