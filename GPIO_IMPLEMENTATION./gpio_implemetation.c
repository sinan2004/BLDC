#include "main.h"

/* USER CODE BEGIN PV */

#define UH 	GPIO_PIN_8
#define VH	GPIO_PIN_9
#define WH	GPIO_PIN_10

#define ENu GPIO_PIN_10
#define ENv GPIO_PIN_11
#define ENw	GPIO_PIN_12

uint8_t hall_A= 0b0;
uint8_t hall_B= 0b0;
uint8_t hall_C= 0b0;
uint8_t hall_state = 0b111;
uint8_t speed = 0;



const uint8_t control_lookup[7][6] = {{0,0,0,0,0,0},
									  {1,0,0,1,1,0},
									  {0,1,0,0,1,1},
									  {1,0,0,1,0,1},
									  {0,0,1,1,0,1},
									  {0,0,1,0,1,1},
									  {0,1,0,1,1,0}};

uint8_t control_lookup_pos = 0b000000;



/* USER CODE END PV */

 while (1)
  {
		  mainloop++;
	 	  hall_A = (GPIOA ->IDR& GPIO_PIN_15)?1:0;
	 	  hall_B = (GPIOB ->IDR& GPIO_PIN_3)?1:0;
	 	  hall_C = (GPIOB ->IDR& GPIO_PIN_10)?1:0;

	 	  hall_state = (hall_A<<2)|(hall_B<<1)|hall_C;

		  if(direction == 0)
		  {
			hall_state--;
			hall_state = (hall_state == 0) ? 6: hall_state;
		  }
		  else
		  {
			hall_state ++;
			hall_state = (hall_state == 7) ? 1: hall_state;
		  }
	  
	  		// lookup table------------------------------------------------
	  
	  	 	HAL_GPIO_WritePin(GPIOA, UH, control_lookup[hall_state][0]);
			HAL_GPIO_WritePin(GPIOA, VH, control_lookup[hall_state][1]);
			HAL_GPIO_WritePin(GPIOA, WH, control_lookup[hall_state][2]);


			HAL_GPIO_WritePin(GPIOC, ENu, control_lookup[hall_state][3]);
			HAL_GPIO_WritePin(GPIOC, ENv, control_lookup[hall_state][4]);
			HAL_GPIO_WritePin(GPIOC, ENw, control_lookup[hall_state][5]);

			control_lookup_pos = control_lookup[hall_state][0]<<5|control_lookup[hall_state][1]<<4|control_lookup[hall_state][2]<<3|
								 control_lookup[hall_state][3]<<2|control_lookup[hall_state][4]<<1|control_lookup[hall_state][5];

	  	  

	  // switchcase------------------------------------------------
	  
	  	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5); //LED

	  	  //enable pin always  high
	  	  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_10, SET);
	 	  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_11, SET);
	 	  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_12, SET);

	 	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, RESET); //PHASE
	 	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, RESET);
	 	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, RESET);

	 	  switch(hall_state)
	 	  {
	 	      case 1:

//				HAL_GPIO_WritePin(GPIOA, UH, FLOAT);
				HAL_GPIO_WritePin(GPIOA, VH, SET);
				HAL_GPIO_WritePin(GPIOA, WH, RESET);

				HAL_GPIO_WritePin(GPIOC, ENu, RESET);
	 	          break;
	 	      case 2:
				HAL_GPIO_WritePin(GPIOA, UH, SET);
//				HAL_GPIO_WritePin(GPIOA, VH, FLOAT);
				HAL_GPIO_WritePin(GPIOA, WH, RESET);

				HAL_GPIO_WritePin(GPIOC, ENv, RESET);

	 	          break;
	 	      case 3:
				HAL_GPIO_WritePin(GPIOA, UH, RESET);
//				HAL_GPIO_WritePin(GPIOA, VH, FLOAT);
				HAL_GPIO_WritePin(GPIOA, WH, SET);

				HAL_GPIO_WritePin(GPIOC, ENv, RESET);

	 			  break;
	 	      case 4:
//				HAL_GPIO_WritePin(GPIOA, UH, FLOAT);
				HAL_GPIO_WritePin(GPIOA, VH, RESET);
				HAL_GPIO_WritePin(GPIOA, WH, SET);

				HAL_GPIO_WritePin(GPIOC, ENu, RESET);

	 			  break;

	 	      case 5:
				HAL_GPIO_WritePin(GPIOA, UH, RESET);
				HAL_GPIO_WritePin(GPIOA, VH, SET);
//				HAL_GPIO_WritePin(GPIOA, WH, FLOAT);

				HAL_GPIO_WritePin(GPIOC, ENw, RESET);

	 			  break;

	 	      case 6:
				HAL_GPIO_WritePin(GPIOA, UH, SET);
				HAL_GPIO_WritePin(GPIOA, VH, RESET);
//				HAL_GPIO_WritePin(GPIOA, WH, FLOAT);

				HAL_GPIO_WritePin(GPIOC, ENw, RESET);
	 			  break;
	 	      default:
	 	    	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, RESET); //PHASE
	 	    	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, RESET);
	 	    	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, RESET);

	 	  }
  }





