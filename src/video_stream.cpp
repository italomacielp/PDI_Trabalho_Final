#include "video_stream.hpp"

VideoStream* video_open(const char* source) {

    VideoStream* stream = new VideoStream();

    if (source == nullptr) {
        stream->cap.open(0);
    } else {
        stream->cap.open(source);
    }

    if (!stream->cap.isOpened()) {
        delete stream;
        return nullptr;
    }

    return stream;
}

bool video_read(VideoStream* stream, cv::Mat& frame) {
    return stream && stream->cap.read(frame);
}

void video_release(VideoStream* stream) {
    if (stream) {
        stream->cap.release();
        delete stream;
    }
}

