#include <iostream>
#include <opencv2/opencv.hpp>

int main(){
	std::cout << "Opencv Version is : " << CV_VERSION;
	cv::Mat img = cv::imread("Lenna.png", cv::IMREAD_COLOR);
	cv::imshow("Lenna in window", img);
	cv::waitKey(0);
}