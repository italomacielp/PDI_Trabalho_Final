#pragma once
#include <opencv2/opencv.hpp>

struct VideoStream {
    cv::VideoCapture cap;
};

VideoStream* video_open(const char* source);
bool video_read(VideoStream* stream, cv::Mat& frame);
void video_release(VideoStream* stream);

