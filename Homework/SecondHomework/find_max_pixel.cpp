/*
1/ 그레이스케일로 하는게 편해요
2/ 2차원 배열을 쓸거임. 진행 순서는 행렬풀듯이 1row(1columb, 2, 3, 4... ) next 2row 이런식으로.
3/ 그러니까, 결국 1번과제의 확장인거임. 배열에서 최댓값을 뽑아낸 다음. 이 최댓값을 다시 뒤에거와 비교해서 표현하는거지.

*/
#include <opencv2/opencv.hpp>	//opencv 라이브러리.
#include <iostream>	//콘솔에 출력하기 위함임.

int display(int cols, int rows, int pixel) {		//콘솔에 사진 폭을 띄울거임.
	std::cout << "###########################################" << std::endl;
	std::cout << " 폭 : " << cols << " / 높이 : " << rows << " / 최대 화소값 : "<<pixel<<std::endl;
	std::cout << "###########################################" << std::endl;
	return 0;
}

int main() {
	cv::Mat img = cv::imread("lenna.png", cv::IMREAD_GRAYSCALE);	//color모드로 하면 255.
	int width = img.cols;
	int height = img.rows;

	int** pixel;	//동적 할당되는 배열만들기
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