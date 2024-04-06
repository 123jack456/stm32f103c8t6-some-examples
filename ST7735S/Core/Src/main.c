/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "Lcd_Driver.h"
//#include "LCD_Config.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */
  lcd_init();
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
//  showimage(gImage_zz);
//  HAL_Delay(5000);
showPicture();
HAL_Delay(3000);
lcd_set_color(0XFFFF);
showChinese(2,1, WHITE,BLACK,0);
showChinese(2,2, WHITE,BLACK,2);
showchar(3,1,WHITE,BLACK,'@');
HAL_Delay(3000);
lcd_set_color(0XFFFF);
OLED_ShowString(3,1,WHITE,BLACK,"hello world!");
showChinese(3,7, WHITE,BLACK,0);
showChinese(3,8, WHITE,BLACK,2);
//showChinese(2,2, WHITE,BLACK,2);
//showChinese(2,1, RED,BLACK,0);
//showChinese(2,2, RED,BLACK,2);
//showChinese(2,3, RED,BLACK,0);
//showChinese(2,4, RED,BLACK,2);
//showChinese(2,5, RED,BLACK,0);
//showChinese(2,6, RED,BLACK,2);
//showChinese(2,7, RED,BLACK,0);
//showChinese(2,8, RED,BLACK,2);
//showChinese(2,9, RED,BLACK,0);
//showChinese(2,10,RED,BLACK,2);
//showchar(1,1,RED,BLACK,'a');
//OLED_ShowString(3,1,RED,BLACK,"hello world!");
//showChinese(2,1,GREEN,0);
//showChinese(3,1,BLUE ,0);
//showChinese(4,1,RED  ,0);
//showChinese(5,1,GREEN,0);
//showChinese(6,1,BLUE ,0);
//showChinese(7,1,RED  ,0);
//showChinese(8,1,GREEN,0);
//showChinese(9,1,BLUE  ,0);
//showChinese(10,1,RED,0);
  while (1)
  {
//	  lcd_set_color(GREEN);
//	  HAL_Delay(500);
//	  lcd_set_color(BLUE);
//	  HAL_Delay(500);
//	  lcd_set_color(RED);
//	  HAL_Delay(500);
//	  lcd_set_color(WHITE);
//	  HAL_Delay(500);
//	  lcd_set_color(BLACK);
//	  HAL_Delay(500);
//	  lcd_set_area_color(0,80,100,160,GRAY0);
//	  HAL_Delay(1000);
//	  showimage(gImage_zz);
//	  HAL_Delay(5000);
//	  lcd_draw_line(0,0,128,RED);
//	  lcd_draw_line(0,127,160,GREEN);
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
