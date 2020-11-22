#include "led.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "OLED_I2C.h"
u8 flag=0;	
unsigned char BMP[1024];
 int main(void)
 {	
	delay_init();	    	 //延时函数初始化	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);// 设置中断优先级分组2
	uart_init(500000);	 //串口初始化为500000
	LED_Init();		  	 //初始化与LED连接的硬件接口 
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	I2C_Configuration();
	OLED_Init();
	
	OLED_CLS();//清屏
	
 OLED_ShowStr(35, 3, "BiliBili", 2);
	while(1)
	{
	if(flag==1)
	{
		OLED_DrawBMP(0,0,128,8,(unsigned char *)BMP);//测试BMP位图显示
		flag=0;
	}
	}	 
}


