#include "sparsepoly.hpp"

int main() {
	//���׽� ��ü A,B �����ϱ�;
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