#include <cstdio>	//stdio.h와 동일한 기능을 하는 헤더파일

//배열속 최댓값을 찾는 함수
int FindArrayMax(int score[], int n) {	//자료구조 : 배열 score와 n은 배열을 탐색하기 위해 지정한 정수
	int tmp = score[0]; //최초값을 초기 최댓값으로 설정
	for (int i = 1; i < n; i++) {	//그래서 i가 0부터가 아닌 1부터 시작함!
		if (score[i] > tmp) {
			tmp = score[i];
		}
	}
	return tmp;
}
//메인함수
int main() {
	int score[5] = { 1, 10, 2, 4, 5 };
	int out;
	out = FindArrayMax(score, 5);
	printf("result=%d", out);
	return 0;
}