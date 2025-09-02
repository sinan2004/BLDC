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

/* USER CODE END PV */

 while (1)
  {
    /* USER CODE END WHILE */

	  	  mainloop++;

	  	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);

	  	  //enable pin always  high
	  	  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_10, SET);
	 	  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_11, SET);
	 	  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_12, SET);

	 	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, RESET); //PHASE
	 	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, RESET);
	 	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, RESET);



	 	  hall_A = (GPIOA ->IDR& GPIO_PIN_15)?1:0;
	 	  hall_B = (GPIOB ->IDR& GPIO_PIN_3)?1:0;
	 	  hall_C = (GPIOB ->IDR& GPIO_PIN_10)?1:0;



	 	  hall_state = (hall_A<<2)|(hall_B<<1)|hall_C;

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
