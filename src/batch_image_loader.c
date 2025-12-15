#include "batch_image_loader.h"
#include "crosswalk_detector_hough.h"
#include <opencv/highgui.h>
#include <dirent.h>
#include <string.h>
#include <stdio.h>

void process_batch(const char* folder) {
    DIR* dir = opendir(folder);
    struct dirent* entry;

    if (!dir) {
        printf("Erro ao abrir pasta de batch\n");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strstr(entry->d_name, ".jpg") ||
            strstr(entry->d_name, ".png") ||
            strstr(entry->d_name, ".jpeg")) {

            char path[256];
            sprintf(path, "%s/%s", folder, entry->d_name);

            IplImage* img = cvLoadImage(path, CV_LOAD_IMAGE_COLOR);
            if (!img) continue;

            detect_crosswalk_hough(img);

            cvShowImage("Batch", img);
            cvWaitKey(0);

            cvReleaseImage(&img);
        }
    }

    closedir(dir);
    cvDestroyAllWindows();
}
