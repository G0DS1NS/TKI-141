
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
* @brief функция input принимает вводимые значение
* @param number вводимое значение
* @return возвращает вводимое значение
*/
double input(void);

/*
* @brief функция get_t считает значение изменения температуры
* @param Q отдаваемая энергия
* @param m масса ложки
* @return возвращает значение изменения температуры
*/
double get_t(const double Q, const double m);

/*
* @brief is_number проверяет меньше число нуля или нет
* @param number число
* @return возвращает true, если больше 0 и fasle, если меньше или равен 0
*/
bool is_number(const double number);

/*
* @brief функция main выводит значение t, исходя из значений Q и m
* @param Q отдаваемая энергия
* @param m масса ложки
* @return возвращает 0 в случае успеха
*/
int main(void) {

  puts("Введите значение Q:");

  double Q = input();

  puts("Введите значение m:");

  double m = input();
    if(!is_number(m) || !is_number(Q)){

      puts("Parameter is not posotive");

      return 1;
    }

  printf("t = %f\n", get_t(Q, m));

  return 0;
}

double input(void) {

  double number = 0;

  if (scanf_s("%lf", &number) != 1) {

    puts("Your input is uncorrected");

    exit(EXIT_FAILURE);
  }

  return number;

}

double get_t(const double Q, const double m) {

  const double c = 462;

  return Q / (c * m);
}

bool isNumber(const double number){
  return number > 0;
}
