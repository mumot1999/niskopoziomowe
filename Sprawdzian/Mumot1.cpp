// zad2.cpp : Ten plik zawiera funkcjê „main”. W nim rozpoczyna siê i koñczy wykonywanie programu.
//

#include <iostream>
#include "stdafx.h"

void readFromFile();

struct Pracownik {
	char nazwisko[50];
	double pensja;
	double premia;
	double netto;
	double podatek;
};

Pracownik data[200];
int dataCount = 0;

void calculate_netto_and_podatek(Pracownik* p) {
	double podatek = 0.19 * (p->pensja + p->premia);
	double netto = p->pensja + p->premia - podatek;
	p->podatek = podatek;
	p->netto = netto;
}

char vchar()
{
	char cc;
	while ((cc = getchar()) <= ' ');
	return cc;
}

void show() {
	double sum_netto = 0;
	double sum_podatek = 0;

	for (int i = 0; i < dataCount; i++) {
		Pracownik e = data[i];
		sum_netto += e.netto;
		sum_podatek += e.podatek;
	}
	printf_s("suma podatków: %f, suma netto: %f", sum_podatek, sum_netto);
}

void resetDatabase() {
	for (int i = 0; i < 200; i++) {
		data[i] = Pracownik();
	}
}

void readFromFile() {
	resetDatabase();
	FILE *pFile;
	fopen_s(&pFile, "Dane.txt", "r"); // read mode
	int _count;
	fscanf_s(pFile, "%d", &_count);
	dataCount = _count;
	for (int i = 0; i < _count; i++) {
		fscanf_s(pFile, "%s", data[i].nazwisko, 50);
		fscanf_s(pFile, "%lf", &(data[i].pensja));
		fscanf_s(pFile, "%lf", &(data[i].premia));
	}
}

void writeToFile() {
	FILE *pFile;
	fopen_s(&pFile, "Wyplata.txt", "wt"); // read mode
	fprintf_s(pFile, "%d ", dataCount);

	for (int i = 0; i < dataCount; i++) {
		fprintf_s(pFile, "%s ", data[i].nazwisko);
		fprintf_s(pFile, "%lf ", data[i].netto);
		fprintf_s(pFile, "%lf ", data[i].podatek);
	}
}

typedef void(*VoidFunction) ();

int main() {
	readFromFile();
	for (int i = 0; i < dataCount; i++)
	{
		calculate_netto_and_podatek(&data[i]);
	}
	writeToFile();
	show();
}


