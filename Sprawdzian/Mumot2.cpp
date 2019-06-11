// Mumot2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "math.h"

double a(double n) {
	return sin(n) + 5.25;
}

double b(double n) {
	return cos(n) - 3.23;
}

double c(double n) {
	if (n == 0) {
		throw "Nie mozna przeprowadzic operacji log(0) !!!";
	}
	return log10(pow(n, 2.0) + 1.21);
}

double d(double n) {
	return n;
}

typedef double(*VoidFunction) (double);

int main()
{
	printf_s("%lf \n", c(1));

	VoidFunction functions[] = {
		a,
		b,
		c,
		d,
	};

	int W;
	printf("Ilosc wierszy: ");
	scanf_s("%d", &W);

	double** A = new double*[W];
	for (int i = 0; i < W; i++)
		A[i] = new double[2];

	for (int i = 0; i < W; i++)
		for (int j = 0; j < 2; j++)		{
			scanf_s("%lf", &A[i][j]);
		}

	double* B = new double[W];

	for (int i = 0; i < W; i++)
		for (int j = 0; j < 2; j++) {
			int n = A[i][0];

			if (n < 0 || n > 2) {
				n = 3;
			};

			B[i] = functions[n](A[i][1]);
		}
	for (int i = 0; i < W; i++)
		printf_s("%lf \n", B[i]);

    return 0;
}

