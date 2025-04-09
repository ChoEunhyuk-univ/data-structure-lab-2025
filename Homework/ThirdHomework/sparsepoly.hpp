/*
1) numTerms를 항 갯수로 잡고 값받기.
2) sparsepoly를 2차원 배열로 선언. (n x 2), 예를들어 sparsepoly[2][1]이면 3번째 항에서 계수를 의미함. 뒤에칸은 차수로 놓고.
3) n-1번째 항의 계수와 차수를 for문으로 받기.
4) sparsepoly를 저장.

근데 저러면 문제가, malloc을 써야하고 그러면 코드 꼬이기 쉬움.
그래서 우리가 std 배운걸로 벡터때려서 풀면 되는거임.
따라서 numterms는 애초에 nx2 행렬로 정의할 필요도 없었음. 그냥 차수만 받아서 쓰면 됨.
*/

#pragma once
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#define	MAX_DEGREE 101

class SparsePoly {
	int numTerms;	//항의 개수 받기.
	std::vector<int> exp;
	std::vector<float> cof;

public:
	SparsePoly() {}

	void read() {
		printf("\n항의 개수를 입력하세요 : ");
		scanf_s("%d", &numTerms);
		if (numTerms > MAX_DEGREE) exit(0);	//최대차수 초과시 프로그램 강제종료

		exp.resize(numTerms);
		cof.resize(numTerms);
		for (int terms = 0; terms < numTerms; terms++) {
			printf("%d번째 항의 계수와 차수를 입력하세요 : ", terms + 1);
			scanf_s("%f %d", &cof[terms], &exp[terms]);
		}
	}
	char poly;
	void display(const char* poly) {
		printf(poly);
		for (int terms = 0; terms < numTerms; terms++) {
			printf("%.2fx^%d", cof[terms], exp[terms]);
			if (terms < numTerms - 1) {
				if (cof[terms] > 0) printf(" + ");
				if (cof[terms] < 0)printf(" - ");
			}
		}
	}

	/*
	덧셈 알고리즘 구현 : 차수가 동일한거 끼리 덧셈이니까...
	근데 저거 텀즈 그대로 덧셈해버리면 문제가, 만약 저 텀즈당 차수가 둘이 동일하지 않다면? 그러면 어떻게 품?
	그러면 이중 반복문을 써서. a1,a2,a3... 하는동안 b는 2차원 배열 돌리듯이 둘을 대조시켜본다면?
	
	그렇지만 굳이 그럴필요 없이, 아까 정의한 cof와 exp 인자 배열을 쓰면 됨.
	*/

	void add(const SparsePoly& a, const SparsePoly& b) {
		exp = a.exp;
		cof = a.cof;
		numTerms = a.numTerms;

		for (int i = 0; i < b.numTerms; i++) {
			bool found = 0;
			for (int j = 0; j < numTerms; j++) {
				if (b.exp[i] == exp[j]) {  
					cof[j] += b.cof[i];
					found = 1;
					break;		//break를 쓰지 않으면, 동차수항들이 여러번 더해지며 값이 부정확해질 수 있음.
				}
			}
			if (!found) {
				exp.push_back(b.exp[i]);	//벡터의 맨 끝에 새로운 요소(b.~~[i])를 추가하는 함수임.
				cof.push_back(b.cof[i]);	//이걸 쓰면 벡터의 크기가 1만큼 늘어나고, 새로운 요소가 마지막 위치에 삽입됨.
				numTerms++;					//예를들어, b에는 a에 없는 x^3항이 있다 할때, exp와 cof에 이 항의 정보가 추가되며 덧셈된걸로 처리함!
			}
		}
	}

};
