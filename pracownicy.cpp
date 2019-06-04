#include "pch.h"
#include <stdio.h>

struct Pracownik
{
	char Nazwisko[30];
	double Stawka;
	int LiczbaGodzin;
};

char vchar()
{
	char cc;
	while ((cc = getchar()) <= ' ');
	return cc;
}

void wczytanie_danych(Pracownik tab_pracownikow[], int &ilosc)
{
	FILE* odczyt;
	fopen_s(&odczyt, "Spis.txt", "r");
	fscanf_s(odczyt, "%d", &ilosc);
	if (ilosc > 50)
	{
		ilosc = 50;
	}
	// printf("%d", ilosc);
	for (int i = 0; i < ilosc; i++)
	{
		fscanf_s(odczyt, "%s", tab_pracownikow[i].Nazwisko, 29);
		fscanf_s(odczyt, "%lf", &tab_pracownikow[i].Stawka);
		fscanf_s(odczyt, "%d", &tab_pracownikow[i].LiczbaGodzin);
	}
	fclose(odczyt);
}

void wprowadzenie(Pracownik tab_pracownikow[], int &ilosc)
{
	if (ilosc == 50)
	{
		printf("W tablicy juz znajduje sie maksymalna ilosc pracownikow.");
		return;
	}
	printf("Podaj nazwiko nowego pracownika: ");
	scanf_s("%s", &tab_pracownikow[ilosc].Nazwisko, 29);
	printf("Podaj stawke: ");
	scanf_s("%lf", &tab_pracownikow[ilosc].Stawka);
	printf("Podaj liczbe godzin: ");
	scanf_s("%d", &tab_pracownikow[ilosc].LiczbaGodzin);
	ilosc++;
}

void wyswietlenie(Pracownik tab_pracownikow[], int &ilosc)
{
	for (int i = 0; i < ilosc; i++)
	{
		printf("Nazwisko: %s\tStawka: %lf\tLiczba godzin: %d\n", tab_pracownikow[i].Nazwisko, tab_pracownikow[i].Stawka, tab_pracownikow[i].LiczbaGodzin);
	}
}

void zapisanie_danych(Pracownik tab_pracownikow[], int &ilosc)
{
	FILE* zapis;
	fopen_s(&zapis, "Spis.txt", "w");
	fprintf_s(zapis, "%d\n", ilosc);
	for (int i = 0; i < ilosc; i++)
	{
		fprintf_s(zapis, "%s %lf %d\n", tab_pracownikow[i].Nazwisko, tab_pracownikow[i].Stawka, tab_pracownikow[i].LiczbaGodzin);
	}
	fclose(zapis);
}

void wyplata(Pracownik tab_pracownikow[], int &ilosc)
{
	FILE *zapis;
	fopen_s(&zapis, "ListaPlac.txt", "w");
	double netto;
	double podatek;
	for (int i = 0; i < ilosc; i++)
	{
		podatek = double(tab_pracownikow[i].LiczbaGodzin) * tab_pracownikow[i].Stawka * 0.19;
		netto = double(tab_pracownikow[i].LiczbaGodzin) * tab_pracownikow[i].Stawka - podatek;
		fprintf_s(zapis, "Nazwisko: %s\nNetto: %lf\nPodatek: %lf\n", tab_pracownikow[i].Nazwisko, netto, podatek);
	}
	fclose(zapis);
}

int main()
{
	Pracownik tab_pracownikow[50];
	int liczba_pracownikow = 0;
	void(*TF[])(Pracownik*, int&) = { wczytanie_danych, wprowadzenie, wyswietlenie, zapisanie_danych, wyplata };
	char opcja = ' ';
	bool wyjscie = false;
	while (!wyjscie)
	{
		printf("Wybierz opcje:\n");
		printf("A-wczytanie danych, B-wprowadzenie nowego pracownika, C-wyswietlenie pracownikow\n");
		printf("D-zapisanie danych, E-zapisanie wyplat, G-wyjscie: ");
		opcja = vchar();
		opcja &= 0x5F;
		printf("\n");
		if (opcja >= 'A' && opcja <= 'E')
		{
			TF[opcja-'A'](tab_pracownikow, liczba_pracownikow);
		}
		else if (opcja == 'G')
		{
			wyjscie = true;
		}
	}
	return 0;
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
