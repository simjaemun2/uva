#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define MIN_H 64
#define MAX_H 128
#define MAX_R MAX_H * 2

char h1[MAX_H + 1];
char h2[MAX_H + 1];
char result[MAX_R + 1];

extern void mul(char* result, char* h1, char* h2);

char get_char()
{
	int d = rand() % 36;
	if (d < 10)
		return '0' + d;
	return d + 55;
}

char get_char_first()
{
	int d = rand() % 35;
	if (d < 9)
		return '1' + d;
	return d + 56;
}

int make_number(char* s)
{
	s[0] = get_char_first();

	int range = rand() % (MAX_H - MIN_H + 1) + MIN_H;

	for (int i = 1; i <= range; i++)
	{
		s[i] = get_char();
	}

	return strlen(s);
}


int main()
{
	srand(3);
	
	for (register int i = 1; i <= 50; i++)
	{
		int sum = 0;
		for (register int c = 0; c < 10000; c++)
		{
			int a = make_number(h1);
			int b = make_number(h2);

			mul(result, h1, h2);

			sum += result[rand() % (a + b - 1)];
		}

		int len = strlen(result);

		for (int i = 0; i < len; i++)
			sum += result[i];
		sum += len;

		printf("#%d %d\n", i, sum);
	}
	

	mul(result, "10", "10");
}

#define MIN_H 64
#define MAX_H 128
#define MAX_R MAX_H * 2
#define C36 36
#define MAX_H_36 MAX_H * 36
#define MAX_R_36 MAX_R * 36

typedef unsigned short BASE36;

BASE36 iarr1[MAX_H_36 + 10], iarr2[MAX_H_36 + 10], iarrR[MAX_R_36 + 10];
int len1, len2, lenR;

char itoc_table[C36 + 1] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int ctoi(char c)
{
	if (c < '9' + 1)
		return c - '0';
	return c - 'A';
}

void to10(BASE36 iarr[], char* h, int& len)
{
	len = 0;

	while (h[len])
	{
		iarr[len] = ctoi(h[len]);
		++len;
	}
}

void mulcal()
{
	for (int i = 0; i < len1 + len2 + 2; i++)
		iarrR[i] = 0;

	for (int i1 = len1 - 1; i1 >= 0; i1--)
	{
		if (iarr1[i1] == 0)
			continue;

		for (int i2 = len2 - 1; i2 >= 0; i2--)
		{
			iarrR[len1 + len2 - (i1 + i2 + 2)] = iarr1[i1] * iarr2[i2];
		}
	}

	for (int i = 0; i < len1 + len2; i++)
	{
		iarrR[i + 1] += iarrR[i] / C36;
		iarrR[i] %= C36;
	}
}

void tochar36(char* result)
{
	for (lenR = MAX_R_36; lenR >= 0; lenR--)
	{
		if (iarrR[lenR] != 0)
			break;
	}

	int i = 0;

	for (; lenR >= 0; lenR--, i++)
	{
		result[i] = itoc_table[iarrR[lenR]];
	}

	result[i] = 0;
}

void mul(char* result, char* h1, char* h2)
{
	to10(iarr1, h1, len1);
	to10(iarr2, h2, len2);

	mulcal();

	tochar36(result);
	/*
	printf("h1 : %s\n", h1);
	printf("h2 : %s\n", h2);
	printf("result : %s\n", result);
	*/
}