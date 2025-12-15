#ifndef CONFIG_H
#define CONFIG_H

/* ====== MODOS DE EXECUÇÃO ======
 * Prioridade:
 * 1) BATCH_FOLDER
 * 2) IMAGE_PATH
 * 3) VIDEO_SOURCE
 */

#define BATCH_FOLDER "images/batch"  
#define IMAGE_PATH   NULL             
#define VIDEO_SOURCE 0                

#define CANNY_LOW 50
#define CANNY_HIGH 150

#define HOUGH_THRESHOLD 80
#define MIN_LINE_LENGTH 60
#define MAX_LINE_GAP 10

#define ANGLE_THRESHOLD 15.0  

#endif
