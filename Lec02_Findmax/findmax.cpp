#include <cstdio>	//stdio.h�� ������ ����� �ϴ� �������

//�迭�� �ִ��� ã�� �Լ�
int FindArrayMax(int score[], int n) {	//�ڷᱸ�� : �迭 score�� n�� �迭�� Ž���ϱ� ���� ������ ����
	int tmp = score[0]; //���ʰ��� �ʱ� �ִ����� ����
	for (int i = 1; i < n; i++) {	//�׷��� i�� 0���Ͱ� �ƴ� 1���� ������!
		if (score[i] > tmp) {
			tmp = score[i];
		}
	}
	return tmp;
}
//�����Լ�
int main() {
	int score[5] = { 1, 10, 2, 4, 5 };
	int out;
	out = FindArrayMax(score, 5);
	printf("result=%d", out);
	return 0;
}