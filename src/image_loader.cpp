#include "image_loader.hpp"
#include <opencv2/opencv.hpp>

cv::Mat load_image(const std::string& path) {
    return cv::imread(path, cv::IMREAD_COLOR);
}

