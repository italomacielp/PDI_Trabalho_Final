#include "config.h"
#include "video_stream.h"
#include "image_loader.h"
#include "batch_image_loader.h"
#include "crosswalk_detector_hough.h"
#include <opencv/highgui.h>

int main() {

#if BATCH_FOLDER != NULL
    process_batch(BATCH_FOLDER);

#elif IMAGE_PATH != NULL
    IplImage* img = load_image(IMAGE_PATH);
    detect_crosswalk_hough(img);

    cvShowImage("Imagem", img);
    cvWaitKey(0);
    cvReleaseImage(&img);

#else
    VideoStream* video = video_open(NULL);
    IplImage* frame;

    while ((frame = video_read(video)) != NULL) {
        detect_crosswalk_hough(frame);

        cvShowImage("Video", frame);
        if (cvWaitKey(30) == 27) break;
    }

    video_release(video);
#endif

    cvDestroyAllWindows();
    return 0;
}
