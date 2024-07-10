#ifndef __BSP_ICON_H
#define __BSP_ICON_H
#include "main.h"

#define TEMP_ICON_WIDTH        33
#define TEMP_ICON_HEIGHT        33

#define HUM_ICON_WIDTH       34
#define HUM_ICON_HEIGHT      34

#define TFT_WIDTH     320
#define TFT_HEIGHT    240

#define HUM_WORD_WIDTH         62     
#define HUM_WORD_HEIGHT        29

void tft_disp_background_image(const uint8_t* image,uint16_t startX,uint16_t startY);


void tft_disp_temp_image(const uint8_t* image,uint16_t startX,uint16_t startY);


void tft_disp_humidity_image(const uint8_t* image,uint16_t startX,uint16_t startY);



void tft_disp_hum_chines_image(const uint8_t* image,uint16_t startX,uint16_t startY);


void TFT_Disp_Humidity_Symbol_34_34(uint16_t x,uint16_t y);

void TFT_Disp_Temp_Symbol_33_33(uint16_t x,uint16_t y);


#endif 

