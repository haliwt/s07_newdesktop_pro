#ifndef __BSP_LCD_GUI_H
#define __BSP_LCD_GUI_H
#include "main.h"

#define TFT_DISP_TEMP_24   0


#define TIMER_X0    35//5//100
#define TIMER_Y     80//150

#define TIMER_X1    60//30//125
#define TIMER_X2    85//55 //150
#define TIMER_X3  	110//80//175

//
#define DIS_TIME_X0   80
#define DIS_TIME_Y    190

#define DIS_TIME_X1    114

#define DIS_TIME_X2    166

#define DIS_TIME_X3    200

//hours display position
#define WORKS_HOUR_X0   15 //5//80
#define WORKS_HOUR_Y0   120 //190

#define WORKS_HOUR_X1    49//39//114

//minute display position
#define WORKS_MINUTE_X0    101//91// 166
#define WORKS_MINUTE_Y0    120 //190

#define WORKS_MINUTE_X1    135//125//200
//time of colon
#define TIME_COLON_X0   75//65  
#define TIME_COLON_Y0   103//173
//humidity display position
#define HUM_LOCAT_X0   200//160
#define HUM_LOCAT_Y0   45//40

#define HUM_LOCAT_X1   254//214
//humidity icon
#define HUM_SYMBOL_X0   180
#define HUM_SYMBOL_Y0   5
//humidity chinese words 
#define  HUM_WORD_X0    250//219
#define  HUM_WORD_Y0     15

//temperature display position
#define  TEMP_LOCAT_X0   200//160
#define  TEMP_LOCAT_Y0   170

#define  TEMP_LOCAT_X1  254 //214
//temperature of icon positon
#define  TEMP_SYMBOL_X0   180
#define  TEMP_SYMBOL_Y0   122//120

#define  TEMP_WORD_X0     250//219
#define  TEMP_WORD_Y0     132//130






void TFT_DrawPoint(uint16_t x,uint16_t y,uint16_t color);

void TFT_SetWindow(uint16_t xstart,uint16_t ystart,uint16_t xend,uint16_t yend);

void TFT_St7789_SetBGColor(uint32_t color);

void TFT_St7789_FillBlock(uint16_t xstart,uint16_t ystart,uint16_t block_width,uint16_t block_height,uint16_t color);
void TFT_ST7789_FillPicture(uint16_t xstart,uint16_t ystart,uint16_t block_width,uint16_t block_height,const uint8_t *black_data);


void TFT_Disp_Temp_Value(uint8_t bc,uint8_t temp_value);
void TFT_Disp_Humidity_Value(uint8_t hum_value);

void TFT_ShowString(uint16_t x,uint16_t y,char *str,uint8_t fw,uint8_t fh,uint8_t mode);

//void TFT_ShowFont(uint8_t x,uint8_t y,char *font,uint8_t fw,uint8_t fh,uint8_t mode);

void TFT_ShowText(uint16_t x,uint16_t y,char *str,uint8_t fw,uint8_t fh,uint8_t mode);

void TFT_ShowPicture(uint16_t x,uint16_t y,const uint8_t *p,uint8_t pw,uint8_t ph);

void TFT_Works_Or_Timer_times_Handler(void);

void TFT_Display_Handler(void);

void TFT_Works_Or_Timer_times_Handler(void);

void lcd_draw_rectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color);

void TFT_Display_Temp_Symbol(void);

void TFT_Display_Humidity_Symbol(void);

void TFT_Display_WorksTime(void);
void TFT_Only_Disp_Timing(void);



void TFT_Disp_Set_TimerTime(uint8_t bc);
void TFT_Disp_Set_TimerTime_Init(void);




void TFT_DonnotDisp_Works_Time(void);


void TFT_Disp_Voice_Temp_Value(uint8_t bc,uint8_t temp_value);

void TFT_Disp_Voice_Set_TimerTime_Init(void);

void TFT_Disp_Onley_Set_TimerTime_Value(void);

void TFT_Only_Disp_Set_Timer_Blink(void);

void TFT_Display_WorksTime_Voice(void);

void TFT_Display_PowerOn_WorksTime_Init(void);

void TFT_Disp_Only_Humidity_Numbers(uint8_t hum_value);

void TFT_Disp_Only_Temp_Numbers(uint8_t bc,uint8_t temp_value);

void TFT_Disp_Temp_SwitchSet_Value(uint8_t bc,uint8_t temp_value);

void TFT_Display_Update_Handler(void);

void TFT_Display_Precise_WorksTime(void);

void TFT_Display_TempHumidity_Icon_Init_Handler(void);

void TFT_Disp_CountDown_60s(uint8_t idata);

void Donot_Disp_CountDown_60s(void);


#endif

