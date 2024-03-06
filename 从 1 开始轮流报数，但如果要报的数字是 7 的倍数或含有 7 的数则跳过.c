#include "stdio.h"
/**
 * @brief 一个简单的报数游戏程序
 * 
 * 这个程序模拟了一个报数游戏，游戏规则如下：
 * - 一群人依次报数，从1开始，依次递增。
 * - 当报数的数字满足以下条件之一时，需要跳过：
 *   - 含有数字7；
 *   - 是7的倍数。
 * - 统计每个人报数的次数，分为三个队伍，分别以1、2、3开头。
 * - 用户输入报数的轮数，程序输出每个队伍报数的次数。
 * - 程序运行结束后，提示用户按任意键退出。
 * @param n 报数的轮数
 */
int main() {
	int i, one, two, three, k, n, a[10000], b[10000], c[10000], d[10000], e[10000];
	printf("enter the value of round \n");
	scanf( "%d", &n);
	for (i = 1, one = 0, two = 0, three = 0, k = 0;; i++) {
		if (i > 10000)
			break; //越界检查
		a[i] = i % 10;
		b[i] = i / 10 % 10;
		c[i] = i / 100 % 10;
		d[i] = i / 1000 % 10;
		e[i] = i / 10000 % 10;
		if (a[i] == 7 || b[i] == 7 || c[i] == 7 || d[i] == 7 || e[i] == 7 || i % 7 == 0) {
			if (i % 3 == 1) {
				one ++;
			} else if (i % 3 == 2) {
				two++;
			} else if (i % 3 == 0) {
				three++;
			}
			k++;
		}
		if (i - k == n) {
			break;
		}
	}
	printf ( "%d, %d, %d", one, two, three);
	printf("press any key to exit...");
	getchar();
	return 0 ;
}
