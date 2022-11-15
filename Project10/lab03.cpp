#include <iostream>

using namespace std;

class BaseClass {
public:
	int b = 0;
	virtual void Print() {
		cout << "BaseClass" << endl;
	}
};
class DerivedClass: public BaseClass {
public:
	int d = 2;
	virtual void Print() {
		cout << "DerivedClass" << endl;
	}
};
/*���� BaseClass, DerivedClass�� �����ϰ� ���� int�� ���� b�� d�� �����Ѵ�.*/
int main() {
	DerivedClass derived;
	BaseClass* base = &derived;
	auto derived2 = dynamic_cast<DerivedClass*>(base);
	derived2->d = 0; // derived2�� dynamic_cast�� ���� ���� d�� ���� 0���� ��ȯ
	if (derived2->d==0) { // �� �ν��Ͻ� ������ ��ٸ� ���� d�� ���� �ٲ������� 0�� �ɰ��̴�.
		cout << "Everything is OKAY" << endl;//if else���� ���� ���� ���� Ȯ��.
	}
	else {
		cout << "Everything is WRONG" << endl;
	}
}