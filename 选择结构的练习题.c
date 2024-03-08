/*********************************************************************
    程序名:选择结构的练习题
    版权: VibrantZing@2024
    作者: AzureHalcyon
    日期: 2024-03-08 22:16
    说明: 用于练习选择结构。如果选项较少，用if条件句很简单。涉及多条件选择时，switch语句则更显简洁。对函数进行了封装：逻辑是先在主函数里执行do-while循环，根据循环结果调用选择函数，最后跳转到对应的问题上。在一次循环结束的时候，我进行了清空缓存区的操作，防止上次的输入影响下一次循环。
*********************************************************************/
#include "stdio.h"

int selectProblem();
void solveProblem(int choice);
void weekday(int day);
int isLeapYear(int year);
float calculate(float num1, char op, float num2);
void zodiacSign(int month);
void mood(int day);
void compareIntegers(float num1, float num2);
void clearBuffer();

//注：这里本来想在头文件里声明，但是想到写这个的初衷就是一个文件搞定，另外学习通也不方便提交头文件，所以不得不忍受这么一大坨声明。。。真难看。
int main() {
	char continueChoice;
	do {
		int choice = selectProblem();
		solveProblem(choice);
		printf("是否要进行其他操作？(y/n): ");
		clearBuffer(); // 清空输入缓冲区
		scanf("%c", &continueChoice);
	} while (continueChoice == 'y' || continueChoice == 'Y');

	printf("程序结束。\n");
	return 0;
}


/**
 * @brief 选择要解决的问题
 *
 * @return 选择问题编号
 */
int selectProblem() {
	int choice;
	printf("选择要解决的问题：\n"
	       "1. 判断星期几\n"
	       "2. 检查是否闰年\n"
	       "3. 执行计算\n"
	       "4. 确定星座\n"
	       "5. 根据星期几判断情绪\n"
	       "6. 判断两个数字的大小\n");
	scanf("%d", &choice);
	return choice;
}

/**
 * @brief 解决选择的问题
 *
 * @param choice 选择的问题编号
 */
void solveProblem(int choice) {
	switch (choice) {
		case 1: {
			int userDay;
			printf("请输入星期几的数字（1-7）：");
			scanf("%d", &userDay);
			weekday(userDay);
		}
		break;
		case 2: {
			int userYear;
			printf("请输入年份：");
			scanf("%d", &userYear);
			isLeapYear(userYear);
		}
		break;
		case 3: {
			float num1, num2;
			char op;
			printf("请输入两个数字和运算符（例如：1 + 1）：");
			scanf("%f %f %c", &num1, &op, &num2 );
			calculate(num1, op, num2 );
		}
		break;
		case 4: {
			int userMonth;
			printf("请输入月份：");
			scanf("%d", &userMonth);
			zodiacSign(userMonth);
		}
		break;
		case 5: {
			int userDay;
			printf("请输入星期几的数字（1-7）：");
			scanf("%d", &userDay);
			mood(userDay);
		}
		break;
		case 6:
			float num1, num2;
			printf("请输入两个数，用空格分隔：");
			scanf("%f %f", &num1, &num2);
			compareIntegers(num1, num2);
			break;
		default:
			printf("无效的选择！\n");
	}
}

/**
 * @brief 根据输入的数字确定星期几的英文输出
 *
 * @param day 星期几的数字（1-7）
 */
void weekday(int day) {
	switch (day) {
		case 1:
			printf("Monday\n");
			break;
		case 2:
			printf("Tuesday\n");
			break;
		case 3:
			printf("Wednesday\n");
			break;
		case 4:
			printf("Thursday\n");
			break;
		case 5:
			printf("Friday\n");
			break;
		case 6:
			printf("Saturday\n");
			break;
		case 7:
			printf("Sunday\n");
			break;
		default:
			printf("无效的星期几数字！\n");
	}
}

/**
 * @brief 判断年份是否为闰年
 *
 * @param year 要检查的年份
 * @return 如果年份是闰年，则返回1，否则返回0
 */
int isLeapYear(int year) {
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
		printf("%d年是闰年。\n", year);
		return 1;
	} else {
		printf("%d年不是闰年。\n", year);
		return 0;
	}
}

/**
 * @brief 根据运算符执行计算
 *
 * @param num1 第一个数字
 * @param num2 第二个数字
 * @param op 运算符（+，-，*，/）
 * @return 计算结果
 */
float calculate(float num1, char op, float num2 ) {
	float result;
	switch (op) {
		case '+':
			result = num1 + num2;
			break;
		case '-':
			result = num1 - num2;
			break;
		case '*':
			result = num1 * num2;
			break;
		case '/':
			if (num2 != 0)
				result = num1 / num2;
			else {
				printf("错误：除数不能为零！\n");
				return 0;
			}
			break;
		default:
			printf("无效的运算符！\n");
			return 0;
	}
	printf("结果：%.2f\n", result);
	return result;
}

/**
 * @brief 根据输入的月份确定星座
 *
 * @param month 月份数字（1-12）
 */
void zodiacSign(int month) {
	switch (month) {
		case 1:
			printf("摩羯座\n");
			break;
		case 2:
			printf("水瓶座\n");
			break;
		case 3:
			printf("双鱼座\n");
			break;
		case 4:
			printf("白羊座\n");
			break;
		case 5:
			printf("金牛座\n");
			break;
		case 6:
			printf("双子座\n");
			break;
		case 7:
			printf("巨蟹座\n");
			break;
		case 8:
			printf("狮子座\n");
			break;
		case 9:
			printf("处女座\n");
			break;
		case 10:
			printf("天秤座\n");
			break;
		case 11:
			printf("天蝎座\n");
			break;
		case 12:
			printf("射手座\n");
			break;
		default:
			printf("无效的月份数字！\n");
	}
}

/**
 * @brief 根据输入的星期几判断情绪
 *
 * @param day 星期几的数字（1-7）
 */
void mood(int day) {
	switch (day) {
		case 1:
			printf("broken\n");
			break;
		case 2:
			printf("my heart is hoping\n");
			break;
		case 3:
			printf("my empty arms are open\n");
			break;
		case 4:
			printf("waiting for love\n");
			break;
		case 5:
			printf("thanks\n");
			break;
		case 6:
			printf("burning like a fire on wild\n");
			break;
		case 7:
			printf("guess I won't come to the church'\n");
			break;
		default:
			printf("无效的星期几数字！\n");
	}
}

/**
 * @brief 比较两个整数的大小并输出结果
 *
 * @param num1 第一个整数
 * @param num2 第二个整数
 */
void compareIntegers(float num1, float num2) {
	if ((float)num1 > (float)num2) {
		printf("%.2f 大于 %.2f\n", num1, num2);
	} else if (num1 < num2) {
		printf("%.2f 小于 %.2f\n", num1, num2);
	} else {
		printf("%.2f 等于 %.2f\n", num1, num2);
	}
}


/**
 * @brief 清空输入缓冲区
 */
void clearBuffer() {
	while (getchar() != '\n');
}
