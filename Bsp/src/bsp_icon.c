#include "bsp.h"

static void TFT_SEND_DATA(uint8_t data);
static void TFT_SEND_CMD(uint8_t cmd);

static void TFT_SetWindows(uint16_t startX,uint16_t startY,uint16_t width,uint16_t height);

/*************************************
*@brief tft_disp_humidity_image
*@details 显示图片函数,16位颜色数据先发高8位再发低八位
*@param[in] address:图片数据地址
*			startX：X起始坐标
*			startY：Y起始坐标
*@return void
*
***************************************/
void tft_disp_background_image(const uint8_t* image,uint16_t startX,uint16_t startY)
{

    uint16_t i; 
	uint8_t picH,picL;
	//Lcd_Clear(WHITE); //清屏 

    TFT_SetWindows(startX, startY, TFT_WIDTH,TFT_HEIGHT);

    for(i=0;i<320*240;i++)
    {	
        picL=*(image+i*2);	//数据低位在前
        picH=*(image+i*2+1);				
        LCD_Write_16bit_Data(picH<<8|picL);

    }	
		 
}

/*************************************
*@brief tft_disp_humidity_image
*@details 显示图片函数,16位颜色数据先发高8位再发低八位
*@param[in] address:图片数据地址
*			startX：X起始坐标
*			startY：Y起始坐标
*@return void
*
***************************************/


/*******************************************************************************************
*@brief tft_disp_humidity_image
*@details 显示图片函数,16位颜色数据先发高8位再发低八位
*@param[in] address:图片数据地址
*			startX：X起始坐标
*			startY：Y起始坐标
*@return void
*
********************************************************************************************/
void tft_disp_hum_chines_image(const uint8_t* image,uint16_t startX,uint16_t startY)
{

    uint16_t i; 
	uint8_t picH,picL;
	//Lcd_Clear(WHITE); //清屏 

    TFT_SetWindows(startX, startY, HUM_WORD_WIDTH,HUM_WORD_HEIGHT);

    for(i=0;i<(HUM_WORD_WIDTH*HUM_WORD_HEIGHT);i++)
    {	
        picL=*(image+i*2);	//数据低位在前
        picH=*(image+i*2+1);				
        LCD_Write_16bit_Data(picH<<8|picL);

    }	
		 
}



/*************************************
*@brief tft_disp_humidity_image
*@details 显示图片函数,16位颜色数据先发高8位再发低八位
*@param[in] address:图片数据地址
*			startX：X起始坐标
*			startY：Y起始坐标
*@return void
*
***************************************/
void tft_disp_temp_image(const uint8_t* image,uint16_t startX,uint16_t startY)
{

    uint16_t i; 
	uint8_t picH,picL;
	//Lcd_Clear(WHITE); //清屏 

    TFT_SetWindows(startX, startY, TEMP_ICON_WIDTH,TEMP_ICON_HEIGHT);

    for(i=0;i<(TEMP_ICON_WIDTH*TEMP_ICON_HEIGHT);i++)
    {	
        picL=*(image+i*2);	//数据低位在前
        picH=*(image+i*2+1);				
        LCD_Write_16bit_Data(picH<<8|picL);

    }	
		 
}

void TFT_Disp_Humidity_Symbol_34_34(uint16_t x,uint16_t y)
{
    uint16_t temp, t, tbit,mode;
    uint16_t x0=x;
    mode =0;
	static uint16_t color;

	for(t = 0; t < 170; t++)	/*遍历打印所有像素点到LCD */
	{   
	
		temp = s07_hum_picture[t]; 
		
		for(tbit = 0; tbit < 8; tbit++)	/* 打印一个像素点到液晶 */
		{	
			
			
			if(temp & 0x80)	color = BLACK;//WHITE;
			else if(0 == mode)	color = WHITE;//BLACK;
			else color = BLACK;
			TFT_DrawPoint(x, y,color );
			
			temp <<= 1;			
			//y++; // 垂直扫描
			x++;//水平扫描

			if(x >= LCD_Width){
                    gpro_t.lcd_over_width_flag =1;
					return;	/* 超区域了 */

			}
			
			if((x - x0) == 34){
				x = x0;
				y++;
				
			    if(y >= LCD_Height){
				gpro_t.lcd_over_height_flag=1;
				return;		/* 超区域了 */

			     }
 
				break;
			}
		}  	 
	}  

}


void TFT_Disp_Temp_Symbol_33_33(uint16_t x,uint16_t y)
{
    uint16_t temp, t, tbit,mode;
    uint16_t x0=x;
    mode =0;
	static uint16_t color;

	for(t = 0; t < 165; t++)	/*遍历打印所有像素点到LCD */
	{   
	
		temp = s07_temp_image[t]; 
		
		for(tbit = 0; tbit < 8; tbit++)	/* 打印一个像素点到液晶 */
		{	
			
			
			if(temp & 0x80)	color = BLACK;//WHITE;
			else if(0 == mode)	color = WHITE;//BLACK;
			else color = BLACK;
			TFT_DrawPoint(x, y,color );
			
			temp <<= 1;			
			//y++; // 垂直扫描
			x++;//水平扫描

			if(x >= LCD_Width){
                    gpro_t.lcd_over_width_flag =1;
					return;	/* 超区域了 */

			}
			
			if((x - x0) == 33){
				x = x0;
				y++;
				
			    if(y >= LCD_Height){
				gpro_t.lcd_over_height_flag=1;
				return;		/* 超区域了 */

			     }
 
				break;
			}
		}  	 
	}  

}



/*************************************
*@brief tft_disp_humidity_image
*@details 显示图片函数,16位颜色数据先发高8位再发低八位
*@param[in] address:图片数据地址
*			startX：X起始坐标
*			startY：Y起始坐标
*@return void
*
***************************************/
void tft_disp_humidity_image(const uint8_t* image,uint16_t startX,uint16_t startY)
{

    uint16_t i; 
	uint8_t picH,picL;
	//Lcd_Clear(WHITE); //清屏 

    TFT_SetWindows(startX, startY,  HUM_ICON_WIDTH,HUM_ICON_HEIGHT);

    for(i=0;i<(HUM_ICON_WIDTH*HUM_ICON_HEIGHT);i++)
    {	
        picL=*(image+i*2);	//数据低位在前
        picH=*(image+i*2+1);				
        LCD_Write_16bit_Data(picH<<8|picL);

    }	
		 
}
/**************************************************************
*@brief TFT_SEND_DATA
*@details 写入数据
*@param[in] data 8位数据
*@
*@
*@
**************************************************************/
static void TFT_SEND_DATA(uint8_t data)
{	
   LCD_Write_Data(data);
} 

/*************************************
*@brief TFT_SEND_CMD
*@details 写入命名
*@param[in] cmd 8位命令
*@return void
*@author zx
*@date 2022-12-18
***************************************/
static void TFT_SEND_CMD(uint8_t cmd)
{	
	LCD_Write_Cmd(cmd);	  
} 



/*************************************
* @brief   LCD_SetWindows
* @details  设置LCD显示窗口,设置完成后就可以连续发
			送颜色数据了，无需再一次一次设置坐标
* @param  startX：窗口起点x轴坐标
* 		   startY：窗口起点y轴坐标
* 		   width：窗口宽度
* 		   height：窗口高度
* @return void  
*************************************/
static void TFT_SetWindows(uint16_t startX,uint16_t startY,uint16_t width,uint16_t height)
{
#if TFT_X_OFFSET
	startX += TFT_X_OFFSET;
#endif	
#if TFT_Y_OFFSET
	startY += TFT_Y_OFFSET;
#endif		
	
	TFT_SEND_CMD(0x2A);		//发送设置X轴坐标的命令0x2A
	//参数SC[15:0]	->	设置起始列地址，也就是设置X轴起始坐标
	TFT_SEND_DATA(startX>>8);				//先写高8位
	TFT_SEND_DATA(startX&0xFF);			//再写低8位
	//参数EC[15:0]	->	设置窗口X轴结束的列地址，因为参数usXwidth是窗口长度，所以要转为列地址再发送
	TFT_SEND_DATA((startX+width-1)>>8);				//先写高8位
	TFT_SEND_DATA((startX+width-1)&0x00FF);			//再写低8位

	TFT_SEND_CMD(0x2B);		//发送设置Y轴坐标的命令0x2B
	//参数SP[15:0]	->	设置起始行地址，也就是设置Y轴起始坐标
	TFT_SEND_DATA(startY>>8);				//先写高8位
	TFT_SEND_DATA(startY&0x00FF);			//再写低8位
	//参数EP[15:0]	->	设置窗口Y轴结束的列地址，因为参数usYheight是窗口高度，所以要转为行地址再发送
	TFT_SEND_DATA((startY+height-1)>>8);				//先写高8位
	TFT_SEND_DATA((startY+height-1)&0x00FF);			//再写低8位
	TFT_SEND_CMD(0x2C);			//开始往GRAM里写数据
}


