#include<stdio.h>
#include<math.h>

int main()
{
	int i,j,k;
	float x1 = 0,y1 = 0,bu = 0,bd = 0,b = 0,a = 0,rd = 0,rd1 = 0,r = 0;
	
	printf("������һ����������ʾ�ж��������ݣ�xi��yi��\n");
	scanf("%d",&i);
	printf("ÿ������һ��x��y���ո����\n");
	float x[i],y[i];
	
	for(j = 0;j < i;j++)
	{
		scanf("%f %f",&x[j],&y[j]);
		x1 += x[j];
		y1 += y[j];
	}
	
	x1 /= i;
	y1 /= i;
	
	for(j = 0;j < i;j++)
	{
		bu += (x[j] - x1) * (y[j] - y1);
		bd += (x[j] - x1) * (x[j] - x1);
		rd1 += (y[j] - y1) * (y[j] - y1);
	}
	
	rd = sqrt(bd) * sqrt(rd1);
	r = bu / rd;
	b = bu / bd;
	a = y1 - b * x1;
	
	printf("r=%f,b=%f,a=%f",r,b,a);
	
	return 0;
}
