#include "main.h"



/* USER CODE BEGIN PV */



#define VH 	GPIO_PIN_8
#define WH	GPIO_PIN_9
#define UH	GPIO_PIN_10


#define ENu GPIO_PIN_10 //ORIGINAL CONFIG
#define ENv GPIO_PIN_11
#define ENw	GPIO_PIN_12



uint8_t hall_A= 0b0;
uint8_t hall_B= 0b0;
uint8_t hall_C= 0b0;

uint8_t hall_state = 0b111;

uint32_t mainloop = 0;

uint32_t state_1 =0;
uint32_t state_2 =0;
uint32_t state_3 =0;
uint32_t state_4 =0;
uint32_t state_5 =0;
uint32_t state_6 =0;

uint8_t dir = 0;

const uint8_t fr_control_lookup[7][6]  = {{0,0,0,0,0,0}, //trial 02 smooth without delay //DIR 0
										  {1,0,0,1,1,0}, //10Z
										  {0,0,1,0,1,1}, //Z01
										  {1,0,0,1,0,1}, //1Z0
										  {0,0,1,1,0,1}, //0Z1
										  {0,1,0,1,1,0}, //01Z
										  {0,1,0,0,1,1}, //Z10
										};

const uint8_t re_control_lookup[7][6] = {{0,0,0,0,0,0},//reset        //DIR 1
									     {1,0,0,1,1,0},//10Z
									     {0,1,0,0,1,1},//Z10
									     {0,1,0,0,1,1},//01Z
									     {0,0,1,1,0,1},//0Z1 trial 02 reverse
									     {1,0,0,1,0,1},//1Z0
									     {0,0,1,0,1,1},//Z01
		                                };


uint8_t control_lookup_pos = 0b000000;
uint8_t delay = 5;


/* USER CODE END PV */

/* USER CODE END PV */
  while (1)
  {
    /* USER CODE END WHILE */
	  mainloop++;
	  	  HAL_Delay(delay);

	  	  	  	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);

	  	  	 	  hall_A = (GPIOA ->IDR& GPIO_PIN_15)?1:0;
	  	  	 	  hall_B = (GPIOB ->IDR& GPIO_PIN_3)?1:0;
	  	  	 	  hall_C = (GPIOB ->IDR& GPIO_PIN_10)?1:0;

	  	  	 	  hall_state = (hall_A<<2)|(hall_B<<1)|hall_C;






	  	  	 	  if(dir == 0)
	  	  	 	  	  {

	  					HAL_GPIO_WritePin(GPIOA, UH, fr_control_lookup[hall_state][0]);
	  					HAL_GPIO_WritePin(GPIOA, VH, fr_control_lookup[hall_state][1]);
	  					HAL_GPIO_WritePin(GPIOA, WH, fr_control_lookup[hall_state][2]);

	  					HAL_GPIO_WritePin(GPIOC, ENu, fr_control_lookup[hall_state][3]);
	  					HAL_GPIO_WritePin(GPIOC, ENv, fr_control_lookup[hall_state][4]);
	  					HAL_GPIO_WritePin(GPIOC, ENw, fr_control_lookup[hall_state][5]);
	  	  	 	  	  }

	  	  	 	  else
	  	  	 	  {
	  					HAL_GPIO_WritePin(GPIOA, UH, re_control_lookup[hall_state][0]);
	  					HAL_GPIO_WritePin(GPIOA, VH, re_control_lookup[hall_state][1]);
	  					HAL_GPIO_WritePin(GPIOA, WH, re_control_lookup[hall_state][2]);

	  					HAL_GPIO_WritePin(GPIOC, ENu, re_control_lookup[hall_state][3]);
	  					HAL_GPIO_WritePin(GPIOC, ENv, re_control_lookup[hall_state][4]);
	  					HAL_GPIO_WritePin(GPIOC, ENw, re_control_lookup[hall_state][5]);
	  	  	 	  }


    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}






