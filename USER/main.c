#include "led.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "OLED_I2C.h"
u8 flag=0;	
unsigned char BMP[1024];
 int main(void)
 {	
	delay_init();	    	 //��ʱ������ʼ��	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);// �����ж����ȼ�����2
	uart_init(500000);	 //���ڳ�ʼ��Ϊ500000
	LED_Init();		  	 //��ʼ����LED���ӵ�Ӳ���ӿ� 
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	I2C_Configuration();
	OLED_Init();
	
	OLED_CLS();//����
	
 OLED_ShowStr(35, 3, "BiliBili", 2);
	while(1)
	{
	if(flag==1)
	{
		OLED_DrawBMP(0,0,128,8,(unsigned char *)BMP);//����BMPλͼ��ʾ
		flag=0;
	}
	}	 
}


