//1차원 배열에서 최댓값을 구해서 반환하는 함수 구현하기

/*
슈도코드?
array=[1,3,5,-2,3, ..... an]
int arraymax;
for i 1 to n
	if arraymax > array[n] then arraymax = array[n]

print arraymax

*/

#include <cstdio>
#define MAX 5
int main() {
	int arraymax;
	int array[5] = {};

	for (int i = 0; i < MAX; i++) {	//배열 입력받는부분
		printf("array[%d] is = ", i);
		scanf_s("%d", &array[i]);
		printf("\n");
	}
	arraymax = array[0];

	for (int k = 0; k < MAX; k++) {	//배열속 최댓값과 대조하는 부분
		if (arraymax < array[k]) {
			arraymax = array[k];
		}
	}
	printf("arraymax is = %d", arraymax);

}