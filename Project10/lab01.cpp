#include <stdio.h>
#include <iostream>
using namespace std;
// shape�� �߻� Ŭ������ ����
class Shape {
	public:
		virtual void draw() = 0;
};
/* RoundedRectangle, RoundedSquare, Rectangle, Square�� ���� ���� �������̽��� ��������� ���
draw() �������̵��Ͽ� �� �����鿡 ���� ����� ǥ��
�������: Shape�� �پ��� �������ν�, �������� �׷�ȭ ��Ŵ*/
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
// AbstractFactory �������̽��� ����Ͽ� Shape�� ����� ���ϴ� 
//Shape* get() method�� ���
class AbstractFactory {
	public:
		static Shape* getShape(string s);
		static Shape* getRoundedShape(string s);

};
// ������ ��翡���� �з�
// if���� �̿��Ͽ� ����
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
}// ������ ���¿� ���� ��ü�� �����Ͽ� ���� ������ ���¿� �´� ����� ǥ��.