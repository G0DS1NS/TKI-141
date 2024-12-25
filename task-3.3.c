#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>
#include <stdbool.h>


/**
* @brief id_positive проверяет, является ли h положительным числом
* @param h параметр h
* @return возвращает true, если h больше 0 и false в противном случае
*/
bool is_positive(const double h);

/**
* @brief get_next_element считает значение следующего элемента функционального ряда
* @param n параметр n
* @param x параметр x
* @return возвращает значение следующего элемента функционального ряда
*/
double get_next_element(const int n, const double x, const double last_element);

/**
* @brief finput принимает на вход значение типа double, ведённое пользователем
* @return возвращает значение типа double, ведённое пользователем
*/
double finput(void);

int main(void)
{

	puts("Enter the start of arrea:");

	double x1 = finput();

	puts("Enter the end of arrea");

	double x2 = finput();

	puts("Enter the step:");

	double h = finput();

	if (!is_positive(h))
	{
		puts("h is not positive");

		return 1;
	}

	double last_element = 1;

	double start = x1;

	double summ = 1;

	printf("x\t\tcos(x)\t\tS\n");

	int n = 1;

	for (start; start <= x2 + DBL_EPSILON; start += h)
	{
		summ += get_next_element(n, start, last_element);
		printf("%lf\t%lf\t%lf\n", start, cos(start), summ);

		last_element = get_next_element(n, start, last_element);

		n += 1;
	}

	return 0;
}

double get_next_element(const int n, const double x, const double last_element) {

	return last_element * -pow(x, 2) / (2 * n * (2 * n - 1));
}

double finput(void)
{
	double number = 0;

	if (scanf_s("%lf", &number) != 1)
	{
		puts("Yout input is uncorrected");

		exit(EXIT_FAILURE);
	}

	return number;
}

bool is_positive(const double h)
{
	return h > DBL_EPSILON;
}
