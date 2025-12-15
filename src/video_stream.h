#ifndef VIDEO_STREAM_H
#define VIDEO_STREAM_H

#include <opencv/cv.h>

typedef struct {
    CvCapture* cap;
} VideoStream;

VideoStream* video_open(const char* source);
IplImage* video_read(VideoStream* stream);
void video_release(VideoStream* stream);

#endif
