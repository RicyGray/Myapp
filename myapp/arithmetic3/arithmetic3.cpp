#include"pch.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#pragma warning(disable:4996)

typedef struct {		//分数结构体声明
	int fenzi = 0;
	int fenmu = 1;
}fenshu;
void yuefen(int &m, int &n) //约去分子分母的公约数
{
	int p;
	p = (m + n - abs(m - n)) / 2;//p为m，n中较小值
	for (int i = 2; i <= p; i++)
		if (m%i == 0 && n%i == 0)
		{
			m /= i;
			n /= i;
			i = 2;
		}
}
fenshu Add(fenshu a1, fenshu a2) {			//加法
	fenshu a3;
	int f, g;
	f = a1.fenzi * a2.fenmu + a1.fenmu * a2.fenzi;
	g = a1.fenmu * a2.fenmu;
	yuefen(f, g);
	a3.fenzi = f;
	a3.fenmu = g;
	return a3;
}

fenshu minus(fenshu a1, fenshu a2) {	//减法
	fenshu a3;
	int f, g;
	f = a1.fenzi * a2.fenmu - a1.fenmu * a2.fenzi;
	g = a1.fenmu * a2.fenmu;
	yuefen(f, g);
	a3.fenzi = f;
	a3.fenmu = g;
	return a3;
}

fenshu division(fenshu a1, fenshu a2) {	//除法
	fenshu a3;
	int f, g;
	f = a1.fenzi * a2.fenmu;
	g = a1.fenmu * a2.fenzi;
	yuefen(f, g);
	a3.fenzi = f;
	a3.fenmu = g;
	return a3;
}

fenshu multiplication(fenshu a1, fenshu a2) {	//乘法
	fenshu a3;
	int f, g;
	f = a1.fenzi * a2.fenzi;
	g = a1.fenmu * a2.fenmu;
	yuefen(f, g);
	a3.fenzi = f;
	a3.fenmu = g;
	return a3;
}
void daying(char a, fenshu a1, fenshu a2, fenshu a5, int number, int max, FILE *fp, FILE *bp) {
	switch (a)
	{
	case '+':   //加法
		a5 = Add(a1, a2);
		yuefen(a5.fenzi, a5.fenmu);
		if (a5.fenzi < a5.fenmu)
		{
			fprintf(fp, "%d .四则运算题目%d/%d+%d/%d=%d/%d\n", number, a1.fenzi, a1.fenmu, a2.fenzi, a2.fenmu, a5.fenzi, a5.fenmu);
			fprintf(bp, "%d .答案=%d/%d\n", number, a5.fenzi, a5.fenmu); break;
		}
		else
			if (a5.fenmu == 1)
			{
				fprintf(fp, "%d.四则运算题目%d/%d+%d/%d=%d\n", number, a1.fenzi, a1.fenmu, a2.fenzi, a2.fenmu, a5.fenzi);
				fprintf(bp, "%d.答案=%d\n", number, a5.fenzi); break;
			}
			else
			{
				fprintf(fp, "%d.四则运算题目%d/%d+%d/%d=%d'%d/%d\n", number, a1.fenzi, a1.fenmu, a2.fenzi, a2.fenmu, a5.fenzi / a5.fenmu, a5.fenzi%a5.fenmu, a5.fenmu);
				fprintf(bp, "%d.答案=%d'%d/%d\n", number, a5.fenzi / a5.fenmu, a5.fenzi%a5.fenmu, a5.fenmu); break;
			}
	case '-': a5 = minus(a1, a2);  //减法
		yuefen(a5.fenzi, a5.fenmu);
		if (a5.fenzi < 0) {
			a1.fenzi = rand() % max + 1;
			a2.fenzi = rand() % max + 1;
			a1.fenmu = rand() % max + 1;
			a2.fenmu = rand() % max + 1;
			yuefen(a1.fenzi, a1.fenmu);
			yuefen(a2.fenzi, a2.fenmu);
			a5 = minus(a1, a2);
			yuefen(a5.fenzi, a5.fenmu);
		}
		if (a5.fenzi < a5.fenmu)
		{
			fprintf(fp, "%d.四则运算题目%d/%d-%d/%d=%d/%d\n", number, a1.fenzi, a1.fenmu, a2.fenzi, a2.fenmu, a5.fenzi, a5.fenmu);
			fprintf(bp, "%d.答案=%d/%d\n", number, a5.fenzi, a5.fenmu); break;
		}
		else
			if (a5.fenmu == 1)
			{
				fprintf(fp, "%d.四则运算题目%d/%d-%d/%d=%d\n", number, a1.fenzi, a1.fenmu, a2.fenzi, a2.fenmu, a5.fenzi);
				fprintf(bp, "%d.答案=%d\n", number, a5.fenzi); break;
			}
			else
			{
				fprintf(fp, "%d.四则运算题目%d/%d-%d/%d=%d'%d/%d\n", number, a1.fenzi, a1.fenmu, a2.fenzi, a2.fenmu, a5.fenzi / a5.fenmu, a5.fenzi%a5.fenmu, a5.fenmu);
				fprintf(bp, "%d.答案=%d'%d/%d\n", number, a5.fenzi / a5.fenmu, a5.fenzi%a5.fenmu, a5.fenmu); break;
			}
	case '*': a5 = multiplication(a1, a2); //乘法
		yuefen(a5.fenzi, a5.fenmu);

		if (a5.fenzi < a5.fenmu)
		{
			fprintf(fp, "%d.四则运算题目%d/%d*%d/%d=%d/%d\n", number, a1.fenzi, a1.fenmu, a2.fenzi, a2.fenmu, a5.fenzi, a5.fenmu);
			fprintf(bp, "%d.答案=%d/%d\n", number, a5.fenzi, a5.fenmu); break;
		}
		else
			if (a5.fenmu == 1)
			{
				fprintf(fp, "%d.四则运算题目%d/%d*%d/%d=%d\n", number, a1.fenzi, a1.fenmu, a2.fenzi, a2.fenmu, a5.fenzi);
				fprintf(bp, "%d.答案=%d\n", number, a5.fenzi); break;
			}
			else
			{
				fprintf(fp, "%d.四则运算题目%d/%d*%d/%d=%d'%d/%d\n", number, a1.fenzi, a1.fenmu, a2.fenzi, a2.fenmu, a5.fenzi / a5.fenmu, a5.fenzi%a5.fenmu, a5.fenmu);
				fprintf(bp, "%d.答案=%d'%d/%d\n", number, a5.fenzi / a5.fenmu, a5.fenzi%a5.fenmu, a5.fenmu); break;
			}
	case '/': a5 = division(a1, a2); //除法
		yuefen(a5.fenzi, a5.fenmu);

		if (a5.fenzi < a5.fenmu)
		{
			fprintf(fp, "%d.四则运算题目%d/%d÷%d/%d=%d/%d\n", number, a1.fenzi, a1.fenmu, a2.fenzi, a2.fenmu, a5.fenzi, a5.fenmu);
			fprintf(bp, "%d.答案=%d/%d\n", number, a5.fenzi, a5.fenmu); break;
		}
		else
			if (a5.fenmu == 1)
			{
				fprintf(fp, "%d.四则运算题目%d/%d÷%d/%d=%d\n", number, a1.fenzi, a1.fenmu, a2.fenzi, a2.fenmu, a5.fenzi);
				fprintf(bp, "%d.答案=%d\n", number, a5.fenzi); break;
			}
			else
			{
				fprintf(fp, "%d.四则运算题目%d/%d÷%d/%d=%d'%d/%d\n", number, a1.fenzi, a1.fenmu, a2.fenzi, a2.fenmu, a5.fenzi / a5.fenmu, a5.fenzi%a5.fenmu, a5.fenmu);
				fprintf(bp, "%d.答案=%d'%d/%d\n", number, a5.fenzi / a5.fenmu, a5.fenzi%a5.fenmu, a5.fenmu); break;
			}
	}
}

void daying2(char a, char b, fenshu a1, fenshu a2, fenshu a3, fenshu a5, int number, int max, FILE *fp, FILE *bp)
{

	if (a5.fenzi < a5.fenmu)
	{
		fprintf(fp, "%d .四则运算题目%d/%d%c%d/%d%c%d/%d=%d/%d\n", number, a1.fenzi, a1.fenmu, a, a2.fenzi, a2.fenmu, b, a3.fenzi, a3.fenmu, a5.fenzi, a5.fenmu);
		fprintf(bp, "%d .答案=%d/%d\n", number, a5.fenzi, a5.fenmu);
	}
	else
		if (a5.fenmu == 1)
		{
			fprintf(fp, "%d.四则运算题目%d/%d%c%d/%d%c%d/%d=%d\n", number, a1.fenzi, a1.fenmu, a, a2.fenzi, a2.fenmu, b, a3.fenzi, a3.fenmu, a5.fenzi);
			fprintf(bp, "%d.答案=%d\n", number, a5.fenzi);
		}
		else
		{
			fprintf(fp, "%d.四则运算题目%d/%d%c%d/%d%c%d/%d=%d'%d/%d\n", number, a1.fenzi, a1.fenmu, a, a2.fenzi, a2.fenmu, b, a3.fenzi, a3.fenmu, a5.fenzi / a5.fenmu, a5.fenzi%a5.fenmu, a5.fenmu);
			fprintf(bp, "%d.答案=%d'%d/%d\n", number, a5.fenzi / a5.fenmu, a5.fenzi%a5.fenmu, a5.fenmu);
		}
}

void daying3(char a, char b, char c, fenshu a1, fenshu a2, fenshu a3, fenshu a4, fenshu a5, int number, int max, FILE *fp, FILE *bp)
{

	if (a5.fenzi < a5.fenmu)
	{
		fprintf(fp, "%d .四则运算题目%d/%d%c%d/%d%c%d/%d%c%d/%d=%d/%d\n", number, a1.fenzi, a1.fenmu, a, a2.fenzi, a2.fenmu, b, a3.fenzi, a3.fenmu, c, a4.fenzi, a4.fenmu, a5.fenzi, a5.fenmu);
		fprintf(bp, "%d .答案=%d/%d\n", number, a5.fenzi, a5.fenmu);
	}
	else
		if (a5.fenmu == 1)
		{
			fprintf(fp, "%d.四则运算题目%d/%d%c%d/%d%c%d/%d%c%d/%d=%d\n", number, a1.fenzi, a1.fenmu, a, a2.fenzi, a2.fenmu, b, a3.fenzi, a3.fenmu, c, a4.fenzi, a4.fenmu, a5.fenzi);
			fprintf(bp, "%d.答案=%d\n", number, a5.fenzi);
		}
		else
		{
			fprintf(fp, "%d.四则运算题目%d/%d%c%d/%d%c%d/%d%c%d%d=%d'%d/%d\n", number, a1.fenzi, a1.fenmu, a, a2.fenzi, a2.fenmu, b, a3.fenzi, a3.fenmu, c, a4.fenzi, a4.fenmu, a5.fenzi / a5.fenmu, a5.fenzi%a5.fenmu, a5.fenmu);
			fprintf(bp, "%d.答案=%d'%d/%d\n", number, a5.fenzi / a5.fenmu, a5.fenzi%a5.fenmu, a5.fenmu);
		}
}

fenshu action2(char a, char b, fenshu a1, fenshu a2, fenshu a3, fenshu a5, fenshu a6)
{
	if (a== '*' || a == '/')
	{
		if (a == '*')
		{
			a6 = multiplication(a1, a2);
			yuefen(a6.fenzi, a6.fenmu);

		}
		else
		{
			a6 = division(a1, a2);
			yuefen(a6.fenzi, a6.fenmu);
		}
		if (b == '*')
		{
			a5 = multiplication(a6, a3);
			yuefen(a5.fenzi, a5.fenmu);

		}
		else if (b == '/')
		{
			a5 = division(a6, a3);
			yuefen(a5.fenzi, a5.fenmu);

		}
		else if (b == '+')
		{
			a5 = Add(a6, a3);
			yuefen(a5.fenzi, a5.fenmu);

		}
		else
		{
			a5 = minus(a6, a3);
			yuefen(a5.fenzi, a5.fenmu);


		}

	}
	else
	{
		if (b== '*')
		{
			a6 = multiplication(a2, a3);
			yuefen(a6.fenzi, a6.fenmu);
			if (a == '+')
			{
				a5 = Add(a1, a6);
				yuefen(a5.fenzi, a5.fenmu);

			}
			else
			{
				a5 = minus(a1, a6);
				yuefen(a5.fenzi, a5.fenmu);

			}
		}
		else if (b== '/')
		{
			a6 = division(a2, a3);
			yuefen(a6.fenzi, a6.fenmu);
			if (a == '+')
			{
				a5 = Add(a1, a6);
				yuefen(a5.fenzi, a5.fenmu);

			}
			else
			{
				a5 = minus(a1, a6);
				yuefen(a5.fenzi, a5.fenmu);

			}
		}
		else if (b == '+'||b=='-')
		{
			if (a == '+')
			{
				a6 = Add(a1, a2);
				yuefen(a6.fenzi, a6.fenmu);
				if (b == '+')
				{
					a5 = Add(a6, a3);
					yuefen(a5.fenzi, a5.fenmu);

				}
				else
				{
					a5 = minus(a6, a3);
					yuefen(a5.fenzi, a5.fenmu);

				}
			}
			else
			{
				a6 = minus(a1, a2);
				yuefen(a6.fenzi, a6.fenmu);
				if (a == '+')
				{
					a5 = Add(a6, a3);
					yuefen(a5.fenzi, a5.fenmu);

				}
				else
				{
					a5 = minus(a6, a3);
					yuefen(a5.fenzi, a5.fenmu);

				}
			}
		}
		
	}
	return a5;
}

fenshu actioan3(char a, char b, char c, fenshu a1, fenshu a2, fenshu a3, fenshu a4, fenshu a5)
{
	fenshu a6, a7;
	if (a== '/' || a == '*') {
		if (a == '*')
		{
			a6 = multiplication(a1, a2);
			yuefen(a6.fenzi, a6.fenmu);
		}
		else
		{
			a6 = division(a1, a2);
			yuefen(a6.fenzi, a6.fenmu);
		}
			
		a5 = action2(b, c, a6, a3, a4, a5, a7);
	}
	else if (b == '/' || b == '*')
	{
		if (b == '*')
		{ 
			a6 = multiplication(a2, a3);
			yuefen(a6.fenzi, a6.fenmu);
		}
			
		else
		{
			a6 = division(a2, a3);
			yuefen(a6.fenzi, a6.fenmu);
		}
		a5 = action2(a, c, a1, a6, a4, a5, a7);
			
	}
	else if (c == '/' || c == '*')
	{
		if (c == '*')
		{
			a6 = multiplication(a3, a4);
			yuefen(a6.fenzi, a6.fenmu);
		}

		else
		{
			a6 = division(a3, a4);
			yuefen(a6.fenzi, a6.fenmu);
		}
		a5 = action2(a, b, a1, a2, a6, a5, a7);
	}
	else
	{
		if (a == '+')
		{
			a6 = Add( a1, a2);
			yuefen(a6.fenzi, a6.fenmu);
		}
		else 
		{
			a6 = minus(a1, a2);
			yuefen(a6.fenzi, a6.fenmu);
		}
		a5 = action2(a, b, a6, a3, a4, a5, a7);
	}
	return a5;
}



int main()
{
	int tishu, max;
	printf("功能注释：输入-n x为生成x道题目，输入-r x将生成x以内（不包括x）的四则运算题目\n");
	printf("请先输入-n x\n");
	scanf("-n %d", &tishu);
	getchar();
	printf("请再输入-r x\n");
	scanf("-r %d", &max);
	getchar();
	FILE *fp;
	if ((fp = fopen("Exercises.txt", "w")) == NULL)//打开Exercises.txt文件，没有该文件则创建一个新的
	{
		printf("Cannot open this file!\n");
		exit(0);
	}
	FILE *bp;
	if ((bp = fopen("Answers.txt", "w")) == NULL)//打开Answers.txt文件，没有该文件则创建一个新的
	{
		printf("Cannot open this file!\n");
		exit(0);
	}
	int i = 0, number = 1;
	while (i < tishu)
	{
		fenshu a1, a2, a3, a4, a5, a6;


		a1.fenzi = rand() % max + 1;
		a2.fenzi = rand() % max + 1;
		a3.fenzi = rand() % max + 1;
		a4.fenzi = rand() % max + 1;
		a1.fenmu = rand() % max + 1;
		a2.fenmu = rand() % max + 1;
		a3.fenmu = rand() % max + 1;
		a4.fenmu = rand() % max + 1;
		yuefen(a1.fenzi, a1.fenmu);
		yuefen(a2.fenzi, a2.fenmu);
		yuefen(a3.fenzi, a3.fenmu);
		yuefen(a4.fenzi, a4.fenmu);


		int x, b, j, b1;       //随机生成任意数量的加减乘除
		char str[4];

		b = rand() % 3 + 1;
		b1 = b;
		for (j = 0; b; j++, b--)
		{
			x = rand() % 4;
			if (x == 0)
				str[j] = '+';
			else if (x == 1)
				str[j] = '-';
			else if (x == 2)
				str[j] = '*';
			else
				str[j] = '/';
		}

		if (b1 == 1)
		{
			daying(str[0], a1, a2, a5, number, max, fp, bp);
		}
		else if (b1 == 2)
		{
			a5 = action2(str[0], str[1], a1, a2, a3, a5, a6);
			if (a5.fenzi < 0)
				continue;
			daying2(str[0], str[1], a1, a2, a3, a5, number, max, fp, bp);
		}
		else

		{
			a5 = actioan3(str[0], str[1], str[2], a1, a2, a3, a4, a5);
			if (a5.fenzi < 0)
				continue;
			daying3(str[0], str[1], str[2], a1, a2, a3, a4, a5, number, max, fp, bp);
		}

		i++;
		number++;
	}
	fclose(fp);
	fclose(bp);
	return 0;

}