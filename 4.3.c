#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

/**
* @brief input принимает на вход числа типа int, вводимые пользователем
* @return возвращает число, которое ввёл пользователь
*/
int input(void);

/**
* @brief initialize_list создаёт многомерный массив
* @param n параметр n
* @param m параметр m
* @return возвращает указатель на многомерный массив
*/
int** initialize_list(const size_t n, const size_t m);

/**
* @brief initialize создаёт одномерный массив
* @param n параметр n
* @return возвращает указатель не одномерный массив
*/
int* initialize(const size_t n);

/**
* @brief manually_list заполняет двухмерный массив числами, вводимыми пользователем
* @param list указатель на двухмерный массив
* @param n параметр n
* @param m параметр m
*/
void manually_list(int** list, const size_t n, const size_t m);

/**
* @brief manually_init заполняет одномерный массив числами, который ввёл пользователь
* @param list одномерный массив
* @param n
*/
void manually_init(int* list, const size_t n);

/**
* @brief random_init заполняет одномерный массив случайными числами
* @param list одномерный массив
* @param n параметр n
* @param min минимальное значение в диапазоне случайных чисел
* @param max максимальное значение в диапазоне случайных чисел
*/
void random_init(int* list, const size_t n, const int min, const int max);

/**
* @brief random_list заполняет двухмерный массив случайными числами
* @param list двухмерный массив
* @param n параметр n
* @param m параметр m
* @param min минимальное значение диапазона случайных чисел
* @param max максимальное значение диапазона случайных чисел
*/
void random_list(int** list, const size_t n, const size_t m, const int min, const int max);

/**
* @brief is_positive проверяет число на положительных
* @param number число
* @return вовзращает true, если число положительное и false, если отрицательное
*/
bool is_positive(const int number);

/**
* @brief input принимает на вход числа типа int, вводимые пользователем
* @return возвращает число, которое ввёл пользователь
*/
int positive_input(void);

/**
* @brief check_list проверяет, выделилась ли память для массива
* @param list двухмерный массив
*/
void check_list(int** list);

/**
* @brief check_list проверяет, выделилась ли память для массива
* @param list одномерный массив
*/
void check(int* list);

/**
* @brief replace_min_element заменяет минимальный элемент в столбце на протовоположный
* @param list двухмерный массив
* @param n параметр n
* @param m параметр m
*/
void replace_min_element(int** list, const size_t n, const size_t m);

/**
* @brief min_element находит индекс минимального элемента в столбце
* @param list двухмерный массив
* @param m параметр m
* @param i параметр i
* @return возвращает индекс минимального элемнта в столбце
*/
size_t min_element(int** list, const size_t m, const size_t i);

/**
* @brief index_min_element находит максимальный элемент в столбце
* @param list двухмерный массив
* @param n параметр n
* @param ind параметр ind
*/
size_t index_max_element(int** list, const size_t n, const size_t ind);

/**
* @brief free_all освобождает память для всех элементов массива
* @param list двухмерный массив
* @param m параметр m
*/
void free_all(int** list, const size_t m);

/**
* @brief remove_list удаляет строчки в массива с максимальными элементами
* @param list двухмерный массив
* @param n параметр n
* @param m параметр m
* @param ind параметр ind
*/
void remove_list(int** list, const size_t n, const size_t m, const size_t ind);

/**
* @brief move_list сдвигает строчки массива наверх
* @param list двухмерный массив
* @param n параметр n
* @param m параметр m
* @param ind параметр ind
*/
void move_list(int** list, const size_t n, const size_t m, const size_t ind);

/**
* @brief new_list задаёт массиву новое значение с удалёнными строчками
* @param list двухмерный массив
* @param m параметр m
* @param count количество удаленных строчек
*/
int** new_list(int** list, const size_t m, const int count);

/**
* @brief choose перечисляет константы для выбора способа заполнения массива
* @param manually ручное заполнение массива
* @param random заполнение массива случайными числами
*/
typedef enum {
	manually = 1,
	random
}choose;

/**
* @brief printArray выводит массив на экран
* @param list двухмерный массив
* @param n параметр n
* @param m параметр m
*/
void printArray(int** list, const size_t n, const size_t m);

/**
* @brief main точка входа в программу
* @return возвращает 0 в случае успеха
*/
int main(void)
{
	const size_t n = positive_input();
	const size_t m = positive_input();
	int** list = initialize_list(n, m);
	choose init = (choose)input();
	switch (init)
	{
	case manually:
	{
		manually_list(list, n, m);
		break;
	}
	case random:
	{
		const int min = input();
		const int max = input();
		if (min > max)
		{
			puts("Error");
			return 1;
		}
		random_list(list, n, m, min, max);
		break;
	}
	default:
		puts("Invalid input");
		return 1;
	}

	replace_min_element(list, n, m);
	int count = 0;
	for (size_t i = 0; i < n; i++)
	{
		remove_list(list, n, m, i);
		count++;
	}

	list = new_list(list, m, count);
	printArray(list, n, m);
	free_all(list, m);
	free(list);
	return 0;
}

int** new_list(int** list, const size_t m, const int count)
{
	int** new_list = (int**)malloc(sizeof(int*) * m);
	for (size_t i = 0; i < m - count; i++)
	{
		new_list[i] = list[i];
	}

	return new_list;
}

void move_list(int** list, const size_t n, const size_t m, const size_t ind)
{
	for (size_t i = ind + 1; i < m; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			list[i][j] = list[i + 1][j];
		}
	}
}

void replace_min_element(int** list, const size_t n, const size_t m)
{
	for (size_t j = 0; j < m; j++)
	{
		size_t min = min_element(list, j, n);
		list[min][j] = -list[min][j];
	}
}

size_t min_element(int** list, const size_t j, const size_t m)
{
	int min = list[0][j];
	size_t k = 0;
	for (size_t i = 0; i < m; i++)
	{
		if (list[i][j] < min)
		{
			min = list[i][j];
			k = i;
		}
	}

	return k;
}

void free_all(int** list, const size_t m)
{
	for (size_t i = 0; i < m; i++)
	{
		free(list[i]);
	}
}

void remove_list(int** list, const size_t n, const size_t m, const size_t ind)
{
	size_t i = index_max_element(list, n, ind);
	for (size_t j = 0; j < n; j++)
	{
		list[i][j] = list[i + 1][j];
	}

	move_list(list, n, m, index_max_element(list, n, ind));
}

size_t index_max_element(int** list, const size_t m, const size_t ind)
{
	size_t index_max_element = 0;
	for (size_t i = 0; i < m; i++)
	{
		if (list[i][ind] > list[index_max_element][ind])
		{
			index_max_element = i;
		}
	}

	return index_max_element;
}

int input(void)
{
	int number = 0;
	if (scanf_s("%d", &number) != 1)
	{
		puts("Error");
		exit(EXIT_FAILURE);
	}
	return number;
}

void check_list(int** list)
{
	if (list == NULL)
	{
		exit(1);
	}
}

void check(int* list)
{
	if (list == NULL)
	{
		exit(1);
	}
}

int** initialize_list(const size_t n, const size_t m)
{
	int** list = (int**)malloc(sizeof(int*) * m);
	check_list(list);
	for (size_t i = 0; i < m; i++)
	{
		list[i] = initialize(n);
	}

	return list;
}

int* initialize(const size_t n)
{
	int* list = (int*)malloc(sizeof(int) * n);
	check(list);
	return list;
}

void manually_init(int* list, const size_t n)
{
	for (size_t i = 0; i < n; i++)
	{
		list[i] = input();
	}
}

void manually_list(int** list, const size_t n, const size_t m)
{
	for (size_t i = 0; i < m; i++)
	{
		manually_init(list[i], n);
	}
}


void random_init(int* list, const size_t n, const int min, const int max)
{
	srand((unsigned int)time((time_t*)NULL));
	for (size_t i = 0; i < n; i++)
	{
		list[i] = (rand() % max - min + 1) + min;
	}
}

void random_list(int** list, const size_t n, const size_t m, const int min, const int max)
{
	for (size_t i = 0; i < m; i++)
	{
		random_init(list[i], n, min, max);
	}
}

bool is_positive(const int number)
{
	return number > 0;
}

int positive_input(void)
{
	int number = input();
	if (!is_positive(number))
	{
		puts("Your input is uncorrected");
		exit(1);
	}

	return number;
}

void printArray(int** list, const size_t n, const size_t m)
{
	for (size_t i = 0; i < m; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			printf("list[%zu][%zu]= %d\n", i, j, list[i][j]);
		}
	}
}
