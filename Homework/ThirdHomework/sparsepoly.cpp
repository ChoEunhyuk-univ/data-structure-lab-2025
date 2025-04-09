#include "sparsepoly.hpp"

int main() {
	//다항식 객체 A,B 생성하기;
	SparsePoly A;
	SparsePoly B;

	A.read();
	A.display("poly A is : ");

	B.read();
	B.display("poly B is : ");

	SparsePoly C;
	C.add(A,B);
	C.display("\npoly C = A+B is : ");
}