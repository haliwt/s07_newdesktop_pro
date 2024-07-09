#ifndef __BSP_H
#define __BSP_H
#include "main.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


#include "FreeRTOS.h"
#include "task.h"
#include "cmsis_os.h"


#include "adc.h"
//#include "dma.h"
#include "iwdg.h"
//#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"
//bsp
#include "bsp_buzzer.h"
#include "bsp_ultrasonic.h"
#include "bsp_delay.h"
#include "bsp_ptc.h"
#include "bsp_plasma.h"
#include "bsp_sensor.h"
#include "bsp_adc.h"
#include "bsp_fan.h"
#include "bsp_led.h"
#include "bsp_key.h"
#include "bsp_ctl.h"
#include "bsp_lcd.h"
#include "bsp_usart.h"
#include "bsp_lcd_gui.h"
#include "bsp_wifi.h"
#include "bsp_image.h"
#include "bsp_tft_font.h"
#include "bsp_font.h"
#include "bsp_font_app.h"
#include "bsp_split_time.h"
#include "interrupt_manager.h"
#include "bsp_key_app.h"
#include "bsp_ntc.h"
#include "bsp_icon.h"



//wifi
#include "bsp_wifi_fun.h"
#include "bsp_esp8266.h"
#include "bsp_publish.h"
#include "bsp_subscription.h"
#include "bsp_mqtt_iot.h"

//voice 
#include "bsp_voice.h"

//
#include "bsp_freertos.h"




/* ���� BSP �汾�� */
#define __STM33G030C8T6_BSP_VERSION		"1.0"



#define  USE_FreeRTOS      1

#if USE_FreeRTOS == 1
    #include "FreeRTOS.h"
	#include "task.h"

	#define DISABLE_INT()    taskENTER_CRITICAL()
	#define ENABLE_INT()     taskEXIT_CRITICAL()
#else
	/* ¿ª¹ØÈ«¾ÖÖÐ¶ÏµÄºê */
	#define ENABLE_INT()	__set_PRIMASK(0)	/* Enable global interrupt  */
	#define DISABLE_INT()	__set_PRIMASK(1)	/* ½ûÖ¹È«¾ÖÖÐ¶Ï */
#endif


#define SAMPLE            0

typedef enum set_temp{

   disp_ptc_temp_value_item,
   dsip_set_ptc_temp_value_item,
   disp_do_setting_ptc_value_item,
   


}set_temp_item;

typedef enum{

    mode_key_set_temp = 0x01,
    mode_key_select ,
    mode_key_confirm,
    mode_key_set_timer_value,


}mode_key_state;


typedef enum _ptc_warning{

    ptc_no_warning,
	ptc_waning


}waning_t;





typedef enum{

  pro_init,
  pro_disp_dht11_value,
  pro_run_main_fun,
  pro_disp_works_time,
  pro_set_temperature,
  pro_disp_wifi_led,
  pro_mode_key_fun,
  pro_wifi_publish_init,
  pro_wifi_subscriber_init,
  pro_check_time_out,
  pro_interval_ten_minutes
  

}process_run_state;



typedef enum{

   power_off,
   power_on,



}state_power_enum;




typedef struct{

  //key
   uint8_t gKey_value;
   uint8_t gPower_On;

   

  
   uint8_t run_process_step;
   uint8_t key_power_be_pressed_flag ;
   uint8_t power_off_flag;

   //add and dec key
   uint8_t  disp_key_set_temp_value;
   uint8_t  disp_key_set_timer_timing;
   uint8_t disp_temp_or_set_tmp_switch_flag ;
   
 

   //buzzer

  
   //time
 
   uint8_t disp_works_timer_timing_mode_item;
   uint8_t set_timer_timing_success ;
   

   //wifi info

   uint8_t (*key_works_timer_timing_state)(void);
   uint8_t (*disp_works_timer_timing_state)(void);
  
 
   //modke key
  
   uint8_t mode_key_run_item_step;
   
  
  //temperature 
     uint8_t set_temperature_value_flag;

   //warning
   
   //error 
     uint8_t lcd_over_width_flag;
     uint8_t lcd_over_height_flag ;
	//wifi
	uint8_t wifi_led_fast_blink_flag;
    
	uint8_t interval_stop_run_flag ;
   
   
   //main process timer 

	uint8_t gTimer_usart_error;

	uint8_t gTime_pro_run_voice_time;

	uint8_t gTimer_pro_time_split_symbol;
	uint8_t gTimer_pro_wifi_led;
	uint8_t gTimer_pro_wifi_fast_led;
	//uint8_t gTimer_pro_long_key_timer_flag;

  uint8_t gTimer_pro_mode_key_be_select;
  uint8_t gTimer_pro_set_tem_value_blink;
  

  uint8_t gTimer_pro_set_long_key_tims;

  uint8_t gTimer_pro_update_dht11_data;
  

   uint8_t gTimer_run_total;

  //timer timing function
  uint8_t gTimer_pro_feed_dog;
  uint8_t gTimer_pro_temp_delay ;
    //timing by interrupt
  uint8_t gTimer_wifi_connect_counter;
  uint8_t gTimer_run_time_out;
  uint8_t gTimer_pro_disp_temphum;
  uint8_t gTimer_exit_mode_long_key;
  uint8_t gTimer_read_humidity_value;
  uint8_t  gTimer_fan_run_one_minute;
  int8_t gTimer_countdown_one_minute;
 
   
	

}PRO_T;


extern PRO_T gpro_t;


void bsp_Init(void);


void bsp_run_Idle(void);

void bsp_run_iwdg(void);

void PowerOnOff_Init_Ref_Fun(void);

void PowerOff_Ref_Fun(void);




void Key_Process_Handler(uint8_t keyvalue);
void PowerOn_Process_Handler(void);



void Power_Off_Process_Handler(void);



void Wifi_Fast_Led_Blink(void);

void Mode_Long_Key_Fun(void);;

void WIFI_LED_Blink(void);

void Power_Off_Special_Fun(void);

void Power_On_Special_Fun(void);



void smartphone_power_on_handler(void);


void power_on_init_set_ref(void);


#endif 
