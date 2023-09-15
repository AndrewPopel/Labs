#include <stdio.h>
#include <conio.h>
#include <locale>
#include "Header.h"


void main()
{
	setlocale(LC_ALL, "rus");
	//Ввод данных
	int n, p;
	

	//Запуск 1
	puts("-----------Запуск 1-----------");

	printf("Укажите кол-во городов:  "); scanf_s("%d", &n);
	
	//Спросить у пользователя вручную/случайно ввести матрицу
	for (int i = 0; (i != 0) || (i != 1);) {
		printf("Ввести матрицу вручную?\n Если да, введите 1 (иначе 0): "); scanf_s("%d", &i);
		if (i == 1) {
			InputMatr(int a[][100], int m, int n);					//вручную
		}
		if (i == 0) { RandMatr(int a[][100], int m, int n, int min, int max); }		//рандом
		else puts("Введены неправильные значения!\n");  
	}

	


	//Запуск 2
	//Запуск 3
	//Запуск 4

	//Общий вывод (сравнение и анализ)





}