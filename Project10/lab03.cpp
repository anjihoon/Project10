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
/*각각 BaseClass, DerivedClass를 선언하고 각각 int형 변수 b와 d를 선언한다.*/
int main() {
	DerivedClass derived;
	BaseClass* base = &derived;
	auto derived2 = dynamic_cast<DerivedClass*>(base);
	derived2->d = 0; // derived2의 dynamic_cast를 통해 변수 d의 값을 0으로 변환
	if (derived2->d==0) { // 즉 인스턴스 생성이 됬다면 변수 d의 값이 바꿨음으로 0이 될것이다.
		cout << "Everything is OKAY" << endl;//if else문을 통해 생성 유무 확인.
	}
	else {
		cout << "Everything is WRONG" << endl;
	}
}