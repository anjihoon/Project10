#include <iostream>
#include <cassert>
using namespace std;

class CEO {
public: // rank1 CEO 클래스를 생성
	virtual void func() {} 
	virtual ~CEO() {}// CEO 소멸자 생성
};

class CPO {
public:   // rank2 CPO 클래스를 생성
	virtual void funct() {}
};


class Manager : public CEO, CPO {}; // rank3 클래스를 rank1, rank2 상속받는 클래스로 생성
class Staff : public CPO {}; // rank4 클래스를 문제의 CPO와 rank4와 비교함으로 rank3를 상속 받게 한다
 
int main() {
	CPO* cpo = new Staff;
	Staff* staff = dynamic_cast<Staff*>(cpo);
	Manager* manager = dynamic_cast<Manager*>(cpo);
	CEO* ceo = dynamic_cast<CEO*>(cpo);
	assert(typeid(cpo) == typeid(Staff*));
}
/*CPO* 선언하고 변수명 cpo로 설정하여 rank4를 할당한다.
staff* ,Manager* , CEO* 를 각각 선언하고 dynamic_cast진행
assert()를 이용하여 cpo와 staff*의 typeid값 비교
*/