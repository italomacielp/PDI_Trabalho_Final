#include "image_loader.h"
#include <opencv/highgui.h>

IplImage* load_image(const char* path) {
    return cvLoadImage(path, CV_LOAD_IMAGE_COLOR);
}
