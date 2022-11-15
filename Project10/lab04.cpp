#include <iostream>
#include <cassert>
using namespace std;

class CEO {
public: // rank1 CEO Ŭ������ ����
	virtual void func() {} 
	virtual ~CEO() {}// CEO �Ҹ��� ����
};

class CPO {
public:   // rank2 CPO Ŭ������ ����
	virtual void funct() {}
};


class Manager : public CEO, CPO {}; // rank3 Ŭ������ rank1, rank2 ��ӹ޴� Ŭ������ ����
class Staff : public CPO {}; // rank4 Ŭ������ ������ CPO�� rank4�� �������� rank3�� ��� �ް� �Ѵ�
 
int main() {
	CPO* cpo = new Staff;
	Staff* staff = dynamic_cast<Staff*>(cpo);
	Manager* manager = dynamic_cast<Manager*>(cpo);
	CEO* ceo = dynamic_cast<CEO*>(cpo);
	assert(typeid(cpo) == typeid(Staff*));
}
/*CPO* �����ϰ� ������ cpo�� �����Ͽ� rank4�� �Ҵ��Ѵ�.
staff* ,Manager* , CEO* �� ���� �����ϰ� dynamic_cast����
assert()�� �̿��Ͽ� cpo�� staff*�� typeid�� ��
*/