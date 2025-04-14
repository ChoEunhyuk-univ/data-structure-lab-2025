//복소수연산 헤더파일임
#pragma once	//이건 소스코드에서 다시 헤더파일을 로드하는 일이 없도록 하는 용도임
#include <cstdio>	//늘 쓰던 stdio.h랑 비슷한거임
class Complex {
	double real;
	double imag;
public:		//모든 멤버함수를 inline으로 구현해서 Complex.cpp가 필요 없음.
	void set(double r, double i) {
		real = r;
		imag = i;
	}void read(const char* msg = "복소수 = ") {
		printf(" %s ", msg);
		scanf_s("%lf%lf", &real, &imag);
	}void print(const char* msg = "복소수 = ") {
		printf("%s %4.2f + %4.2fi\n", msg, real, imag);
	}void add(Complex a, Complex b) {
		real = a.real + b.real;
		imag = a.imag + b.imag;
	}
};