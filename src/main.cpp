#include "config.hpp"
#include "video_stream.hpp"
#include "image_loader.hpp"
#include "batch_image_loader.hpp"
#include "crosswalk_detector_hough.hpp"

#include <opencv2/opencv.hpp>
#include <iostream>

int main() {

#ifdef BATCH_FOLDER

    process_batch(BATCH_FOLDER);

#elif defined(IMAGE_PATH)

    cv::Mat img = load_image(IMAGE_PATH);
    if (img.empty()) {
        std::cerr << "Erro ao carregar imagem\n";
        return 1;
    }

    detect_crosswalk_hough(img);

    // 🔹 salva resultado
    cv::imwrite("result/output.png", img);

    cv::imshow("Imagem", img);
    cv::waitKey(0);

#else

    VideoStream* video = video_open(nullptr);
    if (!video) {
        std::cerr << "Erro ao abrir stream de video\n";
        return 1;
    }

    cv::Mat frame;

    while (video_read(video, frame)) {
        detect_crosswalk_hough(frame);

        cv::imshow("Video", frame);
        if (cv::waitKey(30) == 27) break; // ESC
    }

    video_release(video);

#endif

    cv::destroyAllWindows();
    return 0;
}

