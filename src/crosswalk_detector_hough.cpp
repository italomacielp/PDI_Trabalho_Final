#include "crosswalk_detector_hough.hpp"
#include "config.hpp"

#include <opencv2/opencv.hpp>
#include <cmath>

void detect_crosswalk_hough(cv::Mat& frame) {

    cv::Mat gray, edges;

    // 1. Converter para escala de cinza
    cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);

    // 2. Suavização Gaussiana
    cv::GaussianBlur(gray, gray, cv::Size(5, 5), 0);

    // 3. Detector de bordas Canny
    cv::Canny(gray, edges, CANNY_LOW, CANNY_HIGH);

    // 4. Transformada de Hough Probabilística
    std::vector<cv::Vec4i> lines;
    cv::HoughLinesP(
        edges,
        lines,
        1,
        CV_PI / 180,
        HOUGH_THRESHOLD,
        MIN_LINE_LENGTH,
        MAX_LINE_GAP
    );

    int horizontal_count = 0;

    // 5. Análise das linhas detectadas
    for (const auto& l : lines) {

        double dx = l[2] - l[0];
        double dy = l[3] - l[1];
        double angle = std::atan2(dy, dx) * 180.0 / CV_PI;

        if (std::fabs(angle) < ANGLE_THRESHOLD) {
            horizontal_count++;

            cv::line(
                frame,
                cv::Point(l[0], l[1]),
                cv::Point(l[2], l[3]),
                cv::Scalar(0, 255, 0),
                2
            );
        }
    }

    // 6. Decisão: faixa de pedestres detectada
    if (horizontal_count >= 4) {
        cv::putText(
            frame,
            "FAIXA DE PEDESTRES DETECTADA",
            cv::Point(20, 40),
            cv::FONT_HERSHEY_SIMPLEX,
            1.0,
            cv::Scalar(0, 255, 0),
            2
        );
    }
}

