#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <stdbool.h>
#include <time.h>


/**
* @brief choose перечисляет констаты для того, чтобы пользователь выбрал, как заполнять список
* @param manually вручную
* @param random случайные числа
*/
typedef enum {

	manually = 1, 
	random
}choose;

/**
* @brief is_positive проверяет, является ли число положительным
* @param n проверяемое число
* @return true, если число положительное и false, если отрицательное
*/
bool is_positive(const int n);

/**
* @brief summ_of_number считает сумму четных элементов массива
* @param list_of_number массив чисел
* @param n размер передаваемого массива
* @return сумму целый чисел массива
*/
int summ_of_even(const int* list_of_number, const size_t n);


/**
* @brief summ_of_two_char считает количество элементов массива, состоящих из двух цифр
* @param list_of_number массив целых чисел
* @param n размер передаваемого массива
* @return количество чисел, состоящих из двух цифр
*/
int count_of_two_char(const int* list_of_number, const size_t n);


/**
* @brief replace_list заменяет последний отрицательный элемент массива на модуль первого элемента массива
* @param list_of_number массив целых чисел
* @param n размер передаваемого массива
*/
void replace_list(int* list_of_number, const size_t n);

/**
* @brief initialize_manually заполняет массив целыми числами, которые ввёл пользователь
* @param list_of_number массив 
* @param n длина списка
*/
void initialize_manually(int* list_of_number,const int n);


/**
* @brief initialize_rand заполняет массив случайными целыми числами
* @param list_of_number массив целых чисел
* @param n длина списка
* @param max максимальное число списка
* @param min минимальное число списка
*/
void initialize_rand(int* list_of_number,const size_t n, const int max, const int min);

/**
* @brief input считывает значение, вводимое пользователем
* @return возвращает значение, вводимое пользователем
*/
int input(void);

/**
* @brief positive_input считывает число, введённое пользователем и проверяет положительно ли оно
* @return возвращает число, введённое пользователем
*/
size_t positive_input(void);

/**
* @brief create_list создаёт массив
* @param n длина массива
* @return возвращает указатель на первый элемент массива
*/
int* create_list(const int n);

/**
* @brief check_list_not_null проверяет, выделилась ли память для массива
* @param list_numbers массив
* @return возвращает true, если память для массива не выделилась и false, если выделилась
*/
bool check_list_null(const int* list_numbers);

/**
* @brief find_unpositive_element ищет первый отрицательный элемент в массиве
* @param list_of_numbers массив целых чисел
* @param n размер передаваемого массива
* @return возвращает индекс первого отрицательного элемента, если его нет, возвращает NULL
*/
size_t find_unpositive_element(const int* list_of_numbers, const size_t n);

/**
* @brief main выводит результат всех действий пользователю на экран
* @return возвращает 0 в случае успеха
*/
int main(void) 
{

	puts("Enter the n:");

	const size_t n = positive_input();

	int* list_of_number = create_list(n);
	
	choose choose_initialize = (choose)input();

	switch (choose_initialize) {

	case manually:
		initialize_manually(list_of_number, n);
		break;
	case random:
		puts("Enter the max element of list");
		const int max = input();
		puts("Enter the min element of list");
		const int min = input();
		if (min > max)
		{
			puts("Error");
			return 1;
		}
		initialize_rand(list_of_number, max, min);
		break;
	default:
		puts("Error");
		free(list_of_number);
		return 1;
	}

	replace_list(list_of_number, n);

	printf("summ of even numbers = %d\nThe count of numbers consisting of two digits = %d\n", summ_of_even(list_of_number, n), count_of_two_char(list_of_number, n));

	free(list_of_number);

	return 0;
}

int summ_of_even(const int* list_of_number, const size_t n)
{
	check_list_null(list_of_number);

	int summ = 0;

	for (size_t i = 0; i < n; i++)
	{
		if (list_of_number[i] % 2 == 0)
		{
			summ += list_of_number[i];
		}
	}

	return summ;
}

int count_of_two_char(const int* list_of_number, const size_t n)
{

	check_list_null(list_of_number);

	int count = 0;

	for (size_t i = 0; i < n; i++) {

		int element = list_of_number[i];

		if (fabs(element) > 9 && fabs(element) < 100) {

			count += 1;
		}
	}

	return count;
}

void replace_list(int* list_of_numbers, const size_t n)
{
	check_list_null(list_of_numbers);

	size_t index_unpositive_element = find_unpositive_element(list_of_numbers, n);

	if(index_unpositive_element == NULL){
		puts("Error");
		exit(EXIT_FAILURE);
	}

	int replace_element = 0;

	replace_element = list_of_numbers[0];

	list_of_numbers[0] = list_of_numbers[index_unpositive_element];

	list_of_numbers[index_unpositive_element] = replace_element;

}

void initialize_manually(int* list_of_number,const int n)
{

	for (size_t i = 0; i < n; i++)

	{
		puts("\nEnter the your number:");
		list_of_number[i] = input();
	}

}

void initialize_rand(int* list_of_number, const size_t n, const int max, const int min)
{

	srand(time(NULL));
	for (size_t i = 0; i < n - 1; ++i)
	{
		list_of_number[i] = rand() % (max - min + 1) + min;
	}
}


int input(void)
{
	int number = 0;

	if (scanf_s("%d", &number) != 1)
	{

		puts("Your input is uncorrected");

		exit(EXIT_FAILURE);
	}

	return number;
}

bool is_positive(const int n) {

	return n > 0;
}

size_t positive_input(void)
{
	int number = 0;

	if (scanf_s("%zu", &number) != 1 || !is_positive(number))
	{
		puts("Your input is uncorrected");

		exit(EXIT_FAILURE);
	}

	return (size_t)number;
}

int* create_list(const int n)
{
	int* list_of_number = (int*)malloc(sizeof(int) * n);

	check_list_null(list_of_number);

	return list_of_number;
}

void check_list_null(const int* list_numbers)
{
	if (list_numbers == NULL)
	{
		puts("Error");

		exit(EXIT_FAILURE);
	}
}

size_t find_unpositive_element(const int* list_of_numbers, const size_t n)
{
	for (size_t i = 0; i < n; i++)
	{
		if (list_of_numbers[i] < 0)
		{
			return i;
		}
	}

	return NULL;
}
