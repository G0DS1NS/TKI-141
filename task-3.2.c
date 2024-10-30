#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <stdbool.h>


/**
* @brief dinput считывает данные типа int, вводимые пользователем
* @return возвращает значение, введённое пользователем
*/
int dinput(void);


/**
* @brief finput считывает значения типа double, вводимые пользователем
* @return возвращает значение, введённое пользователем
*/
double finput(void);

/**
* @brief get_next_element считает следующий элемент последовательности
* @param last_element последний элемент последовательности
* @return возвращает следующий элемент последовательности
*/
double get_next_element(const double last_element, const int k);


/**
* @brief get_summ считает сумму для первых n элементов
* @param n параметр n
* @return возвращает сумму первых n элементов
*/
double get_summ(const int n);

/**
* @brief get_summ_e считает сумму элементов не меньше e
* @param n параметр n
* @param e параметр e
* @return возвращает сумму элементов не меньших e
*/
double get_summ_e(const int n, const double e);

/**
* @brief is_positive проверяет положителен ли n
* @param n параметр n
* @reеurn возвращает true, если n положителен и false, если равен или меньше 0
*/
bool is_positive(const int n);

/**
* @brief main выводит значения сумм
* @return возвращает 0 в случае успеха
*/
int main(void) {

	puts("Enter the n:");

	int n = dinput();

	if (!is_positive(n))
	{
		puts("n in not positive");

		exit(EXIT_FAILURE);
	}

	puts("Enter the e");

	double e = finput();

	printf("%lf\n %lf", get_summ(n), get_summ_e(n, e));

	return 0;
}

double get_summ(const int n)
{

	double summ = -1;

	double last_element = -1;

	for (int k = 2; k <= n; k++)
	{

		summ += get_next_element(last_element, k);

		last_element = get_next_element(last_element, k);
	}
	
	return summ;
}

double get_next_element(const double last_element, const int k)
{

	return last_element / -pow(k, 2);
}

double get_summ_e(const int n, const double e)
{

	double summ_e = 0;

	double last_element = -1;

	if (last_element >= e + DBL_EPSILON)
	{
		summ_e += last_element;
	}

	for (int k = 2; k <= n; k++) {

		last_element = get_next_element(last_element, k);

		if (last_element >= e + DBL_EPSILON)
		{

			summ_e += last_element;
		}
	}

	return summ_e;
}

int dinput(void)
{

	int number = 0;

	if (scanf_s("%d", &number) != 1)
	{

		puts("Your input is uncorrected");

		exit(EXIT_FAILURE);
	}

	return number;
}

double finput(void)
{

	double number = 0;

	if (scanf_s("%lf", &number) != 1)
	{

		puts("Your input is uncorrected");

		exit(EXIT_FAILURE);
	}

	return number;
}

bool is_positive(const int n)
{
	return n > 0;
}
