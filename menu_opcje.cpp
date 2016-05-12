#include "gra.h"

void Instrukcja(){
	system("clear");
	char opcja;	

	cout << "         ================================\n";
	cout << "         ||                             ||\n";
	cout << "         ||        INSTRUKCJA           ||\n";
	cout << "         ||                             ||\n";
	cout << "         ================================\n\n";
	
	cout << "Co to jest?\n  Gra pt.: \"GRA\" jest to lekko rozbudowana wersja\n";
	cout << "  gry w papier, kamien, nozyce. Opiera sie ona o \n";
	cout << "  logike wielowartosciowa, a dokladnie o definicje\n";
	cout << "  operatorow logicznych.\nCo wpisujemy dodatkowo?\n";
	cout << "  Gracz podczas wlaczania gry wpisuje jako parametry\n";
	cout << "  wywolania nazwy plikow tekstowych, w ktorych znajduja\n";
	cout << "  sie te definicje. Maksymalnie mozna wpisac cztery \n";
	cout << "  nazwy plikow. Nazwy powinny zawierac w sobie nazwe\n";
	cout << "  operatora logicznego(w jezyku angielskim) oraz\n";
	cout << "  posiadac rozszerzenie .txt np.: not.txt. \nPo co te pliki? \n"; 
	cout << "  Kazdy plik oznacza inny tryb gry. 1 w definicji\n";
	cout << "  operatora oznacza wygrana, 0 - przegrana, a X - \n";
	cout << "  gre nierozstrzygnieta, czyli inaczej remis.\nJak wygrac gre?\n";
	cout << "  Wygranie gry jest rownoznaczne z wygraniem jednego\n";
	cout << "  trybu. Aby to osiagnac trzeba przestrzegac definicji\n";
	cout << "  operatora, ktorego wybralismy. Przykladowo, aby wygrac\n";
	cout << "  tryb koniunkcji nalezy rozegrac dwie gry i te dwie gry\n";
	cout << "  wygrac.";  

	cout << "\n\n  Nacisnij S, aby rozpoczac gre lub inny dowolny\n  znak, a nastepnie Enter, aby powrocic do menu...";
	cin >> opcja;

	switch(opcja){
		case 'S': Start(); break;
		case 's': Start(); break;
		default: Menu(); break;
	}
}

void Autor(){
	system("clear");
	char opcja;

	cout << "         ================================\n";
	cout << "         ||                             ||\n";
	cout << "         ||          O AUTORZE          ||\n";
	cout << "         ||                             ||\n";
	cout << "         ================================\n\n";

	cout << "  Imie i nazwisko: Anna Alberska";
	cout << "\n  Wersja: 0.0.11.05";

	cout << "\n\n  Nacisnij S, aby rozpoczac gre lub inny dowolny\n  znak, a nastepnie Enter, aby powrocic do menu...";

	cin >> opcja;

	switch(opcja){
		case 'S': Start(); break;
		case 's': Start(); break;
		default: Menu(); break;
	}
}

void Zla_opcja(){
	system("clear");
	char opcja;

	cout << "         ================================\n";
	cout << "         ||                             ||\n";
	cout << "         ||          ZLA OPCJA          ||\n";
	cout << "         ||                             ||\n";
	cout << "         ================================\n\n";
	
	cout << "  Wybrales zla opcje, huncwocie.\n  Masz do wyboru dwie opcje:\n";
	cout << "  1 Powrot do menu\n";
	cout << "  2 Wylacz gre\n";
	
	do{
		cin >> opcja;
		switch (opcja){
			case '1': Menu(); break;
			case '2': Wylacz_gre(); break;

		}
	}while(opcja != '1' || opcja != '2');
}

void Wylacz_gre(){
	system("clear");
	char opcja;

	cout << "         ================================\n";
	cout << "         ||                             ||\n";
	cout << "         ||          KONIEC?            ||\n";
	cout << "         ||                             ||\n";
	cout << "         ================================\n\n";
	
	cout << "  Jestes pewien, ze chcesz zakonczyc?\n";
	cout << "  T Wylacz\n";
	cout << "  N Powrot do menu\n";

	do{
		cin >> opcja;
		switch (opcja){
			case 'T': system("clear"); exit(0); break;
			case 't': system("clear"); exit(0); break;
			case 'N': Menu(); break;
			case 'n': Menu(); break;
		}
	}while(opcja != 'T' || opcja != 'N' || opcja != 't' || opcja != 'n');

}


