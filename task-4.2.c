#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

/**
* @brief input считывает значение, введенное пользователем
* @return возвращает значение, введённо пользователем
*/
int input(void);

/**
* @brief is_positive проверяет больше ли число 0 или нет
* @param number число
* @return возвращает true, если число больше 0 и false, если число меньше 0
*/
bool is_positive(const int number);

/**
* @brief positive_input считывает значение введённое пользователем и проверяет его на положительность
* @return возвращает число, введённое пользователем
*/
size_t positive_input(void);

/**
* @brief initialize_manually заполняет массив числами, введёнными пользователем
* @param list массив
* @param n длина массива
*/
void initialize_manually(int* list, const size_t n);

/**
* @brief initialize_random заполняет массив случайными числами
* @param list массив
* @param n длина массива
* @param min минимальный элемент массива
* @param max максимальный элемент массива
*/
void initialize_random(int* list, const size_t n, const int min, const int max);

/**
* @brief positive_input_with_zero считывает значение типа int введённое пользователем
* @return возвращает значение введённое пользователем
*/
int positive_input_with_zero(void);

/**
* @brief check_list проверяет выделилась ли память для массива
* @param list массив
*/
void check_list_null(const int* list);

/**
* @brief create_list создаёт массив
* @param n длина массива
* @return возвращает указатель на первый элемент массива
*/
int* create_list(const size_t n);

/**
* @brief list_divis_seven удаляет из массива все элементы, которые деляется на 7
* @param list массив
* @param n длина массива
* @return возвращает указатель на первый элемент массива, из которого удалены все элементы массива, делящиеся на 7
*/
int* list_divis_seven(const int* list, const size_t n, const size_t a, const size_t b);

/**
* @brief create_list_a создаёт новый массив
* @param list массив
* @param n длина массива
* @return возвращает указатель на первый элемент нового массива
*/
int* create_list_a(const int* list, const size_t n);

/**
* @brief is_zero проверяет является ли число 0
* @param number число
* @return возвращает true, если число является 0 и false, если не является
*/
bool is_zero(const int number);

/**
* @brief len_divis_seven считает длину массива без чисел, кратных 7
* @param list массив
* @param n длина массива
* @return возвращает длину нового массива
*/
size_t len_divis_seven(const int* list, const size_t n, const size_t a, const size_t b);

/**
* @brief find_unpositive_element ищет первый отрицательный элемент
* @param list массив
* @param n длина массива
* @return возвращает индекс первого отрицательного элемента
*/
size_t find_unpositive_element(const int* list, const size_t n);

/**
* @brief find_positive_element ищет первый положительный элемент в массиве
* @param list массив
* @param n длина массива
* @return возвращает индекс первого положительного элемента
*/
size_t find_positive_element(const int* list, const size_t n);

/**
* @brief replace меняет значение элемента
* @param list массив
* @param n длина массива
*/
void replace(const int* list, const size_t n);

/**
* @brief choose выбор способа заполнения списка
* @param manually ручной способ заполнения списка
* @param random заполнение спика случайными числами
*/
typedef enum
{
	manually = 1,
	random
}choose;

/**
* @brief main точка входа в программу
* @return возвращает 0 в случае успеха
*/
int main(void)
{
	puts("Enter the len of list:");
	const size_t n = positive_input;
	const size_t a = positive_input_with_zero;
	const size_t b = positive_input_with_zero;
	const choose choose_initialize = (choose)input();
	int* list = create_list(n);
	switch (choose_initialize){
	case manually:
	{
		initialize_manually(list, n);
		break;
	}
	case random:
	{
		int min = input();
		int max = input();
		if (min > max)
		{
			free(list);
			return 1;
		}
		initialize_random(list, n, min, max);
		break;
	}
	default:
	{
		puts("Error");
		free(list);
		return 1;
	}
	}

	replace(list, n);
	int* list_d = list_divis_seven(list, n, a, b);

	int* list_a = create_list_a(list, n);

	printf("list = { ");
	for (size_t i = 0; i < n; i++)
	{
		printf("%d", list_d[i]);
	}
	
	printf(" }\n");
	printf("list_a = { ");
	for (size_t i = 0; i < n; i++)
	{
		printf("%d", list_a[i]);
	}
	printf(" }\n");

	free(list);
	free(list_d);
	free(list_a);
	return 0;
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

bool is_positive(const int number)
{
	return number > 0;
}

size_t positive_input(void)
{
	int number = input();

	if (!is_positive(number))
	{
		puts("Error");
		exit(EXIT_FAILURE);
	}

	return (size_t)number;
}

void initialize_manually(int* list, const size_t n)
{
	for (size_t i = 0; i < n; i++)
	{
		list[i] = input();
	}
}

void initialize_random(int* list, const size_t n, const int min, const int max)
{
	srand((unsigned int)time((time_t*)NULL));

	for (size_t i = 0; i < n; i++)
	{
		list[i] = rand() % (max - min + 1) + min;
	}
}

bool is_zero(const int number)
{
	return number == 0;
}

int positive_input_with_zero(void)
{
	int number = input();

	if (!(is_zero(number) || is_positive(number)))
	{
		puts("Error");
		exit(EXIT_FAILURE);
	}

	return number;
}

void check_list_null(const int* list)
{
	if (list == NULL)
	{
		puts("Error");
		exit(EXIT_FAILURE);
	}
}

int* create_list(const size_t n)
{
	int* list = (int*)malloc(sizeof(int) * n);
	check_list_null(list);
	return list;
}

int* list_divis_seven(const int* list, const size_t n, const size_t a, const size_t b)
{
	int* new_list = create_list(len_divis_seven(list, n, a, b));
	size_t j = 0;
	for (size_t i = 0; i < n; i++)
	{
		if (!(list[i] % 7 == 0 && i > a && i < b))
		{
			new_list[j] = list[i];
			j++;
		}
	}

	return new_list;
}

size_t len_divis_seven(const int* list, const size_t n, const size_t a, const size_t b)
{
	size_t len = 0;

	for (size_t i = a; i <+ b; i++)
	{
		if (list[i] % 7 == 0)
		{
			len++;
		}
	}

	return n - len;
}

int* create_list_a(const int* list, const size_t n)
{
	int* list_a = create_list(n);

	for (size_t i = 0; i < n; i++)
	{
		if (list[i] % 2 == 0)
		{
			list_a[i] = (int)pow(list[i], 2) + (int)i;
		}
		else {
			list_a[i] = (int)i * list[i];
		}
	}

	return list_a;
}

size_t find_positive_element(const int* list, const size_t n)
{
	for (size_t i = 0; i < n; i++)
	{
		if (is_positive(list[i]))
		{
			return i;
		}
	}
	return NULL;
}

size_t find_unpositive_element(const int* list, const size_t n)
{
	for (size_t i = 0; i < n; i++)
	{
		if (!is_positive(list[i]) && !is_zero(list[i]))
		{
			return i;
		}
	}

	return NULL;
}

void replace(int* list, const size_t n)
{
	if (find_positive_element(list, n) == NULL || find_unpositive_element(list, n) == NULL)
	{
		exit(EXIT_FAILURE);
	}
	list[find_positive_element(list, n)] = list[find_unpositive_element(list, n)];
}
