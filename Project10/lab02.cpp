#include<stdio.h>
#include<iostream>

using namespace std;

struct DrawAPI {
	virtual void drawCircle(int radius, int x, int y)=0;

};
// DrawAPI �������̽��� �����ϴ� �긴�� Ŭ���� ����
struct RedCircle :  DrawAPI {
	virtual void drawCircle(int radius, int x, int y) override{
		cout << "Drawing Circle[ color: red, radius: "
			<< radius << ", x: " << x << ", " <<y << "]" << endl;
	}
};

class GreenCircle : public DrawAPI {
public:
	virtual void drawCircle(int radius, int x, int y) override{
		cout << "Drawing Circle[ color: green, radius: "
			<< radius << ", x: " << x << ", " <<y << "]" << endl;
	}
};
// DrawAPI �������̽���  ��ü������ �����ϴ� �긴�� �ۼ�
struct Shape {
protected:
	DrawAPI& drawAPI;
	Shape(DrawAPI& drawAPI) : drawAPI{ drawAPI } {}
public:
	virtual void draw() = 0;
};

struct Circle : Shape {
	int radius, x, y;

	void draw() override {
		drawAPI.drawCircle(radius, x, y);
	}
	Circle(DrawAPI& drawAPI, int radius, int x, int y) 
		: Shape{ drawAPI }, radius{ radius }, x{ x }, y{ y }{}
};
//Shape �� �߻�Ŭ������ DrawAPI �������̽��� ����Ͽ� �����Ѵ�.
int main() {
	RedCircle rc;
	Circle drawCircle{rc,10,100,100};
	drawCircle.draw();

	GreenCircle gc;
	Circle drawCircle2{gc,10,100,100 };
	drawCircle.draw();
}
//���� ��ü�� ������ �� ����Ѵ�.
