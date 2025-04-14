#pragma once
#include <cstdio>
#include <cstring>
class Car {
//private:
	//이러면 자식 클래스는 이 부분을 못 끌어다 쓰게됨.
protected:	//자식 클래스는 여기까진 쓸 수 있음.
	int speed;
	char name[40];
public:
	int gear;
	Car(){}
	~Car(){}
	Car(int s, const char* n, int g)	//const 넣으세요. 근데 왜 오류나는거임?
		:speed(s), gear(g) {
			strcpy_s(name, n);
	}
	void changeGear(int g=4 ) {//=4
		gear = g;
	}void speedUp() {
		speed += 5;
	}void display() {
		printf("[%s] : 기어=%d단 속도=%d kmph\n", name, gear, speed);
	}void whereAmI() { printf("객체 주소 =%x\n", this); }
};