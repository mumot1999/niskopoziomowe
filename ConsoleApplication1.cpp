// ConsoleApplication1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#define dev 1



#include "pch.h"
#include <iostream>


int countZeros(unsigned decimal) {
	unsigned temp = decimal;
	int zeros = 0;
	while (decimal) {
		temp = decimal & 1;
		if (temp == 0) zeros++;
		decimal = decimal >> 1;
	}
	return zeros;
}

int zerosInColumn(unsigned* column, int size) {
	int zeros = 0;
	for (int i = 0; i < size; i++)
	{
		zeros += countZeros(*(column+i));
	}
	return zeros;

}

void get_column(unsigned** tab, int columns, int rows) {
	int id_column = 0;
	int n_zeros_in_column = 0;

	for (int j = 0; j < columns; j++) {
		int zeros = zerosInColumn(tab[j], rows);
		if (zeros > n_zeros_in_column) {
			id_column = j;
			n_zeros_in_column = zeros;
		}
	}

	for (int i = 0; i < rows; i++)
	{
		//tab[id_column][i]
		printf_s("%d ", tab[id_column][i]);
	}
}

void zad1()
{
	int columns;
	int rows;
    
#if 0
	unsigned column[] = { 1,2,3,4 };
	printf_s("%d", zerosInColumn(column, 4));
#endif

#if 0
	printf_s("Podaj liczbe wierszy: ");
	scanf_s("%d", &rows);
	printf_s("Podaj liczbe kolumn: ");
	scanf_s("%d", &columns);

	unsigned** tab = new unsigned *[columns];

	for (int i = 0; i < rows; ++i) {
		tab[i] = new unsigned[rows];
	}

	printf_s("Wypełnij tablice: ");

	for (int j = 0; j < columns; j++) {
		for (int i = 0; i < rows; i++) {

			scanf_s("%d", &tab[i][j]);
		}
	}
	get_column(tab, columns, rows);

#endif // 0

#if 1
	unsigned macierz[][2] = {
		{4,10},
		{1,1},
		{1,1},
		{1,100},
	};

	get_column((unsigned **)macierz, 4, 2);

#endif
}


int main() {
	zad1();
}