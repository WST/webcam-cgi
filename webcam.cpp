#include <opencv2/opencv.hpp>
#include <iostream>
#include <fstream>

cv::VideoCapture webcam;

void captureImage(const char *filename) {
	webcam.open(0);
	cv::Mat frame;
	webcam >> frame;
	imwrite(filename, frame);
	webcam.release();
}

int main() {
	captureImage("/tmp/tmp.jpg");
	std::cout << "Content-Type: image/jpeg\n\n";

	std::ifstream file("/tmp/tmp.jpg");
	std::string data((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
	std::cout << data;
	file.close();

	return 0;
}
