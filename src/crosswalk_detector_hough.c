#include "crosswalk_detector_hough.h"
#include "config.h"
#include <opencv/cv.h>
#include <math.h>

void detect_crosswalk_hough(IplImage* frame) {
    IplImage* gray  = cvCreateImage(cvGetSize(frame), IPL_DEPTH_8U, 1);
    IplImage* edges = cvCreateImage(cvGetSize(frame), IPL_DEPTH_8U, 1);

    cvCvtColor(frame, gray, CV_BGR2GRAY);
    cvSmooth(gray, gray, CV_GAUSSIAN, 5, 5, 0, 0);
    cvCanny(gray, edges, CANNY_LOW, CANNY_HIGH, 3);

    CvMemStorage* storage = cvCreateMemStorage(0);
    CvSeq* lines = cvHoughLines2(
        edges,
        storage,
        CV_HOUGH_PROBABILISTIC,
        1,
        CV_PI / 180,
        HOUGH_THRESHOLD,
        MIN_LINE_LENGTH,
        MAX_LINE_GAP
    );

    int horizontal_count = 0;

    for (int i = 0; i < lines->total; i++) {
        CvPoint* line = (CvPoint*) cvGetSeqElem(lines, i);

        double dx = line[1].x - line[0].x;
        double dy = line[1].y - line[0].y;
        double angle = atan2(dy, dx) * 180.0 / CV_PI;

        if (fabs(angle) < ANGLE_THRESHOLD) {
            horizontal_count++;

            cvLine(
                frame,
                line[0],
                line[1],
                CV_RGB(0, 255, 0),
                2,
                8,
                0
            );
        }
    }

    if (horizontal_count >= 4) {
        cvPutText(
            frame,
            "FAIXA DE PEDESTRES DETECTADA",
            cvPoint(20, 40),
            &cvFont(1.0, 1.0),
            CV_RGB(0, 255, 0)
        );
    }

    cvReleaseImage(&gray);
    cvReleaseImage(&edges);
    cvReleaseMemStorage(&storage);
}
