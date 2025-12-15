#include "batch_image_loader.hpp"
#include "crosswalk_detector_hough.hpp"

#include <opencv2/opencv.hpp>
#include <dirent.h>
#include <string>
#include <cstdio>

void process_batch(const char* folder) {

    if (!folder) {
        std::printf("Pasta de batch nao definida\n");
        return;
    }

    DIR* dir = opendir(folder);
    if (!dir) {
        std::printf("Erro ao abrir pasta de batch: %s\n", folder);
        return;
    }

    struct dirent* entry;

    while ((entry = readdir(dir)) != nullptr) {

        std::string name(entry->d_name);

        if (name.find(".jpg")  == std::string::npos &&
            name.find(".png")  == std::string::npos &&
            name.find(".jpeg") == std::string::npos) {
            continue;
        }

        std::string input_path  = std::string(folder) + "/" + name;
        std::string output_path = std::string("result/") + name;

        cv::Mat img = cv::imread(input_path, cv::IMREAD_COLOR);
        if (img.empty()) {
            std::printf("Falha ao carregar imagem: %s\n", input_path.c_str());
            continue;
        }

        detect_crosswalk_hough(img);

        // 🔹 SALVA RESULTADO
        cv::imwrite(output_path, img);

        // 🔹 opcional: mostrar na tela
        cv::imshow("Batch", img);
        cv::waitKey(0);
    }

    closedir(dir);
    cv::destroyAllWindows();
}

