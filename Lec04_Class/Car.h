#pragma once
#include <cstdio>
#include <cstring>
class Car {
//private:
	//�̷��� �ڽ� Ŭ������ �� �κ��� �� ����� ���Ե�.
protected:	//�ڽ� Ŭ������ ������� �� �� ����.
	int speed;
	char name[40];
public:
	int gear;
	Car(){}
	~Car(){}
	Car(int s, const char* n, int g)	//const ��������. �ٵ� �� �������°���?
		:speed(s), gear(g) {
			strcpy_s(name, n);
	}
	void changeGear(int g=4 ) {//=4
		gear = g;
	}void speedUp() {
		speed += 5;
	}void display() {
		printf("[%s] : ���=%d�� �ӵ�=%d kmph\n", name, gear, speed);
	}void whereAmI() { printf("��ü �ּ� =%x\n", this); }
};