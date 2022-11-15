#include <stdio.h>
#include <iostream>
using namespace std;
// shape의 추상 클래스를 생성
class Shape {
	public:
		virtual void draw() = 0;
};
/* RoundedRectangle, RoundedSquare, Rectangle, Square에 대해 각각 인터페이스를 명시적으로 사용
draw() 오버라이드하여 각 도형들에 대한 출력을 표시
도형모양: Shape의 다양한 구현으로써, 모형별로 그룹화 시킴*/
class RoundedRectangle : public Shape {
public:
	void draw() override {
		cout << "Inside RoundedRectangle::draw() method."
			<< endl;
	}
};

class RoundedSquare : public Shape {
public:
	void draw() override {
		cout << "Inside RoundedSquare::draw() method."
			<< endl;
	}
};

class Rectangle : public Shape {
	public:
		void draw() override {
			cout << "Inside Rectangle::draw() method."
				<< endl;
	}
};

class Square : public Shape {
public:
	void draw() override {
		cout << "Inside Square::draw() method."
			<< endl;
	}
};
// AbstractFactory 인터페이스를 사용하여 Shape의 모양을 정하는 
//Shape* get() method를 사용
class AbstractFactory {
	public:
		static Shape* getShape(string s);
		static Shape* getRoundedShape(string s);

};
// 도형의 모양에따라 분류
// if문을 이용하여 구별
class ShapeFactory : public AbstractFactory {
	public:
		static Shape* getShape(string s);
};
Shape* ShapeFactory::getShape(string s) {
	if (s == "RECTANGLE")
		return new Rectangle();
	if (s == "SQUARE")
		return new Square();
	}

class RoundedShapeFactory : public AbstractFactory {
public:
	static Shape* getRoundedShape(string s);
};
Shape* RoundedShapeFactory::getRoundedShape(string s) {
	if (s == "RECTANGLE")
		return new RoundedRectangle();
	if (s == "SQUARE")
		return new RoundedSquare();
}

class FactoryProducer {
	public:
		static Shape* getRoundedShape(string s);
};
Shape* FactoryProducer::getRoundedShape(string s) {
	if (s == "Rounded") {
		return new RoundedRectangle();
	}
	else {
		return new RoundedSquare();
	}
}

int main() {
	ShapeFactory* sf = new ShapeFactory();
	Shape* s1 = sf->getShape("RECTANGLE");
	s1->draw();
	Shape* s2 = sf->getShape("SQUARE");
	s2->draw();
	RoundedShapeFactory* sf2 = new RoundedShapeFactory();
	Shape* s3 = sf2->getRoundedShape("RECTANGLE");
	s3->draw();
	Shape* s4 = sf2->getRoundedShape("SQUARE");
	s4->draw();
}// 도형의 형태에 따라 객체를 생성하여 각각 도형의 형태에 맞는 출력을 표현.