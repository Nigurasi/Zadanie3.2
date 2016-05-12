#include "gra.h"
using namespace std;

int liczba_plikow = -1;
char* nazwy_plikow[5];

void Plansza_tyt (){
	system("clear");	
	system("setterm -foreground white");
	system("clear");
	
	cout << "         ================================\n";
	cout << "         ||                             ||\n";
	cout << "         ||       Polscy logicy         ||\n";
	cout << "         ||                             ||\n";
	cout << "         ================================\n";

	cout << "\n\n  Nacisnij dowolny przycisk, aby kontynuowac...";
	getchar();
}

void Menu(){
	system("clear");	
	//system("setterm -background white -foreground black");
	//system("clear");
	char opcja;
	
	cout << "         ================================\n";
	cout << "         ||                             ||\n";
	cout << "         ||            MENU             ||\n";
	cout << "         ||                             ||\n";
	cout << "         ================================\n\n";
	
	cout << "  1 Rozpocznij gre\n";
	cout << "  2 Instrukcja\n";
	cout << "  3 O Autorze\n";
	cout << "  4 Wylacz gre\n";
	
	cout <<"\n  Wybierz interesujaca cie opcje, a nastepnie kliknij Enter: ";
	cin >> opcja;
	switch (opcja){
		case '1': Start(); break;
		case '2': Instrukcja(); break;
		case '3': Autor(); break;
		case '4': Wylacz_gre(); break;
		default: Zla_opcja(); break;
	}
	
}

void Start(){
	system("clear");
	string opcja;

	cout << "         ================================\n";
	cout << "         ||                             ||\n";
	cout << "         ||        CO SIE DZIEJE        ||\n";
	cout << "         ||                             ||\n";
	cout << "         ================================\n\n";

	cout << "  Od dawna na calym swiecie pojawialy sie tajemnicze\n";
	cout << "  dziury. Wygladaly jak zwykle pekniecia, ubytki, czy\n";
	cout << "  rozerwania. Z jednym wyjatkiem - nie mialy dna, a osoby,\n";
	cout << "  ktore ich dotykaly, znikaly. Pozniej pojawialy sie one\n";
	cout << "  w innym miejscu lub znajdowano o nich informacje w starych\n";
	cout << "  kronikach, dziennikach badz innych ksiegach. Dlatego tez\n";
	cout << "  naukowcy twierdzili, ze sa to dziury czasoprzestrzenne.\n";
	cout << "  Jednak nikt nie potrafil stwierdzic, dlaczego zaden z zaginionych\n";
	cout << "  nie wraca. Niestety jestes jednym z tych nieszczesnikow.\n";
	cout << "  Nie dotknales dziury, ale wpadles w nia, od razu gdy sie \n";
	cout << "  zmaterializowala. \n";  

	cout << "\n\n  Nacisnij dowolny znak, a nastepnie Enter, aby przejsc dalej...";
	cin >> opcja;

	system("clear");

	cout << "         ================================\n";
	cout << "         ||                             ||\n";
	cout << "         ||        CO SIE DZIEJE        ||\n";
	cout << "         ||                             ||\n";
	cout << "         ================================\n\n";

	cout << "  Pojawiles sie w ciemnym, malym pokoju. Jedna ze scian zostala\n";
	cout << "  zastapiona przez ogromne okno, przez ktore mozna bylo zauwazyc\n";
	cout << "  pomieszczenie przypominajace sale treningowa. Na podlodze lezaly maty.\n";
	cout << "  Na scianach wisialy roznego rodzaju bronie, a pod sciana stalo 5\n";
	cout << "  osob. Nie zdazyles im sie przyjrzec, bo z cienia wyszedl mezczyzna.\n";
	cout << "  Mial na sobie ciemny garnitur, lecz jego twarz pozostawala calkowicie\n";
	cout << "  zaslonieta. Powiedzial, ze jako jedyny masz szanse na powrot do swojego\n";
	cout << "  starego zycia. Wystarczy, ze zagrasz z nim w gre. Jesli wygrasz, wrocisz\n";
	cout << "  tak, skad przyszedles. Jesli przegrasz, zostaniesz na zawsze tu, gdzie\n";
	cout << "  sie pojawiles. Oczywiscie, ze przystales na jego propozycje. \n";
	cout << "  Dopiero teraz wyjawil ci on, ze osoby stojace pod sciana to ludzie,\n";
	cout << "  ktorzy przyczynili sie do rozwoju swiata, czyli naukowcy, filozofowie,\n";
	cout << "  wojownicy i odkrywcy. Razem z tajemniczym zrobisz z nich gladiatorow\n";
	cout << "  walczacych za ciebie. Kazdy z nich ma zalety i wady. Kazdy ma stuprocentowe\n";
	cout << "  szanse na wygranie z niektorymi, a z innymi na pewno przegra. \n";
	cout << "  Twoim zadaniem jest postawic na zwyciezce.\n";

	cout << "\n\n  Nacisnij dowolny znak, a nastepnie Enter, aby przejsc dalej...";
	cin >> opcja;

	Wybierz_Tryb();
}

void Wybierz_Tryb(){
	system("clear");
	string opcja;
	int tryb = -1;	//nr trybu to nr miejsca nazwy pliku w tablicy
	int dlugosci[5];
		
	for (int i = 0; i < 5; i++) dlugosci[i] = 0;

	cout << "         ================================\n";
	cout << "         ||                             ||\n";
	cout << "         ||       WYBIERZ TRYB GRY      ||\n";
	cout << "         ||                             ||\n";
	cout << "         ================================\n\n";

	cout << "  Aby wiedziec, jak wygrac te rozgrywke, musisz znac definicje operacji\n";
	cout << "  logicznych. (Dokladna instrukcja znajduje sie w menu glownym.)\n";

	for (int i = 0; i < liczba_plikow; i++)
		dlugosci[i] = strlen(nazwy_plikow[i]);

	if(liczba_plikow == 1){
		cout << "  Nie mozesz wybrac zadnego trybu,\n  bo podales tylko jeden plik.\n";
		tryb = 0;	
	}

	else{
		cout << "\n  Wybierz Tryb gry(to ma byc liczba!!!):\n";
		for (int i = 0; i < 5 && nazwy_plikow[i] != 0; i++){
			cout << "    " << i << " ";
			for (int j = 0; j < dlugosci[i]-4; j++)
				cout << nazwy_plikow[i][j];
			cout << "\n";
		}
			//scanf("%d", tryb);
			if (scanf("%d", &tryb) == EOF || tryb < 0 || tryb >= liczba_plikow) {
				cout << "\n\n  Wybrales zla liczbe.\n  Dopoki nie wybierzesz wlasciwej liczby, nie bedziesz\n  mogl kontynuowac.";
				cout << "\n\n  Nacisnij dowolny znak, a nastepnie Enter, aby kontynuowac...";
				cin >> opcja;
				Wybierz_Tryb();
			}
	}
	
	FILE* definicja_plik;
	char pierwsza_gra, druga_gra, wynik;	//a i b to wspolrzedne gdzie zapiszemy wynik
	char definicja[4][4];	
	int a, b;

	definicja_plik = fopen( nazwy_plikow[tryb], "r");

	if( definicja_plik == NULL ){
		cout << "\n\n  Nastapil blad. Prawdopodobnie podany plik \n  nie istnieje, napraw to lub wybierz inny tryb.";
		cout << "\n\n  Nacisnij dowolny znak, a nastepnie Enter, aby kontynuowac...";
		cin >> opcja;
		Menu();	
	}
	else{		
		if(!strcmp("not.txt", nazwy_plikow[tryb])){	//dla not jest tylko jedna gra
			for (int i = 0; i < 4; i++){
				for (int j = 0; j < 4; j++)
				definicja[i][j] = '/';
			}			

			for (int i = 0; i < 3; i++){
				if(fscanf (definicja_plik, "%c %c\n", &(pierwsza_gra), &(wynik)) != EOF){
					definicja [0][i] = pierwsza_gra;
					definicja [1][i] = wynik;
				}
			}
			/*for(int i = 0; i < 4; i++){
				for (int j = 0; j < 4; j++){
					cout << definicja[i][j] << " "; 
				}
				cout << "\n";
			}*/			
			
		}
		else{
			
			definicja[0][0] = '/';
			definicja[0][1] = '1';	//tablica definicji - w pierwszym wierszu pierwsza gra
			definicja[0][2] = '0';	//w pierwszej kolumnie druga gra. Na przecieciu wynik.
			definicja[0][3] = 'X';
			definicja[1][0] = '1';
			definicja[2][0] = '0';
			definicja[3][0] = 'X';

			for(int i = 1; i <= 9; i++){
				if(fscanf (definicja_plik, "%c %c %c\n", &(pierwsza_gra), &(druga_gra), &(wynik)) != EOF){
				for (int j = 1; j <= 3; j++){
					if (definicja[0][j] == pierwsza_gra) b = j;
					if (definicja[j][0] == druga_gra) a = j;
				} 
				definicja [a][b] = wynik;
				}
			}
			/*cout << "\n";
			for(int i = 0; i < 4; i++){
				for (int j = 0; j < 4; j++){
					cout << definicja[i][j] << " "; 
				}
				cout << "\n";
			}*/
		}	
	}

	cout << "\n\n  Nacisnij dowolny znak, a nastepnie Enter, aby kontynuowac...";
	cin >> opcja;

	Gra1(nazwy_plikow[tryb], definicja);
}

int main (int argc, char* argv[]){
	system("clear");
	for (int i = 0; i < 5; i++) nazwy_plikow[i] = 0;
	
	if (argc < 2 || argc > 6){

		cout << "\n\n    UWAGA! \n  Linia wywolania powinna zawierac nazwy plikow\n  tekstowych. Ich liczba nie powinna przekraczac 5. \n  Na przyklad tak: \n  ./mygame not.txt and.txt or.txt impl.txt\n  Zastosuj sie do tego.";
		cout << "\n\n\n  Nacisnij dowolny przycisk, aby kontynuowac...";
		getchar();
		return 0;
	}
	liczba_plikow = argc - 1;
	
	for (int i = 1; i <= liczba_plikow; i++){
		nazwy_plikow[i-1] = argv[i];
	}

	
	Plansza_tyt();

	Menu();

system("clear");

return 0;
}
