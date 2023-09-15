#pragma once
#pragma once
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define UI unsigned int

void hw(void) { //выводит "Hello World!"
	puts("Hello World!");
}

bool Simpl(int n) { //проверяет является ли число простым
	int d;
	if (n == 2)
		return true;
	for (d = 2; d <= n / 2; d++)
		if (n%d == 0)
			return false;
	return true;
}

void InputMas(int a[], int n) { // функция для ввода массива
	for (int i = 0; i < n; i++)
		scanf_s("%d", &a[i]);
}

void InputMasPtr(int *a, int n) { //ввод массива через указатель
	for (int* p = a; p < a + n; p++)
		scanf_s("%d", p);
}


void InputMatr(int matr[][100], int m, int n) { //ввод матрицы
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			scanf_s("%d", &matr[i][j]);
}

void InputMatrPtr(int **matr, int m, int n) { //ввод динамической матрицы
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			scanf_s("%d", &matr[i][j]); //Thread 1: EXC_BAD_ACCESS (code=1, address=0x200000001)
}

void OutputMas(int a[], int n) { // функция для вывода массива
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
}

void OutputMasPtr(int *a, int n) { //вывод массива через указатель
	for (int* p = a; p < a + n; p++)
		printf("%d ", *p);
}

void OutputMatr(int matr[][100], int m, int n) { //вывод динамической матрицы
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			printf("%d ", matr[i][j]);
		printf("\n");
	}
}


void OutputMatrPtr(int **matr, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			printf("%d ", matr[i][j]);
		printf("\n");
	}
}

void RandMas(int a[], int n, int min, int max) { //массив случайных чисел от min до max
	//если ошибка с Breakpoints cmd+8 -> удалить их
	srand(time(0));
	for (int i = 0; i < n; i++) //srand
		a[i] = rand() % (max - min + 1) + min;
}

void CopyMas(int *array, int *copy, int n) {
	for (int i = 0; i < n; i++)
	{
		copy[i] = array[i];
	}
}

void RandMatr(int a[][100], int m, int n, int min, int max) {//случайная матрица
	srand(time(0));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			//            a[i][j]=rand()%101;
			a[i][j] = rand() % (max - min + 1) + min;
}

void IncreasMas(int a[], int n) { // возрастающий массив
	srand(time(0));
	a[0] = rand() % 10;
	for (int i = 1; i < n; i++)
		a[i] = a[i - 1] + rand() % 5 + 1; //возрастающий массив
//        a[i]=a[i-1] + rand()%10; //неубывающий массив
}

void DecreasMas(int a[], int n) {// убывающий массив
	a[n - 1] = rand() % 10;
	for (int i = n - 2; i >= 0; i--)
		a[i] = a[i + 1] + rand() % 5 + 1;//убывающий массив
//        a[i]=a[i+1]+ rand()%5;//невозрастающий массив
}

int Max(int a[], int n) { //Номер максимального элемента в массиве
	int i_max, i; //выводит номер элемента
	for (i_max = 0, i = 1; i < n; i++)
		if (a[i] > a[i_max])
			i_max = i;
	return i_max;
}

int Min(int a[], int n) { //Номер минимального элемента в массиве
	int i_min, i; //выводит номер элемента
	for (i_min = 0, i = 1; i < n; i++)
		if (a[i] < a[i_min])
			i_min = i;
	return i_min;
}

int Find(int *array, int n, int X) { //Eсть ли число X в массиве, выводит индекс элемента
	for (int i = 0; i < n; i++)
		if (array[i] == X)
			return i;
	return -1;
}

int BinarySearch(int *array, int n, int X) { //Бинарный поиск числа X в массиве
	int Left = 0, Right = n - 1, middle;
	while (Left <= Right) {
		middle = (Left + Right) / 2;
		if (array[middle] > X)
			Right = middle - 1;
		else if (array[middle] < X)
			Left = middle + 1;
		else
			return middle;
	}
	return -1;

}


void StraightSearch(char *string, char *substring, int n, int m) { //прямой поиск подстроки в строке
	bool flag = false;
	int i, j = 0;
	for (i = 0; (flag != true) and (i <= n - m); i++) {
		/*for (j = 0; (j < m) and (string[i+j] == substring[j]); j++) */
		while (j < m) {
			printf("%c == %c\n", string[i + j], substring[j]);
			if (string[i + j] == substring[j])
				j++;
			else
				break;

		}


		if (j == m)
			flag = true;
	}

	if (flag == true)
		printf("Entry Index: %d\n", i - 1);
	else
		printf("Not found\n");
}


/*int BMSearch (char* str, const char* word) {//БМ поиск подстроки в строке
	int N = int (strlen (str));
	int M = int (strlen (word));

	int *d = new int[256];
	int i;
	for(i = 0; i < 256; i++)
		d[i] = M;

	for(i=0;i<M-1;i++)
		d[(unsigned char)word[i]]=M-i-1;

	int result;
	for(i = M; i <= N; i += d[(unsigned char)str[i-1]]) {
		int j, k;
		for(j = M - 1, k = i - 1;j>=0 && str[k]==word[j]; k--, j--);
		if(j<0)
		{
				result=i-M;
			break;
		}
		if(i==N)
		{
			result=-1;
			break;
		}
	}

	delete[] d;

	return result;
}
*/

void InsertionSort(int n, int *array) { //сортировка вставкой
	int newElement, location;

	for (int i = 1; i < n; i++)
	{
		newElement = array[i];
		location = i - 1;
		while (location >= 0 && array[location] > newElement)
		{
			array[location + 1] = array[location];
			location = location - 1;
		}
		array[location + 1] = newElement;
	}
}

void SwapPtr(int *a, int *b) { //Меняет переменные местами через адреса
	//пример вызова : Swap(&a, &b);
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void SwapInt(int a, int b) { //Меняет переменные местами
	a += b;
	b = a - b;
	a -= b;
}

void ShiftLeft(int a[], int n, int pos) { //Сдвиг массива влево
	for (int i = pos; i < n - 1; i++)
		a[i] = a[i + 1];
}

void ShiftRight(int a[], int n, int pos) { //Сдвиг массива вправо
	for (int i = pos; i < n - 1; i++)
		a[i] = a[i - 1];
}

void ShiftLeft_k(int a[], int n, int p, int k) { //Сдвиг массива влево на k позиций, начиная с p-й
	for (int i = p; i < n - k; i++)
		a[i] = a[i + k];
}

void ShiftRight_k(int a[], int n, int p, int k) { //Сдвиг массива вправо на k позиций, начиная с p-й
	for (int i = p; i < n - k; i++)
		a[i + k] = a[i];
}

void Vstavka(int a[], int n, int x) { //В неубывающем массиве находит место для x, такое, чтобы не нарушить последовательность
	int i;
	for (i = n - 1; x < a[i] && i >= 0; i--)
		a[i + 1] = a[i];
	a[i + 1] = x;
}

int DelStr(int **matr, int m, int n, int k) { //удаляет строку матрицы
	int i, j;
	for (i = k; i < m - 1; i++)
		for (j = 0; j < n; j++)
			matr[i][j] = matr[i + 1][j];
	return --m;
}

int DelStr1(int **matr, int m, int n, int k) {//Освободить память от k-й строки и переместить указатели
	int i;
	delete[] matr[k];
	for (i = k; i < m - 1; i++)
		matr[i] = matr[i + 1];
	return --m;
}

bool Sifra(char ch) { //является ли символ цифрой
	if (ch >= '0' && ch <= '9')
		return true;
	return false;
}

bool Bukva(char ch) { //является ли символ прописной (заглавной) буквой
	if (ch >= 'A' && ch <= 'Z')
		return true;
	return false;
}

bool bukva(char ch) { //является ли символ строчной (маленькой) буквой
	if (ch >= 'a' && ch <= 'z')
		return true;
	return false;
}

UI SetUp1(UI x, int k) {
	UI mask = 1; // 00000001
	mask <<= k;
	x |= mask;
	return x;
}

UI Input1BV(char s[], int n) { //ввод булева вектора
	UI x = 0, mask = 1;
	int i;
	for (i = 0; i < n; i++) {
		x <<= 1;
		if (s[i] == '1') x++;
	}
	return x;
}


UI Input2BV(char s[], int n) { //ввод булева вектора
	UI x = 0;
	int i;
	for (i = 0; i < n; i++)
		if (s[i] == '1')
			x = SetUp1(x, n - 1 - i);
	return x;
}

void InputBM(UI *bm, int m, int n) {//ввод булевой матрицы
	int i; char s[100];
	for (i = 0; i < m; i++) {
		fgets(s, 100, stdin);
		bm[i] = Input2BV(s, n);
	}
}

/*
void OutputBV(UI x, int n) {
	UI mask=1; int i;
	mask<<=n-1;
	for(i=0; i < n; i++, mask>>=1)
		if (x&mask)
			printf("1");
	else
		printf("0");
}
*/

void OutputBV(UI x, int n) { //вывод булева вектора
	UI mask = 1;
	mask <<= n - 1;
	for (int i = 1; i <= n; i++, mask >>= 1)
		printf("%d ", (x&mask) ? 1 : 0);
	printf("\n");
}

void OutputBM(UI *bm, int m, int n) { //вывод булевой матрицы
	int i;
	for (i = 0; i < m; i++) {
		OutputBV(bm[i], n);
		printf("");
	}
	printf("\n");
}

UI Invert(UI x, int k) { //инвертирует k элетмент булева вектора
	UI mask = 1;
	mask <<= k;
	x ^= mask;
	return x;
}

int Weight(UI x, int n) { //вес булева вектора
	int w;
	UI mask = 1;
	for (int i = w = 0; i < n; i++, mask <<= 1)
		if (x & mask)
			w++;
	return w;
}

int WeightСolumn(UI *bm, int m, int k) { //считает кол-во 1 в столбце
	int w, i;
	UI mask = 1 << k;
	for (w = 0, i = 0; i < m; i++)
		if (bm[i] & mask)
			w++;
	return w;
}
/*
void testfile(const char *name) { //правильность открытия файла
	FILE *f = fopen(name, "r");
	if (f == NULL) {
		perror("error opening file");
		getchar();
		exit(-1);
	}
}
*/
/*
void CreateFile(const char *name, int n, int min, int max) { //создает файл со случайными числами n от min до max
	int x;
	FILE *f = fopen(name, "w");
	if (f == NULL) {
		perror("error opening file in CreateFile");
		exit(-1);
	}
	srand(time(0));
	for (int i = 0; i < n; i++) {
		x = rand() % (max - min + 1) + min;
		fprintf(f, "%d ", x);
	}
	fclose(f);
}
*/
/*
void IncreasFile(const char *name, int n) { //создает файл с неубывающими положительными числами
	int x = 0;
	FILE *f = fopen(name, "w");
	if (f == NULL) {
		perror("error opening file in CreateFile");
		exit(-1);
	}
	srand(time(0));
	for (int i = 0; i < n; i++) {
		x = x + rand() % 5 + 1;
		fprintf(f, "%d ", x);
	}
	fclose(f);
}
*/
/*
void PrintFile(const char *name) { //выводит содержимое файла
	FILE *f; int x;
	f = fopen(name, "r");
	if (f == NULL) {
		perror("error opening file in PrintFile");
		exit(-1);
	}
	while (fscanf(f, "%d", &x) != EOF)//feof(f)
		printf("%d ", x);
	fclose(f);
}
*/
/*
void CopyFile(FILE *from, FILE *to) { //копирует содержимое из одного файла в другой
	int x;
	while (fscanf(from, "%d", &x) != EOF)
		fprintf(to, "%d ", x);
}
*/
/*
void Split(const char *name, const char *name1, const char *name2) { //естественная сортировока - разбиение
	FILE *f, *g1, *g2;
	int x, y;

	f = fopen(name, "r");
	g1 = fopen(name1, "w");
	g2 = fopen(name2, "w");
	if (f == NULL || g1 == NULL || g2 == NULL) {
		perror("error opening file in Split");
		exit(-1);
	}


	fscanf(f, "%d", &x);
	while (!feof(f)) {
		fprintf(g1, "%d ", x);
		fscanf(f, "%d", &y);
		while (!feof(f) && (x <= y)) {
			x = y;
			fprintf(g1, "%d ", x);
			fscanf(f, "%d", &y);
		}
		if (!feof(f)) {
			x = y;
			fprintf(g2, "%d ", x);
			fscanf(f, "%d", &y);
			while (!feof(f) && (x <= y)) {
				x = y;
				fprintf(g2, "%d  ", x);
				fscanf(f, "%d", &y);
			}
		}
		x = y;
	}

	fclose(f); fclose(g1); fclose(g2);
}
*/
/*
void Merger(const char *name, const char *name1, const char *name2) { //естественная сортировока - слияние
	FILE *f, *g1, *g2;
	int x, y, z, k;

	f = fopen(name, "w");
	g1 = fopen(name1, "r");
	g2 = fopen(name2, "r");
	if (f == NULL || g1 == NULL || g2 == NULL) {
		perror("error opening file in Merger");
		exit(-1);
	}

	fscanf(g1, "%d", &x); fscanf(g2, "%d", &y);
	while (!feof(g1) && !feof(g2)) {
		if (x < y) {
			fprintf(f, "%d ", x);
			fscanf(g1, "%d", &z);
			if (!feof(g1) && (x > z)) {
				fprintf(f, "%d ", y);
				fscanf(g2, "%d", &k);
				while (!feof(g2) && (y <= k)) {
					y = k;
					fprintf(f, "%d ", y);
					fscanf(g2, "%d", &k);
				}
				y = k;
			}
			x = z;

		}
		else {
			fprintf(f, "%d ", y);
			fscanf(g2, "%d", &k);
			if (!feof(g2) && y > k) {
				fprintf(f, "%d ", x);
				fscanf(g1, "%d", &z);
				while (!feof(g1) && (x <= z)) {
					x = z;
					fprintf(f, "%d ", x);
					fscanf(g1, "%d", &z);
				}
				x = z;
			}
			y = k;
		}
	}
	while (!feof(g1)) {
		fprintf(f, "%d ", x);
		fscanf(g1, "%d", &x);
	}
	while (!feof(g2)) {
		fprintf(f, "%d ", y);
		fscanf(g2, "%d", &y);
	}

	fclose(f); fclose(g1); fclose(g2);
}
*/
void SortBubble(int *a, int n) { //сортировка массива пузырьком
	int c;
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (a[j] > a[j + 1]) {
				c = a[j];
				a[j] = a[j + 1];
				a[j + 1] = c;
			}
}

void SortSheker(int *array, int n) { //сортировка массива шейкером(улучшеная сортировка пузырьком)
	int left = 0, right = n - 1, flag = 1, t;
	while ((left < right) && flag > 0) {
		flag = 0;
		for (int i = left; i < right; i++) {
			if (array[i] > array[i + 1]) {
				t = array[i];
				array[i] = array[i + 1];
				array[i + 1] = t;
				flag = 1; //перемещения
			}
		}
		right--;
		for (int i = right; i > left; i--) {
			if (array[i - 1] > array[i]) {
				int t = array[i];
				array[i] = array[i - 1];
				array[i - 1] = t;
				flag = 1;    //перемещения
			}
		}
		left++;
	}
}

void SortInsertion(int *array, int n) { //сортировка массива прямой вставкой
	int newElement, location;
	for (int i = 1; i < n; i++) {
		newElement = array[i];
		location = i - 1;
		while (location >= 0 && array[location] > newElement) {
			array[location + 1] = array[location];
			location = location - 1;
		}
		array[location + 1] = newElement;
	}
}

void Clear1(UI *bm, int m, int n)
{
	UI mask = 1; int i, j, k;
	for (i = 0; i < n; i++) {
		for (UI mask1, j = 0, k = 0; k != 1; j++)
			if (bm[j] & mask) {
				mask1 = ~mask;
				bm[j] &= mask1;
				k = 1;
			}
		mask <<= 1;
	}
}

