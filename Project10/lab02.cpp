#include<stdio.h>
#include<iostream>

using namespace std;

struct DrawAPI {
	virtual void drawCircle(int radius, int x, int y)=0;

};
// DrawAPI 인터페이스를 구현하는 브릿지 클래스 생성
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
// DrawAPI 인터페이스를  구체적으로 구현하는 브릿지 작성
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
//Shape 의 추상클래스를 DrawAPI 인터페이스를 사용하여 구현한다.
int main() {
	RedCircle rc;
	Circle drawCircle{rc,10,100,100};
	drawCircle.draw();

	GreenCircle gc;
	Circle drawCircle2{gc,10,100,100 };
	drawCircle.draw();
}
//각각 객체를 생성한 후 출력한다.
