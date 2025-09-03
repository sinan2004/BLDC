#include "main.h"

/* USER CODE BEGIN PV */
//#define UH 	GPIO_PIN_8 //original config
//#define VH	GPIO_PIN_9
//#define WH	GPIO_PIN_10


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

uint8_t dir = 1;


//const uint8_t control_lookup[7][6] = {{0,0,0,0,0,0},
//		                              {0,1,0,1,1,0},
//									  {1,0,0,1,1,0},
//									  {0,1,0,0,1,1},
//									  {1,0,0,1,0,1},
//									  {0,0,1,1,0,1},
//									  {0,0,1,0,1,1},
//									  };

const uint8_t control_lookup[7][6] = {{0,0,0,0,0,0},
		                              {1,0,0,1,1,0},
									  {1,0,0,1,0,1},
									  {0,1,0,0,1,1},
									  {0,1,0,1,1,0},
									  {0,0,1,1,0,1},
									  {0,0,1,0,1,1}};


uint8_t control_lookup_pos = 0b000000;
uint8_t delay = 5;


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

//	  	 	  if(dir == 0)
//	  	 	  {
//	  	 		 hall_state--;
//	  	 		 hall_state = (hall_state == 0) ? 6: hall_state;
//	  	 	  }
//	  	 	  else
//	  	 	  {
//	  	 		hall_state++;
//	  	 	    hall_state = (hall_state == 7) ? 1: hall_state;
//	  	 	  }

	  	 	HAL_GPIO_WritePin(GPIOA, UH, control_lookup[hall_state][0]);
			HAL_GPIO_WritePin(GPIOA, VH, control_lookup[hall_state][1]);
			HAL_GPIO_WritePin(GPIOA, WH, control_lookup[hall_state][2]);

			HAL_GPIO_WritePin(GPIOC, ENu, control_lookup[hall_state][3]);
			HAL_GPIO_WritePin(GPIOC, ENv, control_lookup[hall_state][4]);
			HAL_GPIO_WritePin(GPIOC, ENw, control_lookup[hall_state][5]);

			if(hall_state == 1){state_1++;}
			if(hall_state == 2){state_2++;}
			if(hall_state == 3){state_3++;}
			if(hall_state == 4){state_4++;}
			if(hall_state == 5){state_5++;}
			if(hall_state == 6){state_6++;}

//			control_lookup_pos = control_lookup[hall_state][0]<<5|control_lookup[hall_state][1]<<4|control_lookup[hall_state][2]<<3|
//								 control_lookup[hall_state][3]<<2|control_lookup[hall_state][4]<<1|control_lookup[hall_state][5];

//	  	 	  switch(hall_state)
//	  	 	  {
//	  	 	      case 1:
//	  				HAL_GPIO_WritePin(GPIOA, UH, SET);
//	  				HAL_GPIO_WritePin(GPIOA, VH, RESET);
//	  				HAL_GPIO_WritePin(GPIOA, WH, RESET);
//
//
//	  				HAL_GPIO_WritePin(GPIOC, ENu, SET);
//	  				HAL_GPIO_WritePin(GPIOC, ENv, SET);
//	  				HAL_GPIO_WritePin(GPIOC, ENw, RESET);
//	  				state_1++;
//	  	 	          break;
//	  	 	      case 2:
//	  	 	    	HAL_GPIO_WritePin(GPIOA, UH, RESET);
//	  	 	    	HAL_GPIO_WritePin(GPIOA, VH, SET);
//	  				HAL_GPIO_WritePin(GPIOA, WH, RESET);
//
//	  				HAL_GPIO_WritePin(GPIOC, ENu, RESET);
//	  				HAL_GPIO_WritePin(GPIOC, ENv, SET);
//	  				HAL_GPIO_WritePin(GPIOC, ENw, SET);
//	  				state_2++;
//
//	  	 	          break;
//	  	 	      case 3:
//	  				HAL_GPIO_WritePin(GPIOA, UH, SET);
//	  				HAL_GPIO_WritePin(GPIOA, VH, RESET);
//	  				HAL_GPIO_WritePin(GPIOA, WH, RESET);
//
//	  				HAL_GPIO_WritePin(GPIOC, ENu, SET);
//	  				HAL_GPIO_WritePin(GPIOC, ENv, RESET);
//	  				HAL_GPIO_WritePin(GPIOC, ENw, SET);
//
//	  				state_3++;
//
//	  	 			  break;
//	  	 	      case 4:
//	  				HAL_GPIO_WritePin(GPIOA, UH, RESET);
//	  				HAL_GPIO_WritePin(GPIOA, VH, RESET);
//	  				HAL_GPIO_WritePin(GPIOA, WH, SET);
//
//
//	  				HAL_GPIO_WritePin(GPIOC, ENu, SET);
//	  				HAL_GPIO_WritePin(GPIOC, ENv, RESET);
//	  				HAL_GPIO_WritePin(GPIOC, ENw, SET);
//	  				state_4++;
//	  	 			  break;
//
//	  	 	      case 5:
//	  	 	    	HAL_GPIO_WritePin(GPIOA, UH, RESET);
//	  				HAL_GPIO_WritePin(GPIOA, VH, RESET);
//	  				HAL_GPIO_WritePin(GPIOA, WH, SET);
//
//	  				HAL_GPIO_WritePin(GPIOC, ENu, RESET);
//	  				HAL_GPIO_WritePin(GPIOC, ENv, SET);
//	  				HAL_GPIO_WritePin(GPIOC, ENw, SET);
//	  				state_5++;
//	  	 			  break;
//
//	  	 	      case 6:
//	  				HAL_GPIO_WritePin(GPIOA, UH, RESET);
//	  				HAL_GPIO_WritePin(GPIOA, VH, SET);
//	  				HAL_GPIO_WritePin(GPIOA, WH, RESET);
//
//	  				HAL_GPIO_WritePin(GPIOC, ENu, SET);
//	  				HAL_GPIO_WritePin(GPIOC, ENv, SET);
//	  				HAL_GPIO_WritePin(GPIOC, ENw, RESET);
//	  				state_6++;
//	  	 			  break;
//
//	  	 	      default:
//	  	 	    	  HAL_GPIO_WritePin(GPIOA, UH, RESET); //PHASE
//	  	 	    	  HAL_GPIO_WritePin(GPIOA, VH, RESET);
//	  	 	    	  HAL_GPIO_WritePin(GPIOA, WH, RESET);
//
//	  	 	    	HAL_GPIO_WritePin(GPIOA, ENu, RESET); //ENABLE
//	  	 	    	HAL_GPIO_WritePin(GPIOA, ENv, RESET);
//	  	 	    	HAL_GPIO_WritePin(GPIOA, ENw, RESET);
//
//	  	 	  }





    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}





