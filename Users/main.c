#include "SYSTEM/sys/sys.h"
#include "SYSTEM/usart/usart.h"
#include "SYSTEM/delay/delay.h"



int main(void)
{
    HAL_Init();                         /* 初始化HAL库 */
		delay_init(72);
    Stm32_Clock_Init(RCC_PLL_MUL9); /* 设置时钟, 72Mhz */
    
    while(1)
    { 

    }
}


