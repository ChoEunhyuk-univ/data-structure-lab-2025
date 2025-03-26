#include <stdio.h>
#define MAX_SIZE	10	//함수값 정의하기. define은 배웠다시피 상수 지정할때 쓰는거임.
						//상수 정의할때는 이제부턴 tab으로 띄우고 해야함.

void sub(int x, int arr[]) {
	x = 10;
	arr[0] = 10;
}

void main() {
	int var = 0, list[MAX_SIZE];
	list[0] = 0;
	sub(var, list);
	printf("var=%d , list[0]=%d\n", var, list[0]);	//잘 보면 sub 실행 이후 var와 list가 변경되어있음.
}
