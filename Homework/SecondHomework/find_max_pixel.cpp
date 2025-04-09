/*
1/ �׷��̽����Ϸ� �ϴ°� ���ؿ�
2/ 2���� �迭�� ������. ���� ������ ���Ǯ���� 1row(1columb, 2, 3, 4... ) next 2row �̷�������.
3/ �׷��ϱ�, �ᱹ 1�������� Ȯ���ΰ���. �迭���� �ִ��� �̾Ƴ� ����. �� �ִ��� �ٽ� �ڿ��ſ� ���ؼ� ǥ���ϴ°���.

*/
#include <opencv2/opencv.hpp>	//opencv ���̺귯��.
#include <iostream>	//�ֿܼ� ����ϱ� ������.

int display(int cols, int rows, int pixel) {		//�ֿܼ� ���� ���� ������.
	std::cout << "###########################################" << std::endl;
	std::cout << " �� : " << cols << " / ���� : " << rows << " / �ִ� ȭ�Ұ� : "<<pixel<<std::endl;
	std::cout << "###########################################" << std::endl;
	return 0;
}

int main() {
	cv::Mat img = cv::imread("lenna.png", cv::IMREAD_GRAYSCALE);	//color���� �ϸ� 255.
	int width = img.cols;
	int height = img.rows;

	int** pixel;	//���� �Ҵ�Ǵ� �迭�����
	pixel = (int**)malloc(sizeof(int*) * height);
	for (int i = 0; i < height; i++) {
		pixel[i] = (int*)malloc(sizeof(int) * width);
	}

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			pixel[y][x]=static_cast<int>(img.at<uchar>(y, x));
		}
	}

	int brightest = pixel[0][0];

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			if (brightest < pixel[y][x]) brightest = pixel[y][x];
		}
	}

	display(width, height, brightest);

	for (int i = 0; i < height; i++) {
		free(pixel[i]);
	}
	free(pixel);


	cv::imshow("windows", img);
	cv::waitKey(50000);
}