/*
1) numTerms�� �� ������ ��� ���ޱ�.
2) sparsepoly�� 2���� �迭�� ����. (n x 2), ������� sparsepoly[2][1]�̸� 3��° �׿��� ����� �ǹ���. �ڿ�ĭ�� ������ ����.
3) n-1��° ���� ����� ������ for������ �ޱ�.
4) sparsepoly�� ����.

�ٵ� ������ ������, malloc�� ����ϰ� �׷��� �ڵ� ���̱� ����.
�׷��� �츮�� std ���ɷ� ���Ͷ����� Ǯ�� �Ǵ°���.
���� numterms�� ���ʿ� nx2 ��ķ� ������ �ʿ䵵 ������. �׳� ������ �޾Ƽ� ���� ��.
*/

#pragma once
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#define	MAX_DEGREE 101

class SparsePoly {
	int numTerms;	//���� ���� �ޱ�.
	std::vector<int> exp;
	std::vector<float> cof;

public:
	SparsePoly() {}

	void read() {
		printf("\n���� ������ �Է��ϼ��� : ");
		scanf_s("%d", &numTerms);
		if (numTerms > MAX_DEGREE) exit(0);	//�ִ����� �ʰ��� ���α׷� ��������

		exp.resize(numTerms);
		cof.resize(numTerms);
		for (int terms = 0; terms < numTerms; terms++) {
			printf("%d��° ���� ����� ������ �Է��ϼ��� : ", terms + 1);
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
	���� �˰��� ���� : ������ �����Ѱ� ���� �����̴ϱ�...
	�ٵ� ���� ���� �״�� �����ع����� ������, ���� �� ����� ������ ���� �������� �ʴٸ�? �׷��� ��� ǰ?
	�׷��� ���� �ݺ����� �Ἥ. a1,a2,a3... �ϴµ��� b�� 2���� �迭 �������� ���� �������Ѻ��ٸ�?
	
	�׷����� ���� �׷��ʿ� ����, �Ʊ� ������ cof�� exp ���� �迭�� ���� ��.
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
					break;		//break�� ���� ������, �������׵��� ������ �������� ���� ����Ȯ���� �� ����.
				}
			}
			if (!found) {
				exp.push_back(b.exp[i]);	//������ �� ���� ���ο� ���(b.~~[i])�� �߰��ϴ� �Լ���.
				cof.push_back(b.cof[i]);	//�̰� ���� ������ ũ�Ⱑ 1��ŭ �þ��, ���ο� ��Ұ� ������ ��ġ�� ���Ե�.
				numTerms++;					//�������, b���� a�� ���� x^3���� �ִ� �Ҷ�, exp�� cof�� �� ���� ������ �߰��Ǹ� �����Ȱɷ� ó����!
			}
		}
	}

};
