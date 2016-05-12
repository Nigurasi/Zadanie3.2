#include "gra.h"

string symbole [5] = {"Turing", "Sokrates", "Nietzsche", "Sklodowska", "Pond"};

char rozstrzygniecie (int gracz1, int gracz2);

void Gra1 (char* nazwa_pliku, char definicja[4][4]){
	system("clear");
	string opcja;
	int liczba_gier;

	cout << "         ================================\n";
	cout << "         ||                             ||\n";
	cout << "         ||       ROZPOCZYNAMY          ||\n";
	cout << "         ||                             ||\n";
	cout << "         ================================\n\n";

	cout << "  Wybrales tryb " << nazwa_pliku << ".";

	if (!strcmp(nazwa_pliku, "not.txt")){
		 cout << "\n  Skoro wybrales tryb not.txt, to rozegrasz jedna gre. \n  Cala rozgrywke wygrasz, jesli bedziesz przestrzegac\n  regul definicji, ktora wybrales.";
	liczba_gier = 1;
	}

	else {
		cout << "\n  Skoro wybrales ten tryb, to rozegrasz dwie gry.\n  Cala rozgrywke wygrasz, jesli bedziesz przestrzegac\n  regul definicji, ktora wybrales.";
		liczba_gier = 2;
	}
	
	cout << "\n\n  Nacisnij dowolny przycisk, aby kontynuowac...";
	cin >> opcja;
	pkn(liczba_gier, definicja);
}


void pkn (int liczba_gier, char definicja[4][4]){
	system("clear");
	srand(time(NULL));
	string opcja;
	char gra [2] = { '/', '/'};
	int komputer, gracz;

	for (int i = 0; i < liczba_gier; i++){
		system("clear");

		cout << "         ================================\n";
		cout << "         ||                             ||\n";
		cout << "         ||           GRA NR "  << i+1 <<"          ||\n";
		cout << "         ||                             ||\n";
		cout << "         ================================\n\n";

		printf ("  Masz do wyboru nastepujace postacie: ");
		//for (int j = 0; j < 5; j++) cout << "\n   " << j << " " << symbole[j];
		
		cout << "\n   0 Turing: dekoduje zamiary przeciwnika i sprowadza ostrzal na wroga";
		cout << "\n   1 Sokrates: posiada na wyposazeniu zabojcza trucizne - cyjanek";
		cout << "\n   2 Nietzsche: ewoluuje w nadczlowieka";
		cout << "\n   3 Sklodowska: rzuca rozpadami promieniotworczymi";
		cout << "\n   4 Pond(pierwszy czlowiek, ktory wlecial w galaktyke Andromedy;\n wrocila ze statkiem pelnym probek i dowodow na zycie pozaziemskie): \n strzela w przeciwnika wiazka promieniowania omega, ktore rozdziela go na atomy";
		
		cout << "\n\n  Wybierz jeden z nich, wpisujac odpowiednia liczbe: ";
		//cin >> gracz;
		if (scanf("%d", &gracz) == EOF || gracz < 0 || gracz >= 5) {
			cout << "\n\n  Wybrales zla liczbe.\n  Dopoki nie wybierzesz wlasciwej liczby, bedziesz\n  przenoszony do poczatku rozgrywki.";
			cout << "\n\n  Nacisnij dowolny znak, a nastepnie Enter, aby kontynuowac...";
			cin >> opcja;
			Wybierz_Tryb();

		}

		komputer = rand()%5;
		
		cout << "\n\n  Twoj przeciwnik wybral: " << symbole[komputer];

		gra[i] = rozstrzygniecie (gracz, komputer);
		
		cout << "\n\n\n\n  Nacisnij dowolny znak, a nastepnie Enter, aby kontynuowac...";
		cin >> opcja;	
	
	}
	
	system ("clear");
	int wynik_x, wynik_y; char wynik;
	
	cout << "         ================================\n";
	cout << "         ||                             ||\n";
	cout << "         ||           WYNIKI            ||\n";
	cout << "         ||                             ||\n";
	cout << "         ================================\n\n";
	
	if (liczba_gier == 1){
		for (int i = 0; i < 3; i++){
			if(gra[0] == definicja [0][i]){
				wynik = definicja [1][i];
			}
		}
	}

	else{
		for (int i = 1; i < 4; i++){
			if (gra[0] == definicja [0][i]) wynik_y = i;
			if (gra[1] == definicja [i][0]) wynik_x = i;
		
		}
		wynik = definicja [wynik_x][wynik_y];
	
	}
	
	if (wynik == '1') cout << "  Brawo. Udalo ci sie zrozumiec, o co chodzi. Wygrales\n  te rozgrywke. Mozesz byc z siebie dumny.";
	else if (wynik == '0') cout << "  No niestety. Nie udalo sie. Szczescie cie dzis\n  zawiodlo. Mozesz zawsze sprobowac jeszcze raz.";
	else cout << "  Nie niezle. Zremisowales. Rzadko sie to zdaza, wiec w sumie tez\n  jest to jakies zwyciestwo. Ale to jednak nie to samo.";
	
	cout << "\n\n  Nacisnij dowolny znak, a nastepnie Enter, aby przejsc do Menu...";
	cin >> opcja;
	
	Menu();
	

}


char rozstrzygniecie (int gracz1, int gracz2){
	if(gracz1 == gracz2){
		cout << "\n\n  Niestety komputer zaatakowal ta sama bronia, co ty.\n  Ich wlasciwosci sie zeruje, wiec ta walka\n  pozostaje nierozstrzygnieta.";
		return 'X';
	}	
	else if(gracz1 == 0 && gracz2 == 1){ // 1 Turing i Sokrates 
		cout << "\n\n  No niestety. Sokrates przeciwnika otrul sztuczna\n  inteligencje twojego Turinga. Przegrywasz.\n  Wstydz sie.";
		return '0'; 
	}
	
	else if (gracz1 == 1 && gracz2 == 0) { // 2 Sokrates i Turing
		cout << "\n\n  No brawo. Twoj Sokrates wykorzystal swoja niewiedze\n  i przebieglosc, i otrul Turinga przeciwnika.\n  Wygrywasz! No niezle.";
		return '1';
	}
	
	else if(gracz1 == 0 && gracz2 == 2){ // 3 Turing i Nietzsche
		cout << "\n\n  No i super. Bomba Turinga przydala sie takze w tym\n  przypadku. Otoz rozszyfrowala ona tajemnice\n  nadczlowieka Nietzschego przeciwnika i obalila jego potege. Wygrales.\n  Powinienes byc z siebie dumny.";
		return '1'; 
	} 
	
	else if(gracz1 == 2 && gracz2 == 0){ // 4 Nietzsche i Turing
		cout << "\n\n  Eeee... slabo. Bomba Turinga za szybko rozszyfrowala\n  tajemnice potegi nadczlowieka. Twoj Nietzsche\n  mozliwe, ze straci wiare w swoja filozofie. Moze miec to wplyw na cala\n  historie. Totalna przegrana.";
		return '0'; 
	} 
	
	else if(gracz1 == 0 && gracz2 == 3){ // 5 Turing i Sklodowska 
		cout << "\n\n  Pierwsze A.I. ktore przeszlo test Turinga obronilo\n  go wlasna piersia przed rzuconym rozpadem, a nastepnie\n  z pelna sila zaszarzowalo na Sklodowska. Wiedziales,\n  na kogo stawiac! Dobrze.";
		return '1'; 
	} 
	
	else if(gracz1 == 3 && gracz2 == 0){ // 6 Sklodowska i Turing
		cout << "\n\n  I tym razem przewaga historii wygrala. Turing\n  dokladnie wiedzial, na co moze postawic Sklodowska.\n   Z ogromna dokladnoscia obliczyl, jak ochronic sie przed\n  rozpadem i rozgromic Sklodowska. Nie tym razem.";
		return '0'; 
	}

	else if(gracz1 == 0 && gracz2 == 4){ // 7 Turing i Pond
		cout << "\n\n  Niestety promieniowanie omega nie bylo znane za czasow\n  Turinga, wiec nie byl on przygotowany na te ewentualnosc.\n  Jego bomba zostala rozdzielona na atomy, a ty\n  przegrales z kretesem. Ups.";
		return '0'; 
	} 
	
	else if(gracz1 == 4 && gracz2 == 0){ // 8 Pond i Turing
		cout << "\n\n  Wiedziales na kogo postawic. Dziewczyna z bronia zawsze\n  sobie poradzi. Bomba Turinga zniknela raz na\n  zawsze rozdzielona na atomy. Tym razem wygrales.";
		return '1'; 
	} 

	else if(gracz1 == 1 && gracz2 == 2){ // 9 Sokrates i Nietzsche
		cout << "\n\n  Nietzsche ubezpieczyl sie na te ewentualnosc. Jego\n  nadczlowiek jest odporny na wszelkie trucizny odkryte\n  lub wytworzone przed jego stworzeniem, wiec\n  bron Sokratesa byla bezuzyteczna. Przynajmniej Sokrates dowiedzial\n  sie czegos ciekawego. Tym tez.\n  Przegrales.";
		return '0'; 
	} 

	else if(gracz1 == 2 && gracz2 == 1){ // 10 Nietzsche i Sokrates
		cout << "\n\n  Dokladnie wiedziales, ze nadczlowiek jest odporny na\n  wszelkie trucizny. Nawet sie nie wzdrygnal, gdy polykal\n  cyjanek. Brawo. Udalo ci sie.";
		return '1'; 
	} 

	else if(gracz1 == 1 && gracz2 == 3){ // 11 Sokrates i Sklodowska
		cout << "\n\n  Motyla noga. Cyjanek zareagowal z rozpadem. Znowu\n  Sokrates umocnil sie w przekonaniu, ze nic nie wie.\n  Zamiast wygrac, jedynie wzmocnil pierwiastki Sklodowskiej.\n  Nie tym razem.";
		return '0'; 
	} 

	else if(gracz1 == 3 && gracz2 == 1){ // 12 Sklodowska i Sokrates
		cout << "\n\n  Brawo. Sklodowska rzucila w Sokratesa rozpadami w tym\n  samym czasie, gdy on zaatakowal cyjankiem. Nie wiadomo\n  do konca, co sie stalo, ale pol sekundy pozniej\n  Sokrates lezal na matach. Liczy sie efekt.";
		return '1'; 
	} 

	else if(gracz1 == 1 && gracz2 == 4){ // 13 Sokrates i Pond
		cout << "\n\n  Pond nie zauwazyla, ze Sokrates przed walka dosypal\n  jej do wody cyjanek. Przebiegla z niego bestia. Uczciwie\n  czy nie, walka wygrana.";
		return '1'; 
	} 

	else if(gracz1 == 4 && gracz2 == 1){ // 14 Pond i Sokrates
		cout << "\n\n  Szkoda, ze Pond nie nauczyla sie patrzyc, co pije.\n  Cyjanek byl praktycznie nie zauwazalny w wodzie. \n  Dziewczyna prawie od razu padla na maty. Przykro mi.";
		return '0'; 
	} 

	else if(gracz1 == 2 && gracz2 == 3){ // 15 Nietzsche i Sklodowska
		cout << "\n\n  Nadczlowiek jest ponad natura. Tak wiec jego nie\n  obchodza jakies zabawy z pierwiastkami w laboratorium.\n  Szczegolnie z tymi radioaktywnymi. Rozgniotl wszystkie rozpady\n  swoimi piesciami i wrocil na swoje miejsce. Brawo za wybor.";
		return '1'; 
	} 

	else if(gracz1 == 3 && gracz2 == 2){ // 16 Sklodowska i Nietzsche
		cout << "\n\n  Sklodowska prawie sie rozplakala, gdy owoce jej pracy\n  byly niszczone przez Nietzsche'go. Ten olbrzym nawet\n  nie zareagowal na ich wlasciwosci. Niestety, totalna porazka.";
		return '0'; 
	} 

	else if(gracz1 == 2 && gracz2 == 4){ // 17 Nietzsche i Pond
		cout << "\n\n  Jeszcze niedawno nadczlowiek przygotowywal sie do\n  ataku, a teraz jego atomy przemieszczaja sie po calym\n  pomieszczeniu. Juz raczej nie zaatakuje. Oj.";
		return '0'; 
	} 

	else if(gracz1 == 4 && gracz2 == 2){ // 18 Pond i Nietzsche
		cout << "\n\n  Nawet nieograniczona moc i sila nie przezwyciezy najprostszego\n  rozdrabniacza. Od teraz nadczlowiek i jego potega\n  wdychana jest przez wszystkich we Wszechswiecie. Zwyciezyles.";
		return '1'; 
	} 

	else if(gracz1 == 3 && gracz2 == 4){ // 19 Sklodowska i Pond
		cout << "\n\n  Rozpady mialy niewielkie rozmiary, wiec nic dziwnego,\n  ze jeden z nich utknal w broni Pond, uniemozliwiajac\n  jej wystrzal i wyzwalajac swoja energie ze zdwojona moca. Tym razem udalo ci sie wygrac.";
		return '1'; 
	} 

	else /*(gracz1 == 4 && gracz2 == 3)*/{ // 20 Pond i Sklodowska
		cout << "\n\n  Bron Pond stala sie bezuzyteczna w momencie, gdy jeden\n  z rozpadow utknal w lufie jej broni. Probowala\n  siegnac po jedna z broni wiszacych na scianie, ale\n  opary promieniotworcze ja dopadly. Przykro mi.";
		return '0'; 
	} 


}
