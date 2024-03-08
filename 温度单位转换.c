/*********************************************************************
    程序名:温度单位转换程序
    版权: VibrantZing@2024
    作者: AzureHalcyon
    日期: 2024-03-08 21:18
    说明:我添加了大量的doxygen注释，在VSCode上十分赏心悦目
    	 同时，把功能都封装成函数，让功能和可移植性都增强不少
*********************************************************************/
#include "stdio.h"

/**
 * @brief 获取输入的温度单位类型和温度值
 *
 * @param inputUnit 指向整数的指针，用于存储输入的温度单位类型
 * @param temperature 指向浮点数的指针，用于存储输入的温度值
 */
void getInput(int *inputUnit, float *temperature);
/**
 * @brief 将输入的温度值从一种单位转换为另一种单位，并输出转换结果
 *
 * @param temperature 输入的温度值
 * @param inputUnit 输入的温度单位类型
 */
void convertTemperature(float temperature, int inputUnit);
/**
 * @brief 输出温度转换的结果
 *
 * @param celsius 转换后的摄氏度值
 * @param fahrenheit 转换后的华氏度值
 * @param kelvin 转换后的开尔文值
 */
void printResult(float celsius, float fahrenheit, float kelvin);

int main() {
	int inputUnit;
	float temperature;
	getInput(&inputUnit, &temperature);
	convertTemperature(temperature, inputUnit);
	return 0;
}

void getInput(int *inputUnit, float *temperature) {
	//输入温度单位类型
	printf("Enter the input temperature unit:\n");
	printf("1. Celsius\n");
	printf("2. Fahrenheit\n");
	printf("3. Kelvin\n");
	scanf("%d", inputUnit);

	//输入温度值
	printf("Enter the temperature value: ");
	scanf("%f", temperature);
}

void convertTemperature(float temperature, int inputUnit) {
	float celsius, fahrenheit, kelvin;

	// 根据输入的温度单位类型进行转换
	switch (inputUnit) {
		case 1: //摄氏度
			celsius = temperature;
			fahrenheit = (celsius * 9 / 5) + 32;
			kelvin = celsius + 273.15;
			break;
		case 2: //华氏度
			fahrenheit = temperature;
			celsius = (fahrenheit - 32) * 5 / 9;
			kelvin = celsius + 273.15;
			break;
		case 3: //开尔文
			kelvin = temperature;
			celsius = kelvin - 273.15;
			fahrenheit = (celsius * 9 / 5) + 32;
			break;
		default:
			printf("Invalid input unit!\n");
			return;
	printResult(celsius, fahrenheit, kelvin);//为什么放在这里，因为这样就可以少写一遍定义
	}


}

void printResult(float celsius, float fahrenheit, float kelvin) {
	printf("Celsius: %.2f\n", celsius);
	printf("Fahrenheit: %.2f\n", fahrenheit);
	printf("Kelvin: %.2f\n", kelvin);
}
