#include "sys.h"
#include "usart.h"
#include "delay.h"
#include "FreeRTOS.h"
#include "task.h"
#include <stm32f1xx_hal_rcc_ex.h>


TaskHandle_t TestHandle_t;

void test(void *pvParameters){
  while (1)
  {
    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,GPIO_PIN_RESET);
    vTaskDelay(100);
    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,GPIO_PIN_SET);
    vTaskDelay(100);
  }
  

}

void LED_init();

int main(void)
{
    HAL_Init();                         /* 初始化HAL库 */
		
		//delay_init(72);
    Stm32_Clock_Init(RCC_PLL_MUL9); /* 设置时钟, 72Mhz */
    LED_init();
    xTaskCreate(
      test,
      "test",
      10,
      NULL,
      1,
      &TestHandle_t
    );

    vTaskStartScheduler();            /* 启动任务 */
    while(1)
    { 

    }
}

void LED_init(){
  __HAL_RCC_GPIOB_CLK_ENABLE();

  GPIO_InitTypeDef GPIO_Initure;
  GPIO_Initure.Pin=GPIO_PIN_8;
  GPIO_Initure.Mode=GPIO_MODE_OUTPUT_PP;
  GPIO_Initure.Pull=GPIO_PULLUP;
  GPIO_Initure.Speed=GPIO_SPEED_FREQ_HIGH;

  HAL_GPIO_Init(GPIOB,&GPIO_Initure);

}


