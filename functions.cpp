WSZYSTKIE MATERIAŁY ZOSTAŁY WYJĘTE ŻYWCEM Z MAINÓW PRZEMKA I BŁAŻEJA I JAKIEGOŚ RANDOMA Z WYŻSZEGO ROCZNIKA

MENU:
1. PODSTAWOWY KOD DO DZIAŁAŃ NA PLIKACH
2. MODYFIKACJA DO 1., WCZYTYWANA NAZWA PLIKU
3. DYNAMICZNA BUDOWA MACIERZY
4. FUNKCJA LICZENIA JEDYNEK BINARNYCH
5. BUDOWA STRUCTA I WCZYTYWANIE ELEMENTÓW DO TABLICY STRUKTUR
6. PRZEŁĄCZNIK DO TWORZENIA MENU
7. MENU Z WYKORZYSTANEM PRZEŁĄCZNIKA Z PUNKTU 6.
8. SELEKCJA (TUTAJ JAKBY KTOŚ MÓGŁ POWIEDZIEĆ JAKA)
9. VCHAR DO WCZYTYWANIA JEDNEJ LITERKI

----------------------------------------------------
1.TYPOWY KOD NA OPERACJE NA PLIKACH, KOPIUJ WKLEJ DO MAINA :)
----------------------------------------------------

	FILE *odczyt, *zapis;

	fopen_s(&odczyt, "odczyt.txt", "r");
	fopen_s(&zapis, "zapis.txt", "w");

	if (odczyt == NULL || zapis == NULL) {
		printf_s("Nie udalo sie otworzyc wszystkich plikow.\n");
		return 0;
	}

	while (feof(odczyt) == NULL) 
	{


	}

	printf_s("Zapisano.\n");

	fclose(odczyt);
	fclose(zapis);
	

----------------------------------------------------
2.KOD NA WCZYTYWANĄ NAZWĘ PLIKU
----------------------------------------------------

	char nazwa_in[32];
	char nazwa_out[32];

	printf("Podaj nazwe pliku wejsciowego: ");
	scanf("%s", nazwa_in, 32);
	printf("Podaj nazwe pliku wyjsciowego: ");
	scanf("%s", nazwa_out, 32);

	odczyt = fopen( nazwa_in, "r");
	zapis = fopen( nazwa_out, "w");

----------------------------------------------------
3.KOD NA DYNAMICZNA BUDOWE MACIERZY
----------------------------------------------------

	int M,N;
	printf("Ilosc kolumn: ");
	scanf_s("%d", &M);

	printf("Ilosc wierszy: ");
	scanf_s("%d", &N);

	int** tab = new int*[N];
	for (int i = 0; i < N; i++)
		tab[i] = new int[M];

----------------------------------------------------
4.SZUKANIE JEDYNEK BINARNYCH
----------------------------------------------------

int jedynek(unsigned int x) {
	int jedynek = 0;
	while (x != 0) {
		jedynek += (x & 1);
		x >>= 1;
	}
	return jedynek;
}

----------------------------------------------------
5.TYPOWY STRUCT I ZAPIS W TABLICY STRUCTÓW
----------------------------------------------------

struct pracownik 
{  
char Imie[16];  
char Nazwisko[16];  
int pesel; 
}; 
 
 
void f1(pracownik tab[100], int & index) 
{  
printf("podaj imie: ");  
scanf_s("%s", &tab[index].Imie, 16);  
printf("podaj nazwisko: ");  
scanf_s("%s", &tab[index].Nazwisko, 16);  
printf("podaj pesel: ");  
scanf_s("%lli", &tab[index].pesel);  
index++; 
}
 
----------------------------------------------------
6.PRZYKŁADOWY PRZEŁĄCZNIK A LA KNIAT
----------------------------------------------------

int (*funkcje[])(tab[10], int &) = {Funkcja1, Funkcja2, Funkcja3, Funkcja4, Funkcja5};

----------------------------------------------------
7.KOD NA MENU Z TYM WYŻEJ
----------------------------------------------------

while (!koniec) 
{   
printf("wybierz opcje:\n1-nowy \n2-wyswietl all \n3-wyswietl info\n4-zapis \n5-odczyt do pliku\n0-koniec\n");   
scanf_s("%d", &wyb); 
 
  if (0 < wyb && wyb < 6)  
Tab[wyb-1](tab, index);   
if (wyb == 0) koniec = true;   
//else printf_s("Blad"); 
 } 

----------------------------------------------------
8.SELEKCJA … (nie wiem czego xD)
----------------------------------------------------

tab[0] & 0x5F

----------------------------------------------------
9.VCHAR KNIATA XD
----------------------------------------------------

char vchar()
{
	char cc;
	while ((cc = getchar()) <= ' ');
	return cc;
}

----------------------------------------------------
