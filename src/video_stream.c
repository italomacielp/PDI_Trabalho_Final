#include "video_stream.h"
#include <opencv/highgui.h>
#include <stdlib.h>

VideoStream* video_open(const char* source) {
    VideoStream* stream = malloc(sizeof(VideoStream));

    if (source == NULL)
        stream->cap = cvCaptureFromCAM(0);
    else
        stream->cap = cvCaptureFromFile(source);

    if (!stream->cap) {
        free(stream);
        return NULL;
    }
    return stream;
}

IplImage* video_read(VideoStream* stream) {
    return cvQueryFrame(stream->cap);
}

void video_release(VideoStream* stream) {
    if (stream) {
        cvReleaseCapture(&stream->cap);
        free(stream);
    }
}
