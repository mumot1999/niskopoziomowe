// zad2.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>

void readFromFile();

struct Telewizor {
	char name[50];
	int diagonal;

};

Telewizor data[200];
int tvCount = 0;
char vchar()
{
	char cc;
	while ((cc = getchar()) <= ' ');
	return cc;
}
void readFromKeyboard() {

	Telewizor tv;
	printf_s("\npodaj nazwe: ");
	scanf_s("%s", tv.name, 50);
	printf_s("podaj przekatna: ");
	scanf_s("%d", &tv.diagonal);

	data[tvCount] = tv;
	tvCount++;
}


void showTvs() {
	for (int i = 0; i < tvCount; i++) {
		Telewizor tv = data[i];
		printf_s("tv %d \n \t nazwa: \t%s \n \t cale:\t\t%d\n", i, tv.name, tv.diagonal);
	}
}

void resetDatabase() {
	for (int i = 0; i < 200; i++){
		data[i] = Telewizor();
	}

}

void readFromFile() {
	resetDatabase();
	FILE *pFile;
	fopen_s(&pFile, "dane.txt", "r"); // read mode
	int _count;
	fscanf_s(pFile, "%d", &_count);
	tvCount = _count;
	for (int i = 0; i < _count; i++){
		fscanf_s(pFile, "%s", data[i].name, 50);
		fscanf_s(pFile, "%d", &(data[i].diagonal));
	}
}

void writeToFile() {
	FILE *pFile;
	fopen_s(&pFile, "dane1.txt", "wt"); // read mode
	fprintf_s(pFile, "%d ", tvCount);

	for (int i = 0; i < tvCount; i++) {
		fprintf_s(pFile, "%s ", data[i].name);
		fprintf_s(pFile, "%d ", data[i].diagonal);
	}
}

typedef void(*VoidFunction) ();

void p
int main(){
	VoidFunction functions[] = {
		readFromKeyboard,
		readFromFile,
		showTvs,
		writeToFile,
	};
	int choose = 0;
	scanf_s(&choose);

	while(choose)
	printf_s("1. wczyt")
	getc
}



