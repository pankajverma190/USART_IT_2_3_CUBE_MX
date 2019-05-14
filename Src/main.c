/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "string.h"
#include "stdarg.h"
#include "stdio.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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
UART_HandleTypeDef huart2;
UART_HandleTypeDef huart3;

/* USER CODE BEGIN PV */
uint8_t uart2_data;
uint8_t uart3_data;

uint8_t uart3_buff[100];
uint8_t uart2_buff[100];

uint8_t uart3_count;
uint8_t uart2_count;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_USART3_UART_Init(void);
 void uart_printf(char *format,...);
/* USER CODE BEGIN PFP */
	uint8_t data[]= " WELCOME STM32F4\n";
		uint8_t data1[]= "AT\r\n";
			uint8_t data2[]= "AT+CGATT?\r\n";
				uint8_t data3[]= "AT+IPR?\r\n";
					uint8_t data4[]= "AT+SAPBR=3,1,Contype,GPRS\r\n";
						uint8_t data5[]= "AT+SAPBR=3,1,APN,www\r\n";

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{				
	  if (huart->Instance == USART3)
 {
//			if(uart3_data == '\r')
//		{
//			uart3_buff[uart3_count++]='\r';
//			
//		HAL_UART_Transmit(&huart2,uart3_buff, strlen((const char*)uart3_buff),HAL_MAX_DELAY);
//			memset(uart3_buff, 0, sizeof(uart3_buff));
//			uart3_count=0;
//		}
//		else
//		{
//			uart3_buff[uart3_count++]=uart3_data;
	//			HAL_UART_Transmit(&huart2,&uart3_data, 1,HAL_MAX_DELAY);
			//HAL_UART_Transmit(&huart2,rec_buffer, strlen((const char*)rec_buffer),HAL_MAX_DELAY);
	//	}
//	HAL_UART_Transmit(&huart2,&uart3_data, 1,HAL_MAX_DELAY);
//		HAL_UART_Receive_IT(&huart3,&uart3_data,1);
////	HAL_UART_Transmit(&uart2_config,uart3_buff, strlen((const char*)uart3_buff),HAL_MAX_DELAY);
//		
	}
	
// if (huart->Instance == USART2)
// {
//		if(uart2_data == '\n')
//		{
//			uart2_buff[uart2_count++]='\n';
//			HAL_UART_Transmit(&huart3,uart2_buff, strlen((const char*)uart2_buff),HAL_MAX_DELAY);
//				memset(uart2_buff, 0, sizeof(uart2_buff));
//			uart2_count=0;
//		}
//		else
//		{
//			uart2_buff[uart2_count++]=uart2_data;
//			//HAL_UART_Transmit(&huart2,rec_buffer, strlen((const char*)rec_buffer),HAL_MAX_DELAY);
//		}
//	//	HAL_UART_Transmit(&huart3,&uart2_data, 1,HAL_MAX_DELAY);
////	 HAL_UART_Receive_IT(&huart2,&uart2_data,1);
//	}		
}

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
  MX_USART2_UART_Init();
  MX_USART3_UART_Init();
  /* USER CODE BEGIN 2 */
	//__HAL_UART_ENABLE_IT(&huart2,UART_IT_RXNE);
HAL_UART_Receive_IT(&huart2,&uart2_data,1);

	//__HAL_UART_ENABLE_IT(&huart3,UART_IT_RXNE);
HAL_UART_Receive_IT(&huart3,&uart3_data,1);

  /* USER CODE END 2 */
//HAL_UART_Transmit(&huart3,data1, strlen((const char*)data1),HAL_MAX_DELAY);
//	HAL_Delay(3000);
//  /* Infinite loop */
//HAL_UART_Transmit(&huart3,data2, strlen((const char*)data2),HAL_MAX_DELAY);
//	HAL_Delay(3000);
//HAL_UART_Transmit(&huart3,data3, strlen((const char*)data3),HAL_MAX_DELAY);
//	HAL_Delay(3000);
//HAL_UART_Transmit(&huart3,data4, strlen((const char*)data4),HAL_MAX_DELAY);
//	HAL_Delay(3000);
//HAL_UART_Transmit(&huart3,data5, strlen((const char*)data5),HAL_MAX_DELAY);
//	HAL_Delay(3000);

  /* USER CODE BEGIN WHILE */
	uart_printf("AT\r\n");
	HAL_Delay(3000);
	uart_printf("AT+CGATT?\r\n");
	HAL_Delay(3000);
	uart_printf("AT+IPR?\r\n");
	HAL_Delay(3000);
	//uart_printf("AT+SAPBR=3,1,Contype,GPRS\r\n");
//	HAL_Delay(3000);
//	uart_printf("AT+SAPBR=3,1,APN,www\r\n");
		uart_printf("AT+CMGF=1\r\n");
	HAL_Delay(3000);
	uart_printf("AT+CMGS=8800674575\r\n");
	HAL_Delay(3000);	
	uart_printf("Pankaj");
	HAL_Delay(3000);
	uart_printf("\0x1A");
	HAL_Delay(3000);

  while (1)
  {
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

  /** Configure the main internal regulator output voltage 
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 9600;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief USART3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART3_UART_Init(void)
{

  /* USER CODE BEGIN USART3_Init 0 */

  /* USER CODE END USART3_Init 0 */

  /* USER CODE BEGIN USART3_Init 1 */

  /* USER CODE END USART3_Init 1 */
  huart3.Instance = USART3;
  huart3.Init.BaudRate = 9600;
  huart3.Init.WordLength = UART_WORDLENGTH_8B;
  huart3.Init.StopBits = UART_STOPBITS_1;
  huart3.Init.Parity = UART_PARITY_NONE;
  huart3.Init.Mode = UART_MODE_TX_RX;
  huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart3.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART3_Init 2 */

  /* USER CODE END USART3_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

}
 void uart_printf(char *format,...)
 {
	char str[255];
	char *s;
	
	/*Extract the the argument list using VA apis */
	va_list args;
	va_start(args, format);
	vsprintf(str, format,args);
	s=str;

	/* until NULL,USART_REG_SR_TXE_FLAG send out single byte in a blocking fashion */
	while(*s){
	// wait until data register is empty
	while( !(huart3.Instance->SR & UART_FLAG_TXE) );
	huart3.Instance->DR = *s;
	s++;
	}
	
	va_end(args);
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
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
