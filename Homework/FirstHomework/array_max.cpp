//1���� �迭���� �ִ��� ���ؼ� ��ȯ�ϴ� �Լ� �����ϱ�

/*
�����ڵ�?
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

	for (int i = 0; i < MAX; i++) {	//�迭 �Է¹޴ºκ�
		printf("array[%d] is = ", i);
		scanf_s("%d", &array[i]);
		printf("\n");
	}
	arraymax = array[0];

	for (int k = 0; k < MAX; k++) {	//�迭�� �ִ񰪰� �����ϴ� �κ�
		if (arraymax < array[k]) {
			arraymax = array[k];
		}
	}
	printf("arraymax is = %d", arraymax);

}