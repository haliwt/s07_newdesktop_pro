#ifndef __BSP_ICON_H
#define __BSP_ICON_H
#include "main.h"

#define TEMP_ICON_WIDTH        29
#define TEMP_ICON_HEIGHT        29

void tft_disp_temp_image(const uint8_t* image,uint16_t startX,uint16_t startY);


void tft_disp_humidity_image(const uint8_t* image,uint16_t startX,uint16_t startY);





#endif 

